
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Simulator Tank Acquire Identifier Event */

void adm_sim_acquire_identifier_event_tank_level_below_threshold_tank_identifier(
    void)
{
    adm_ent_tank_typ * ent_tank;
    adm_base_boolean_typ entity_not_found;
    adm_base_integer_typ key_num_tank_tank_number;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_tank_level_below_threshold_tank_identifier");
    #endif

    /* Fetch Event Keys */

    key_num_tank_tank_number = adm_sim_int_fetch();

    /* Check Event Key Type Ranges */

    if (
        key_num_tank_tank_number < ADM_TYPE_MINIMUM_EQUIPMENT_NUMBER ||
        key_num_tank_tank_number > ADM_TYPE_MAXIMUM_EQUIPMENT_NUMBER) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(key_num_tank_tank_number));
    }

    /* Generate Event */

    entity_not_found = TRUE;

    ent_tank = adm_entity_system.ent_tank.live_list_head;

    while (
        entity_not_found &&
        ent_tank != NULL) {

        if (
            ent_tank->atb_tank_number == key_num_tank_tank_number) {

            adm_send_event_tank_level_below_threshold(
                NULL,
                ent_tank,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_tank = ent_tank->next;
    }

    /* Check Object Identifier */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTIFIER,
            NULL);

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_tank_level_below_threshold_tank_identifier");
    #endif
}

void adm_sim_acquire_identifier_event_tank_level_above_threshold_tank_identifier(
    void)
{
    adm_ent_tank_typ * ent_tank;
    adm_base_boolean_typ entity_not_found;
    adm_base_integer_typ key_num_tank_tank_number;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_tank_level_above_threshold_tank_identifier");
    #endif

    /* Fetch Event Keys */

    key_num_tank_tank_number = adm_sim_int_fetch();

    /* Check Event Key Type Ranges */

    if (
        key_num_tank_tank_number < ADM_TYPE_MINIMUM_EQUIPMENT_NUMBER ||
        key_num_tank_tank_number > ADM_TYPE_MAXIMUM_EQUIPMENT_NUMBER) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(key_num_tank_tank_number));
    }

    /* Generate Event */

    entity_not_found = TRUE;

    ent_tank = adm_entity_system.ent_tank.live_list_head;

    while (
        entity_not_found &&
        ent_tank != NULL) {

        if (
            ent_tank->atb_tank_number == key_num_tank_tank_number) {

            adm_send_event_tank_level_above_threshold(
                NULL,
                ent_tank,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_tank = ent_tank->next;
    }

    /* Check Object Identifier */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTIFIER,
            NULL);

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_tank_level_above_threshold_tank_identifier");
    #endif
}

void adm_sim_acquire_identifier_event_tank_tanker_delivery_tank_identifier(
    void)
{
    adm_ent_tank_typ * ent_tank;
    adm_base_boolean_typ entity_not_found;
    adm_base_integer_typ key_num_tank_tank_number;
    adm_base_float_typ evd_num_added_volume;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_tank_tanker_delivery_tank_identifier");
    #endif

    /* Fetch Event Keys */

    key_num_tank_tank_number = adm_sim_int_fetch();

    /* Fetch Event Data */

    evd_num_added_volume = adm_sim_fxd_fetch();

    /* Check Event Key Type Ranges */

    if (
        key_num_tank_tank_number < ADM_TYPE_MINIMUM_EQUIPMENT_NUMBER ||
        key_num_tank_tank_number > ADM_TYPE_MAXIMUM_EQUIPMENT_NUMBER) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(key_num_tank_tank_number));
    }

    /* Check Event Data Type Ranges */

    if (
        evd_num_added_volume < ADM_TYPE_MINIMUM_VOLUME ||
        evd_num_added_volume > ADM_TYPE_MAXIMUM_VOLUME) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_FIXED,
            adm_sim_lib_fxtoa(evd_num_added_volume));
    }

    /* Generate Event */

    entity_not_found = TRUE;

    ent_tank = adm_entity_system.ent_tank.live_list_head;

    while (
        entity_not_found &&
        ent_tank != NULL) {

        if (
            ent_tank->atb_tank_number == key_num_tank_tank_number) {

            adm_send_event_tank_tanker_delivery(
                NULL,
                ent_tank,
                (adm_base_fixed_typ)evd_num_added_volume,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_tank = ent_tank->next;
    }

    /* Check Object Identifier */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTIFIER,
            NULL);

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_tank_tanker_delivery_tank_identifier");
    #endif
}

void adm_sim_acquire_identifier_event_tank_fuel_used_tank_identifier(
    void)
{
    adm_ent_tank_typ * ent_tank;
    adm_base_boolean_typ entity_not_found;
    adm_base_integer_typ key_num_tank_tank_number;
    adm_base_float_typ evd_num_delivered_volume;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_tank_fuel_used_tank_identifier");
    #endif

    /* Fetch Event Keys */

    key_num_tank_tank_number = adm_sim_int_fetch();

    /* Fetch Event Data */

    evd_num_delivered_volume = adm_sim_fxd_fetch();

    /* Check Event Key Type Ranges */

    if (
        key_num_tank_tank_number < ADM_TYPE_MINIMUM_EQUIPMENT_NUMBER ||
        key_num_tank_tank_number > ADM_TYPE_MAXIMUM_EQUIPMENT_NUMBER) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(key_num_tank_tank_number));
    }

    /* Check Event Data Type Ranges */

    if (
        evd_num_delivered_volume < ADM_TYPE_MINIMUM_VOLUME ||
        evd_num_delivered_volume > ADM_TYPE_MAXIMUM_VOLUME) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_FIXED,
            adm_sim_lib_fxtoa(evd_num_delivered_volume));
    }

    /* Generate Event */

    entity_not_found = TRUE;

    ent_tank = adm_entity_system.ent_tank.live_list_head;

    while (
        entity_not_found &&
        ent_tank != NULL) {

        if (
            ent_tank->atb_tank_number == key_num_tank_tank_number) {

            adm_send_event_tank_fuel_used(
                NULL,
                ent_tank,
                (adm_base_fixed_typ)evd_num_delivered_volume,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_tank = ent_tank->next;
    }

    /* Check Object Identifier */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTIFIER,
            NULL);

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_tank_fuel_used_tank_identifier");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */