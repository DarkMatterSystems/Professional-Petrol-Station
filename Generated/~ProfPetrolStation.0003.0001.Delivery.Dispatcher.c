
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Delivery Dispatcher */

/* Dispatcher */

void adm_dispatcher_delivery(
    void)
{
    adm_pool_target_delivery_typ * pool_target_delivery;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_delivery");
    #endif

    pool_target_delivery = adm_find_away_target_event_delivery();

    adm_dispatch_state_action_delivery(pool_target_delivery);

    adm_dispatch_home_pool_delivery();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_delivery");
    #endif
}


/* Dispatch Home Pool */

void adm_dispatch_home_pool_delivery(
    void)
{
    adm_pool_target_delivery_typ * pool_target_delivery;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_delivery");
    #endif

    while (adm_entity_system.ent_delivery.home_pool_head != NULL) {

        pool_target_delivery = adm_find_home_target_event_delivery();

        adm_dispatch_state_action_delivery(pool_target_delivery);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_delivery");
    #endif
}


/* Find Home Target Event */

adm_pool_target_delivery_typ * adm_find_home_target_event_delivery(
    void)
{
    adm_pool_target_delivery_typ * pool_target_delivery;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_delivery");
    #endif

    pool_target_delivery = adm_entity_system.ent_delivery.home_pool_head;

    adm_entity_system.ent_delivery.home_pool_head = pool_target_delivery->next;

    if (adm_entity_system.ent_delivery.home_pool_head == NULL) {

        adm_entity_system.ent_delivery.home_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_delivery");
    #endif

    return (pool_target_delivery);
}


/* Find Away Target Event */

adm_pool_target_delivery_typ * adm_find_away_target_event_delivery(
    void)
{
    adm_pool_target_delivery_typ * pool_target_delivery;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_delivery");
    #endif

    pool_target_delivery = adm_entity_system.ent_delivery.away_pool_head;

    adm_entity_system.ent_delivery.away_pool_head = pool_target_delivery->next;

    if (adm_entity_system.ent_delivery.away_pool_head == NULL) {

        adm_entity_system.ent_delivery.away_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_delivery");
    #endif

    return (pool_target_delivery);
}


/* Dispatch State Action */

void adm_dispatch_state_action_delivery(
    adm_pool_target_delivery_typ * pool_target)
{
    adm_dst_delivery_pump_number_typ * dst_pump_number;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_delivery");
    #endif

    if (pool_target->ent_delivery != NULL) {

        adm_object_existent_delivery(
            pool_target->ent_delivery,
            pool_target->error_location.file,
            pool_target->error_location.line,
            pool_target->error_location.rank);
    }

    switch (pool_target->evente) {

        /* Creation Events */

        case ADM_EVENT_DELIVERY_CREATE_DELIVERY :

            dst_pump_number = (adm_dst_delivery_pump_number_typ*)pool_target->dataset.pump_number;

            pool_target->ent_delivery = adm_make_object_delivery(
                ADM_STATUS_DELIVERY_CREATING_DELIVERY);

            adm_sim_display_state_delivery_creating_delivery(pool_target);

            adm_state_action_delivery_creating_delivery(
                pool_target->ent_delivery,
                dst_pump_number);

            adm_deallocate_memory(pool_target->dataset.pump_number);

            adm_check_identifiers_unique_delivery(
                pool_target->ent_delivery,
                2, 30, 31);

            adm_bind_object_delivery(
                pool_target->ent_delivery,
                2, 30, 31);

        break;

        /* Dynamic Events */

        case ADM_EVENT_DELIVERY_FUEL_UNIT_DELIVERED :

            switch ((pool_target->ent_delivery)->status) {

                case ADM_STATUS_DELIVERY_CREATING_DELIVERY :

                    adm_sim_display_state_delivery_calculating_price_of_unconstrained_delivery(pool_target);

                    (pool_target->ent_delivery)->status = ADM_STATUS_DELIVERY_CALCULATING_PRICE_OF_UNCONSTRAINED_DELIVERY;

                    adm_state_action_delivery_calculating_price_of_unconstrained_delivery(
                        pool_target->ent_delivery);

                break;

                case ADM_STATUS_DELIVERY_CALCULATING_PRICE_OF_UNCONSTRAINED_DELIVERY :

                    adm_sim_display_state_delivery_calculating_price_of_unconstrained_delivery(pool_target);

                    (pool_target->ent_delivery)->status = ADM_STATUS_DELIVERY_CALCULATING_PRICE_OF_UNCONSTRAINED_DELIVERY;

                    adm_state_action_delivery_calculating_price_of_unconstrained_delivery(
                        pool_target->ent_delivery);

                break;

                case ADM_STATUS_DELIVERY_DELIVERY_COMPLETE_STATE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Delivery",
                        (pool_target->ent_delivery)->identity,
                        "Event:Fuel_unit_delivered",
                        "State:Delivery_Complete_State");

                break;

                case ADM_STATUS_DELIVERY_DELIVERY_CANCELLED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Delivery",
                        (pool_target->ent_delivery)->identity,
                        "Event:Fuel_unit_delivered",
                        "State:Delivery_Cancelled");

                break;

                case ADM_STATUS_DELIVERY_DELIVERY_VANISHES :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Delivery",
                        (pool_target->ent_delivery)->identity,
                        "Event:Fuel_unit_delivered",
                        "State:Delivery_Vanishes");

                break;
            }

        break;

        case ADM_EVENT_DELIVERY_DELIVERY_COMPLETE :

            switch ((pool_target->ent_delivery)->status) {

                case ADM_STATUS_DELIVERY_CREATING_DELIVERY :

                    adm_sim_display_state_delivery_delivery_cancelled(pool_target);

                    (pool_target->ent_delivery)->status = ADM_STATUS_DELIVERY_DELIVERY_CANCELLED;

                    adm_state_action_delivery_delivery_cancelled(
                        pool_target->ent_delivery);

                break;

                case ADM_STATUS_DELIVERY_CALCULATING_PRICE_OF_UNCONSTRAINED_DELIVERY :

                    adm_sim_display_state_delivery_delivery_complete_state(pool_target);

                    (pool_target->ent_delivery)->status = ADM_STATUS_DELIVERY_DELIVERY_COMPLETE_STATE;

                    adm_state_action_delivery_delivery_complete_state(
                        pool_target->ent_delivery);

                break;

                case ADM_STATUS_DELIVERY_DELIVERY_COMPLETE_STATE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Delivery",
                        (pool_target->ent_delivery)->identity,
                        "Event:Delivery_complete",
                        "State:Delivery_Complete_State");

                break;

                case ADM_STATUS_DELIVERY_DELIVERY_CANCELLED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Delivery",
                        (pool_target->ent_delivery)->identity,
                        "Event:Delivery_complete",
                        "State:Delivery_Cancelled");

                break;

                case ADM_STATUS_DELIVERY_DELIVERY_VANISHES :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Delivery",
                        (pool_target->ent_delivery)->identity,
                        "Event:Delivery_complete",
                        "State:Delivery_Vanishes");

                break;
            }

        break;

        /* Deletion Events */

        case ADM_EVENT_DELIVERY_DELETE_DELIVERY :

            switch ((pool_target->ent_delivery)->status) {

                case ADM_STATUS_DELIVERY_DELIVERY_COMPLETE_STATE :

                    adm_sim_display_state_delivery_delivery_vanishes(pool_target);

                    adm_state_action_delivery_delivery_vanishes(
                        pool_target->ent_delivery);

                    adm_kill_object_delivery(
                        NULL,
                        pool_target->ent_delivery,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank);

                break;

                case ADM_STATUS_DELIVERY_DELIVERY_CANCELLED :

                    adm_sim_display_state_delivery_delivery_vanishes(pool_target);

                    adm_state_action_delivery_delivery_vanishes(
                        pool_target->ent_delivery);

                    adm_kill_object_delivery(
                        NULL,
                        pool_target->ent_delivery,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank);

                break;

                case ADM_STATUS_DELIVERY_DELIVERY_VANISHES :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Delivery",
                        (pool_target->ent_delivery)->identity,
                        "Event:Delete_delivery",
                        "State:Delivery_Vanishes");

                break;
            }

        break;
    }

    adm_deallocate_memory(pool_target);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_delivery");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */