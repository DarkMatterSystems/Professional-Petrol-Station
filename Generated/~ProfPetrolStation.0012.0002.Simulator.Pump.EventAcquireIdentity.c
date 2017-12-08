
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Simulator Pump Acquire Identity Event */

void adm_sim_acquire_identity_event_pump_gun_removed(
    void)
{
    adm_ent_pump_typ * ent_pump;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_pump_gun_removed");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_pump = adm_entity_system.ent_pump.live_list_head;

    while (
        entity_not_found &&
        ent_pump != NULL) {

        if (ent_pump->identity == identity) {

            adm_send_event_pump_gun_removed(
                NULL,
                ent_pump,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_pump = ent_pump->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_pump_gun_removed");
    #endif
}

void adm_sim_acquire_identity_event_pump_gun_replaced(
    void)
{
    adm_ent_pump_typ * ent_pump;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_pump_gun_replaced");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_pump = adm_entity_system.ent_pump.live_list_head;

    while (
        entity_not_found &&
        ent_pump != NULL) {

        if (ent_pump->identity == identity) {

            adm_send_event_pump_gun_replaced(
                NULL,
                ent_pump,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_pump = ent_pump->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_pump_gun_replaced");
    #endif
}

void adm_sim_acquire_identity_event_pump_fuel_level_low(
    void)
{
    adm_ent_pump_typ * ent_pump;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_pump_fuel_level_low");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_pump = adm_entity_system.ent_pump.live_list_head;

    while (
        entity_not_found &&
        ent_pump != NULL) {

        if (ent_pump->identity == identity) {

            adm_send_event_pump_fuel_level_low(
                NULL,
                ent_pump,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_pump = ent_pump->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_pump_fuel_level_low");
    #endif
}

void adm_sim_acquire_identity_event_pump_fuel_available(
    void)
{
    adm_ent_pump_typ * ent_pump;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_pump_fuel_available");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_pump = adm_entity_system.ent_pump.live_list_head;

    while (
        entity_not_found &&
        ent_pump != NULL) {

        if (ent_pump->identity == identity) {

            adm_send_event_pump_fuel_available(
                NULL,
                ent_pump,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_pump = ent_pump->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_pump_fuel_available");
    #endif
}

void adm_sim_acquire_identity_event_pump_pump_enabled(
    void)
{
    adm_ent_pump_typ * ent_pump;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_pump_pump_enabled");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_pump = adm_entity_system.ent_pump.live_list_head;

    while (
        entity_not_found &&
        ent_pump != NULL) {

        if (ent_pump->identity == identity) {

            adm_send_event_pump_pump_enabled(
                NULL,
                ent_pump,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_pump = ent_pump->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_pump_pump_enabled");
    #endif
}

void adm_sim_acquire_identity_event_pump_trigger_depressed(
    void)
{
    adm_ent_pump_typ * ent_pump;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_pump_trigger_depressed");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_pump = adm_entity_system.ent_pump.live_list_head;

    while (
        entity_not_found &&
        ent_pump != NULL) {

        if (ent_pump->identity == identity) {

            adm_send_event_pump_trigger_depressed(
                NULL,
                ent_pump,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_pump = ent_pump->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_pump_trigger_depressed");
    #endif
}

void adm_sim_acquire_identity_event_pump_trigger_released(
    void)
{
    adm_ent_pump_typ * ent_pump;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_pump_trigger_released");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_pump = adm_entity_system.ent_pump.live_list_head;

    while (
        entity_not_found &&
        ent_pump != NULL) {

        if (ent_pump->identity == identity) {

            adm_send_event_pump_trigger_released(
                NULL,
                ent_pump,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_pump = ent_pump->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_pump_trigger_released");
    #endif
}

void adm_sim_acquire_identity_event_pump_customer_finished(
    void)
{
    adm_ent_pump_typ * ent_pump;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_pump_customer_finished");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_pump = adm_entity_system.ent_pump.live_list_head;

    while (
        entity_not_found &&
        ent_pump != NULL) {

        if (ent_pump->identity == identity) {

            adm_send_event_pump_customer_finished(
                NULL,
                ent_pump,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_pump = ent_pump->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_pump_customer_finished");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */