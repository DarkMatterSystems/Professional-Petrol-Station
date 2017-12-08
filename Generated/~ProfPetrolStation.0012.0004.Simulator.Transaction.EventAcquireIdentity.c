
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Simulator Transaction Acquire Identity Event */

void adm_sim_acquire_identity_event_transaction_payment_received(
    void)
{
    adm_ent_transaction_typ * ent_transaction;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_transaction_payment_received");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_transaction = adm_entity_system.ent_transaction.live_list_head;

    while (
        entity_not_found &&
        ent_transaction != NULL) {

        if (ent_transaction->identity == identity) {

            adm_send_event_transaction_payment_received(
                NULL,
                ent_transaction,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_transaction = ent_transaction->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_transaction_payment_received");
    #endif
}

void adm_sim_acquire_identity_event_transaction_customer_absconds(
    void)
{
    adm_ent_transaction_typ * ent_transaction;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;
    adm_base_string_typ evd_nme_customer_details [ADM_TYPE_SIZE_TEXT+1];

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_transaction_customer_absconds");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Fetch Event Data */

    adm_sim_str_fetch(
        evd_nme_customer_details,
        ADM_TYPE_SIZE_TEXT+1);

    /* Check Event Data Type Ranges */

    /* Generate Event */

    entity_not_found = TRUE;

    ent_transaction = adm_entity_system.ent_transaction.live_list_head;

    while (
        entity_not_found &&
        ent_transaction != NULL) {

        if (ent_transaction->identity == identity) {

            adm_send_event_transaction_customer_absconds(
                NULL,
                ent_transaction,
                evd_nme_customer_details,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_transaction = ent_transaction->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_transaction_customer_absconds");
    #endif
}

void adm_sim_acquire_identity_event_transaction_create_transaction(
    void)
{
    adm_base_integer_typ evd_num_delivery_pump;
    adm_base_float_typ evd_num_delivery_cost;
    adm_base_integer_typ evd_num_delivery_time_hours;
    adm_base_integer_typ evd_num_delivery_time_minutes;
    adm_base_integer_typ evd_num_delivery_time_seconds;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_transaction_create_transaction");
    #endif

    /* Fetch Event Data */

    evd_num_delivery_pump = adm_sim_int_fetch();

    evd_num_delivery_cost = adm_sim_fxd_fetch();

    evd_num_delivery_time_hours = adm_sim_int_fetch();

    evd_num_delivery_time_minutes = adm_sim_int_fetch();

    evd_num_delivery_time_seconds = adm_sim_int_fetch();

    /* Check Event Data Type Ranges */

    if (
        evd_num_delivery_pump < ADM_TYPE_MINIMUM_EQUIPMENT_NUMBER ||
        evd_num_delivery_pump > ADM_TYPE_MAXIMUM_EQUIPMENT_NUMBER) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(evd_num_delivery_pump));
    }

    if (
        evd_num_delivery_cost < ADM_TYPE_MINIMUM_MONEY ||
        evd_num_delivery_cost > ADM_TYPE_MAXIMUM_MONEY) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_FIXED,
            adm_sim_lib_fxtoa(evd_num_delivery_cost));
    }

    if (
        evd_num_delivery_time_hours < ADM_TYPE_MINIMUM_TIME_HOUR ||
        evd_num_delivery_time_hours > ADM_TYPE_MAXIMUM_TIME_HOUR) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(evd_num_delivery_time_hours));
    }

    if (
        evd_num_delivery_time_minutes < ADM_TYPE_MINIMUM_TIME_MINUTE ||
        evd_num_delivery_time_minutes > ADM_TYPE_MAXIMUM_TIME_MINUTE) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(evd_num_delivery_time_minutes));
    }

    if (
        evd_num_delivery_time_seconds < ADM_TYPE_MINIMUM_TIME_SECOND ||
        evd_num_delivery_time_seconds > ADM_TYPE_MAXIMUM_TIME_SECOND) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(evd_num_delivery_time_seconds));
    }

    /* Generate Event */

    adm_send_event_transaction_create_transaction(
        evd_num_delivery_pump,
        (adm_base_fixed_typ)evd_num_delivery_cost,
        evd_num_delivery_time_hours,
        evd_num_delivery_time_minutes,
        evd_num_delivery_time_seconds,
        0, 0, 0);

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_transaction_create_transaction");
    #endif
}

void adm_sim_acquire_identity_event_transaction_close_transaction(
    void)
{
    adm_ent_transaction_typ * ent_transaction;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_transaction_close_transaction");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_transaction = adm_entity_system.ent_transaction.live_list_head;

    while (
        entity_not_found &&
        ent_transaction != NULL) {

        if (ent_transaction->identity == identity) {

            adm_send_event_transaction_close_transaction(
                NULL,
                ent_transaction,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_transaction = ent_transaction->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_transaction_close_transaction");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */