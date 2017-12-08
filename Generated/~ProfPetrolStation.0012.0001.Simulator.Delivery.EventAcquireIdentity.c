
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Simulator Delivery Acquire Identity Event */

void adm_sim_acquire_identity_event_delivery_fuel_unit_delivered(
    void)
{
    adm_ent_delivery_typ * ent_delivery;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_delivery_fuel_unit_delivered");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_delivery = adm_entity_system.ent_delivery.live_list_head;

    while (
        entity_not_found &&
        ent_delivery != NULL) {

        if (ent_delivery->identity == identity) {

            adm_send_event_delivery_fuel_unit_delivered(
                NULL,
                ent_delivery,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_delivery = ent_delivery->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_delivery_fuel_unit_delivered");
    #endif
}

void adm_sim_acquire_identity_event_delivery_delivery_complete(
    void)
{
    adm_ent_delivery_typ * ent_delivery;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_delivery_delivery_complete");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_delivery = adm_entity_system.ent_delivery.live_list_head;

    while (
        entity_not_found &&
        ent_delivery != NULL) {

        if (ent_delivery->identity == identity) {

            adm_send_event_delivery_delivery_complete(
                NULL,
                ent_delivery,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_delivery = ent_delivery->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_delivery_delivery_complete");
    #endif
}

void adm_sim_acquire_identity_event_delivery_delete_delivery(
    void)
{
    adm_ent_delivery_typ * ent_delivery;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_delivery_delete_delivery");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_delivery = adm_entity_system.ent_delivery.live_list_head;

    while (
        entity_not_found &&
        ent_delivery != NULL) {

        if (ent_delivery->identity == identity) {

            adm_send_event_delivery_delete_delivery(
                NULL,
                ent_delivery,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_delivery = ent_delivery->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_delivery_delete_delivery");
    #endif
}

void adm_sim_acquire_identity_event_delivery_create_delivery(
    void)
{
    adm_base_integer_typ evd_num_pump_number;
    adm_base_integer_typ evd_num_timestamp_hours;
    adm_base_integer_typ evd_num_timestamp_minutes;
    adm_base_integer_typ evd_num_timestamp_seconds;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_delivery_create_delivery");
    #endif

    /* Fetch Event Data */

    evd_num_pump_number = adm_sim_int_fetch();

    evd_num_timestamp_hours = adm_sim_int_fetch();

    evd_num_timestamp_minutes = adm_sim_int_fetch();

    evd_num_timestamp_seconds = adm_sim_int_fetch();

    /* Check Event Data Type Ranges */

    if (
        evd_num_pump_number < ADM_TYPE_MINIMUM_EQUIPMENT_NUMBER ||
        evd_num_pump_number > ADM_TYPE_MAXIMUM_EQUIPMENT_NUMBER) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(evd_num_pump_number));
    }

    if (
        evd_num_timestamp_hours < ADM_TYPE_MINIMUM_TIME_HOUR ||
        evd_num_timestamp_hours > ADM_TYPE_MAXIMUM_TIME_HOUR) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(evd_num_timestamp_hours));
    }

    if (
        evd_num_timestamp_minutes < ADM_TYPE_MINIMUM_TIME_MINUTE ||
        evd_num_timestamp_minutes > ADM_TYPE_MAXIMUM_TIME_MINUTE) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(evd_num_timestamp_minutes));
    }

    if (
        evd_num_timestamp_seconds < ADM_TYPE_MINIMUM_TIME_SECOND ||
        evd_num_timestamp_seconds > ADM_TYPE_MAXIMUM_TIME_SECOND) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(evd_num_timestamp_seconds));
    }

    /* Generate Event */

    adm_send_event_delivery_create_delivery(
        evd_num_pump_number,
        evd_num_timestamp_hours,
        evd_num_timestamp_minutes,
        evd_num_timestamp_seconds,
        0, 0, 0);

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_delivery_create_delivery");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */