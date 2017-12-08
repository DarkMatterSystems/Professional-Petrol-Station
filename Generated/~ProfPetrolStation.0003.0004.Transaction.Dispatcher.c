
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Transaction Dispatcher */

/* Dispatcher */

void adm_dispatcher_transaction(
    void)
{
    adm_pool_target_transaction_typ * pool_target_transaction;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_transaction");
    #endif

    pool_target_transaction = adm_find_away_target_event_transaction();

    adm_dispatch_state_action_transaction(pool_target_transaction);

    adm_dispatch_home_pool_transaction();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_transaction");
    #endif
}


/* Dispatch Home Pool */

void adm_dispatch_home_pool_transaction(
    void)
{
    adm_pool_target_transaction_typ * pool_target_transaction;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_transaction");
    #endif

    while (adm_entity_system.ent_transaction.home_pool_head != NULL) {

        pool_target_transaction = adm_find_home_target_event_transaction();

        adm_dispatch_state_action_transaction(pool_target_transaction);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_transaction");
    #endif
}


/* Find Home Target Event */

adm_pool_target_transaction_typ * adm_find_home_target_event_transaction(
    void)
{
    adm_pool_target_transaction_typ * pool_target_transaction;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_transaction");
    #endif

    pool_target_transaction = adm_entity_system.ent_transaction.home_pool_head;

    adm_entity_system.ent_transaction.home_pool_head = pool_target_transaction->next;

    if (adm_entity_system.ent_transaction.home_pool_head == NULL) {

        adm_entity_system.ent_transaction.home_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_transaction");
    #endif

    return (pool_target_transaction);
}


/* Find Away Target Event */

adm_pool_target_transaction_typ * adm_find_away_target_event_transaction(
    void)
{
    adm_pool_target_transaction_typ * pool_target_transaction;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_transaction");
    #endif

    pool_target_transaction = adm_entity_system.ent_transaction.away_pool_head;

    adm_entity_system.ent_transaction.away_pool_head = pool_target_transaction->next;

    if (adm_entity_system.ent_transaction.away_pool_head == NULL) {

        adm_entity_system.ent_transaction.away_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_transaction");
    #endif

    return (pool_target_transaction);
}


/* Dispatch State Action */

void adm_dispatch_state_action_transaction(
    adm_pool_target_transaction_typ * pool_target)
{
    adm_dst_transaction_creation_data_typ * dst_creation_data;
    adm_dst_transaction_customer_details_typ * dst_customer_details;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_transaction");
    #endif

    if (pool_target->ent_transaction != NULL) {

        adm_object_existent_transaction(
            pool_target->ent_transaction,
            pool_target->error_location.file,
            pool_target->error_location.line,
            pool_target->error_location.rank);
    }

    switch (pool_target->evente) {

        /* Creation Events */

        case ADM_EVENT_TRANSACTION_CREATE_TRANSACTION :

            dst_creation_data = (adm_dst_transaction_creation_data_typ*)pool_target->dataset.creation_data;

            pool_target->ent_transaction = adm_make_object_transaction(
                ADM_STATUS_TRANSACTION_CREATING_PENDING_TRANSACTION);

            adm_sim_display_state_transaction_creating_pending_transaction(pool_target);

            adm_state_action_transaction_creating_pending_transaction(
                pool_target->ent_transaction,
                dst_creation_data);

            adm_deallocate_memory(pool_target->dataset.creation_data);

            adm_check_identifiers_unique_transaction(
                pool_target->ent_transaction,
                5, 37, 31);

            adm_bind_object_transaction(
                pool_target->ent_transaction,
                5, 37, 31);

        break;

        /* Dynamic Events */

        case ADM_EVENT_TRANSACTION_PAYMENT_RECEIVED :

            switch ((pool_target->ent_transaction)->status) {

                case ADM_STATUS_TRANSACTION_CREATING_PENDING_TRANSACTION :

                    adm_sim_display_state_transaction_paid_state(pool_target);

                    (pool_target->ent_transaction)->status = ADM_STATUS_TRANSACTION_PAID_STATE;

                    adm_state_action_transaction_paid_state(
                        pool_target->ent_transaction);

                break;

                case ADM_STATUS_TRANSACTION_PAID_STATE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Transaction",
                        (pool_target->ent_transaction)->identity,
                        "Event:Payment_received",
                        "State:Paid_State");

                break;

                case ADM_STATUS_TRANSACTION_EVADED_STATE :

                    adm_sim_display_state_transaction_paid_state(pool_target);

                    (pool_target->ent_transaction)->status = ADM_STATUS_TRANSACTION_PAID_STATE;

                    adm_state_action_transaction_paid_state(
                        pool_target->ent_transaction);

                break;

                case ADM_STATUS_TRANSACTION_TRANSACTION_VANISHES :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Transaction",
                        (pool_target->ent_transaction)->identity,
                        "Event:Payment_received",
                        "State:Transaction_Vanishes");

                break;
            }

        break;

        case ADM_EVENT_TRANSACTION_CUSTOMER_ABSCONDS :

            switch ((pool_target->ent_transaction)->status) {

                case ADM_STATUS_TRANSACTION_CREATING_PENDING_TRANSACTION :

                    dst_customer_details = (adm_dst_transaction_customer_details_typ*)pool_target->dataset.customer_details;

                    adm_sim_display_state_transaction_evaded_state(pool_target);

                    (pool_target->ent_transaction)->status = ADM_STATUS_TRANSACTION_EVADED_STATE;

                    adm_state_action_transaction_evaded_state(
                        pool_target->ent_transaction,
                        dst_customer_details);

                    adm_deallocate_memory(dst_customer_details->customer_details);

                    adm_deallocate_memory(pool_target->dataset.customer_details);

                break;

                case ADM_STATUS_TRANSACTION_PAID_STATE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Transaction",
                        (pool_target->ent_transaction)->identity,
                        "Event:Customer_absconds",
                        "State:Paid_State");

                break;

                case ADM_STATUS_TRANSACTION_TRANSACTION_VANISHES :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Transaction",
                        (pool_target->ent_transaction)->identity,
                        "Event:Customer_absconds",
                        "State:Transaction_Vanishes");

                break;
            }

        break;

        /* Deletion Events */

        case ADM_EVENT_TRANSACTION_CLOSE_TRANSACTION :

            switch ((pool_target->ent_transaction)->status) {

                case ADM_STATUS_TRANSACTION_CREATING_PENDING_TRANSACTION :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Transaction",
                        (pool_target->ent_transaction)->identity,
                        "Event:Close_transaction",
                        "State:Creating_Pending_Transaction");

                break;

                case ADM_STATUS_TRANSACTION_PAID_STATE :

                    adm_sim_display_state_transaction_transaction_vanishes(pool_target);

                    adm_state_action_transaction_transaction_vanishes(
                        pool_target->ent_transaction);

                    adm_kill_object_transaction(
                        NULL,
                        pool_target->ent_transaction,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank);

                break;

                case ADM_STATUS_TRANSACTION_EVADED_STATE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Transaction",
                        (pool_target->ent_transaction)->identity,
                        "Event:Close_transaction",
                        "State:Evaded_State");

                break;

                case ADM_STATUS_TRANSACTION_TRANSACTION_VANISHES :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Transaction",
                        (pool_target->ent_transaction)->identity,
                        "Event:Close_transaction",
                        "State:Transaction_Vanishes");

                break;
            }

        break;
    }

    adm_deallocate_memory(pool_target);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_transaction");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */