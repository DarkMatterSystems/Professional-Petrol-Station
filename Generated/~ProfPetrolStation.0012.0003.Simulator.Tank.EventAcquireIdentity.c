
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Simulator Tank Acquire Identity Event */

void adm_sim_acquire_identity_event_tank_level_below_threshold(
    void)
{
    adm_ent_tank_typ * ent_tank;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_tank_level_below_threshold");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_tank = adm_entity_system.ent_tank.live_list_head;

    while (
        entity_not_found &&
        ent_tank != NULL) {

        if (ent_tank->identity == identity) {

            adm_send_event_tank_level_below_threshold(
                NULL,
                ent_tank,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_tank = ent_tank->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_tank_level_below_threshold");
    #endif
}

void adm_sim_acquire_identity_event_tank_level_above_threshold(
    void)
{
    adm_ent_tank_typ * ent_tank;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_tank_level_above_threshold");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_tank = adm_entity_system.ent_tank.live_list_head;

    while (
        entity_not_found &&
        ent_tank != NULL) {

        if (ent_tank->identity == identity) {

            adm_send_event_tank_level_above_threshold(
                NULL,
                ent_tank,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_tank = ent_tank->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_tank_level_above_threshold");
    #endif
}

void adm_sim_acquire_identity_event_tank_tanker_delivery(
    void)
{
    adm_ent_tank_typ * ent_tank;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;
    adm_base_float_typ evd_num_added_volume;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_tank_tanker_delivery");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Fetch Event Data */

    evd_num_added_volume = adm_sim_fxd_fetch();

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

        if (ent_tank->identity == identity) {

            adm_send_event_tank_tanker_delivery(
                NULL,
                ent_tank,
                (adm_base_fixed_typ)evd_num_added_volume,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_tank = ent_tank->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_tank_tanker_delivery");
    #endif
}

void adm_sim_acquire_identity_event_tank_fuel_used(
    void)
{
    adm_ent_tank_typ * ent_tank;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;
    adm_base_float_typ evd_num_delivered_volume;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_tank_fuel_used");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Fetch Event Data */

    evd_num_delivered_volume = adm_sim_fxd_fetch();

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

        if (ent_tank->identity == identity) {

            adm_send_event_tank_fuel_used(
                NULL,
                ent_tank,
                (adm_base_fixed_typ)evd_num_delivered_volume,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_tank = ent_tank->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_tank_fuel_used");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */