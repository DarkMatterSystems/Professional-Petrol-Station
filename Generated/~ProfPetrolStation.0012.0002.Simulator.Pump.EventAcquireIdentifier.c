
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Simulator Pump Acquire Identifier Event */

void adm_sim_acquire_identifier_event_pump_gun_removed_pump_identifier(
    void)
{
    adm_ent_pump_typ * ent_pump;
    adm_base_boolean_typ entity_not_found;
    adm_base_integer_typ key_num_pump_pump_number;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_pump_gun_removed_pump_identifier");
    #endif

    /* Fetch Event Keys */

    key_num_pump_pump_number = adm_sim_int_fetch();

    /* Check Event Key Type Ranges */

    if (
        key_num_pump_pump_number < ADM_TYPE_MINIMUM_EQUIPMENT_NUMBER ||
        key_num_pump_pump_number > ADM_TYPE_MAXIMUM_EQUIPMENT_NUMBER) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(key_num_pump_pump_number));
    }

    /* Generate Event */

    entity_not_found = TRUE;

    ent_pump = adm_entity_system.ent_pump.live_list_head;

    while (
        entity_not_found &&
        ent_pump != NULL) {

        if (
            ent_pump->atb_pump_number == key_num_pump_pump_number) {

            adm_send_event_pump_gun_removed(
                NULL,
                ent_pump,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_pump = ent_pump->next;
    }

    /* Check Object Identifier */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTIFIER,
            NULL);

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_pump_gun_removed_pump_identifier");
    #endif
}

void adm_sim_acquire_identifier_event_pump_gun_replaced_pump_identifier(
    void)
{
    adm_ent_pump_typ * ent_pump;
    adm_base_boolean_typ entity_not_found;
    adm_base_integer_typ key_num_pump_pump_number;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_pump_gun_replaced_pump_identifier");
    #endif

    /* Fetch Event Keys */

    key_num_pump_pump_number = adm_sim_int_fetch();

    /* Check Event Key Type Ranges */

    if (
        key_num_pump_pump_number < ADM_TYPE_MINIMUM_EQUIPMENT_NUMBER ||
        key_num_pump_pump_number > ADM_TYPE_MAXIMUM_EQUIPMENT_NUMBER) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(key_num_pump_pump_number));
    }

    /* Generate Event */

    entity_not_found = TRUE;

    ent_pump = adm_entity_system.ent_pump.live_list_head;

    while (
        entity_not_found &&
        ent_pump != NULL) {

        if (
            ent_pump->atb_pump_number == key_num_pump_pump_number) {

            adm_send_event_pump_gun_replaced(
                NULL,
                ent_pump,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_pump = ent_pump->next;
    }

    /* Check Object Identifier */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTIFIER,
            NULL);

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_pump_gun_replaced_pump_identifier");
    #endif
}

void adm_sim_acquire_identifier_event_pump_fuel_level_low_pump_identifier(
    void)
{
    adm_ent_pump_typ * ent_pump;
    adm_base_boolean_typ entity_not_found;
    adm_base_integer_typ key_num_pump_pump_number;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_pump_fuel_level_low_pump_identifier");
    #endif

    /* Fetch Event Keys */

    key_num_pump_pump_number = adm_sim_int_fetch();

    /* Check Event Key Type Ranges */

    if (
        key_num_pump_pump_number < ADM_TYPE_MINIMUM_EQUIPMENT_NUMBER ||
        key_num_pump_pump_number > ADM_TYPE_MAXIMUM_EQUIPMENT_NUMBER) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(key_num_pump_pump_number));
    }

    /* Generate Event */

    entity_not_found = TRUE;

    ent_pump = adm_entity_system.ent_pump.live_list_head;

    while (
        entity_not_found &&
        ent_pump != NULL) {

        if (
            ent_pump->atb_pump_number == key_num_pump_pump_number) {

            adm_send_event_pump_fuel_level_low(
                NULL,
                ent_pump,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_pump = ent_pump->next;
    }

    /* Check Object Identifier */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTIFIER,
            NULL);

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_pump_fuel_level_low_pump_identifier");
    #endif
}

void adm_sim_acquire_identifier_event_pump_fuel_available_pump_identifier(
    void)
{
    adm_ent_pump_typ * ent_pump;
    adm_base_boolean_typ entity_not_found;
    adm_base_integer_typ key_num_pump_pump_number;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_pump_fuel_available_pump_identifier");
    #endif

    /* Fetch Event Keys */

    key_num_pump_pump_number = adm_sim_int_fetch();

    /* Check Event Key Type Ranges */

    if (
        key_num_pump_pump_number < ADM_TYPE_MINIMUM_EQUIPMENT_NUMBER ||
        key_num_pump_pump_number > ADM_TYPE_MAXIMUM_EQUIPMENT_NUMBER) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(key_num_pump_pump_number));
    }

    /* Generate Event */

    entity_not_found = TRUE;

    ent_pump = adm_entity_system.ent_pump.live_list_head;

    while (
        entity_not_found &&
        ent_pump != NULL) {

        if (
            ent_pump->atb_pump_number == key_num_pump_pump_number) {

            adm_send_event_pump_fuel_available(
                NULL,
                ent_pump,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_pump = ent_pump->next;
    }

    /* Check Object Identifier */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTIFIER,
            NULL);

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_pump_fuel_available_pump_identifier");
    #endif
}

void adm_sim_acquire_identifier_event_pump_pump_enabled_pump_identifier(
    void)
{
    adm_ent_pump_typ * ent_pump;
    adm_base_boolean_typ entity_not_found;
    adm_base_integer_typ key_num_pump_pump_number;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_pump_pump_enabled_pump_identifier");
    #endif

    /* Fetch Event Keys */

    key_num_pump_pump_number = adm_sim_int_fetch();

    /* Check Event Key Type Ranges */

    if (
        key_num_pump_pump_number < ADM_TYPE_MINIMUM_EQUIPMENT_NUMBER ||
        key_num_pump_pump_number > ADM_TYPE_MAXIMUM_EQUIPMENT_NUMBER) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(key_num_pump_pump_number));
    }

    /* Generate Event */

    entity_not_found = TRUE;

    ent_pump = adm_entity_system.ent_pump.live_list_head;

    while (
        entity_not_found &&
        ent_pump != NULL) {

        if (
            ent_pump->atb_pump_number == key_num_pump_pump_number) {

            adm_send_event_pump_pump_enabled(
                NULL,
                ent_pump,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_pump = ent_pump->next;
    }

    /* Check Object Identifier */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTIFIER,
            NULL);

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_pump_pump_enabled_pump_identifier");
    #endif
}

void adm_sim_acquire_identifier_event_pump_trigger_depressed_pump_identifier(
    void)
{
    adm_ent_pump_typ * ent_pump;
    adm_base_boolean_typ entity_not_found;
    adm_base_integer_typ key_num_pump_pump_number;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_pump_trigger_depressed_pump_identifier");
    #endif

    /* Fetch Event Keys */

    key_num_pump_pump_number = adm_sim_int_fetch();

    /* Check Event Key Type Ranges */

    if (
        key_num_pump_pump_number < ADM_TYPE_MINIMUM_EQUIPMENT_NUMBER ||
        key_num_pump_pump_number > ADM_TYPE_MAXIMUM_EQUIPMENT_NUMBER) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(key_num_pump_pump_number));
    }

    /* Generate Event */

    entity_not_found = TRUE;

    ent_pump = adm_entity_system.ent_pump.live_list_head;

    while (
        entity_not_found &&
        ent_pump != NULL) {

        if (
            ent_pump->atb_pump_number == key_num_pump_pump_number) {

            adm_send_event_pump_trigger_depressed(
                NULL,
                ent_pump,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_pump = ent_pump->next;
    }

    /* Check Object Identifier */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTIFIER,
            NULL);

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_pump_trigger_depressed_pump_identifier");
    #endif
}

void adm_sim_acquire_identifier_event_pump_trigger_released_pump_identifier(
    void)
{
    adm_ent_pump_typ * ent_pump;
    adm_base_boolean_typ entity_not_found;
    adm_base_integer_typ key_num_pump_pump_number;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_pump_trigger_released_pump_identifier");
    #endif

    /* Fetch Event Keys */

    key_num_pump_pump_number = adm_sim_int_fetch();

    /* Check Event Key Type Ranges */

    if (
        key_num_pump_pump_number < ADM_TYPE_MINIMUM_EQUIPMENT_NUMBER ||
        key_num_pump_pump_number > ADM_TYPE_MAXIMUM_EQUIPMENT_NUMBER) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(key_num_pump_pump_number));
    }

    /* Generate Event */

    entity_not_found = TRUE;

    ent_pump = adm_entity_system.ent_pump.live_list_head;

    while (
        entity_not_found &&
        ent_pump != NULL) {

        if (
            ent_pump->atb_pump_number == key_num_pump_pump_number) {

            adm_send_event_pump_trigger_released(
                NULL,
                ent_pump,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_pump = ent_pump->next;
    }

    /* Check Object Identifier */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTIFIER,
            NULL);

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_pump_trigger_released_pump_identifier");
    #endif
}

void adm_sim_acquire_identifier_event_pump_customer_finished_pump_identifier(
    void)
{
    adm_ent_pump_typ * ent_pump;
    adm_base_boolean_typ entity_not_found;
    adm_base_integer_typ key_num_pump_pump_number;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_pump_customer_finished_pump_identifier");
    #endif

    /* Fetch Event Keys */

    key_num_pump_pump_number = adm_sim_int_fetch();

    /* Check Event Key Type Ranges */

    if (
        key_num_pump_pump_number < ADM_TYPE_MINIMUM_EQUIPMENT_NUMBER ||
        key_num_pump_pump_number > ADM_TYPE_MAXIMUM_EQUIPMENT_NUMBER) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(key_num_pump_pump_number));
    }

    /* Generate Event */

    entity_not_found = TRUE;

    ent_pump = adm_entity_system.ent_pump.live_list_head;

    while (
        entity_not_found &&
        ent_pump != NULL) {

        if (
            ent_pump->atb_pump_number == key_num_pump_pump_number) {

            adm_send_event_pump_customer_finished(
                NULL,
                ent_pump,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_pump = ent_pump->next;
    }

    /* Check Object Identifier */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTIFIER,
            NULL);

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_pump_customer_finished_pump_identifier");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */