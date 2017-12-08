
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Simulator Transaction Acquire Identifier Event */

void adm_sim_acquire_identifier_event_transaction_payment_received_transaction_identifier(
    void)
{
    adm_ent_transaction_typ * ent_transaction;
    adm_base_boolean_typ entity_not_found;
    adm_base_integer_typ key_num_transaction_transaction_number;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_transaction_payment_received_transaction_identifier");
    #endif

    /* Fetch Event Keys */

    key_num_transaction_transaction_number = adm_sim_int_fetch();

    /* Check Event Key Type Ranges */

    if (
        key_num_transaction_transaction_number < ADM_TYPE_MINIMUM_BUSINESS_NUMBER ||
        key_num_transaction_transaction_number > ADM_TYPE_MAXIMUM_BUSINESS_NUMBER) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(key_num_transaction_transaction_number));
    }

    /* Generate Event */

    entity_not_found = TRUE;

    ent_transaction = adm_entity_system.ent_transaction.live_list_head;

    while (
        entity_not_found &&
        ent_transaction != NULL) {

        if (
            ent_transaction->atb_transaction_number == key_num_transaction_transaction_number) {

            adm_send_event_transaction_payment_received(
                NULL,
                ent_transaction,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_transaction = ent_transaction->next;
    }

    /* Check Object Identifier */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTIFIER,
            NULL);

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_transaction_payment_received_transaction_identifier");
    #endif
}

void adm_sim_acquire_identifier_event_transaction_customer_absconds_transaction_identifier(
    void)
{
    adm_ent_transaction_typ * ent_transaction;
    adm_base_boolean_typ entity_not_found;
    adm_base_integer_typ key_num_transaction_transaction_number;
    adm_base_string_typ evd_nme_customer_details [ADM_TYPE_SIZE_TEXT+1];

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_transaction_customer_absconds_transaction_identifier");
    #endif

    /* Fetch Event Keys */

    key_num_transaction_transaction_number = adm_sim_int_fetch();

    /* Fetch Event Data */

    adm_sim_str_fetch(
        evd_nme_customer_details,
        ADM_TYPE_SIZE_TEXT+1);

    /* Check Event Key Type Ranges */

    if (
        key_num_transaction_transaction_number < ADM_TYPE_MINIMUM_BUSINESS_NUMBER ||
        key_num_transaction_transaction_number > ADM_TYPE_MAXIMUM_BUSINESS_NUMBER) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(key_num_transaction_transaction_number));
    }

    /* Check Event Data Type Ranges */

    /* Generate Event */

    entity_not_found = TRUE;

    ent_transaction = adm_entity_system.ent_transaction.live_list_head;

    while (
        entity_not_found &&
        ent_transaction != NULL) {

        if (
            ent_transaction->atb_transaction_number == key_num_transaction_transaction_number) {

            adm_send_event_transaction_customer_absconds(
                NULL,
                ent_transaction,
                evd_nme_customer_details,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_transaction = ent_transaction->next;
    }

    /* Check Object Identifier */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTIFIER,
            NULL);

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_transaction_customer_absconds_transaction_identifier");
    #endif
}

void adm_sim_acquire_identifier_event_transaction_close_transaction_transaction_identifier(
    void)
{
    adm_ent_transaction_typ * ent_transaction;
    adm_base_boolean_typ entity_not_found;
    adm_base_integer_typ key_num_transaction_transaction_number;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_transaction_close_transaction_transaction_identifier");
    #endif

    /* Fetch Event Keys */

    key_num_transaction_transaction_number = adm_sim_int_fetch();

    /* Check Event Key Type Ranges */

    if (
        key_num_transaction_transaction_number < ADM_TYPE_MINIMUM_BUSINESS_NUMBER ||
        key_num_transaction_transaction_number > ADM_TYPE_MAXIMUM_BUSINESS_NUMBER) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(key_num_transaction_transaction_number));
    }

    /* Generate Event */

    entity_not_found = TRUE;

    ent_transaction = adm_entity_system.ent_transaction.live_list_head;

    while (
        entity_not_found &&
        ent_transaction != NULL) {

        if (
            ent_transaction->atb_transaction_number == key_num_transaction_transaction_number) {

            adm_send_event_transaction_close_transaction(
                NULL,
                ent_transaction,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_transaction = ent_transaction->next;
    }

    /* Check Object Identifier */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTIFIER,
            NULL);

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_transaction_close_transaction_transaction_identifier");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */