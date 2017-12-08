
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Simulator Delivery Acquire Identifier Event */

void adm_sim_acquire_identifier_event_delivery_fuel_unit_delivered_delivery_identifier(
    void)
{
    adm_ent_delivery_typ * ent_delivery;
    adm_base_boolean_typ entity_not_found;
    adm_base_integer_typ key_num_pump_pump_number;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_delivery_fuel_unit_delivered_delivery_identifier");
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

    ent_delivery = adm_entity_system.ent_delivery.live_list_head;

    while (
        entity_not_found &&
        ent_delivery != NULL) {

        if (
            ((
                ent_delivery->rel_being_made_using_pump_head)->
                ent_pump)->atb_pump_number == key_num_pump_pump_number) {

            adm_send_event_delivery_fuel_unit_delivered(
                NULL,
                ent_delivery,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_delivery = ent_delivery->next;
    }

    /* Check Object Identifier */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTIFIER,
            NULL);

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_delivery_fuel_unit_delivered_delivery_identifier");
    #endif
}

void adm_sim_acquire_identifier_event_delivery_delivery_complete_delivery_identifier(
    void)
{
    adm_ent_delivery_typ * ent_delivery;
    adm_base_boolean_typ entity_not_found;
    adm_base_integer_typ key_num_pump_pump_number;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_delivery_delivery_complete_delivery_identifier");
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

    ent_delivery = adm_entity_system.ent_delivery.live_list_head;

    while (
        entity_not_found &&
        ent_delivery != NULL) {

        if (
            ((
                ent_delivery->rel_being_made_using_pump_head)->
                ent_pump)->atb_pump_number == key_num_pump_pump_number) {

            adm_send_event_delivery_delivery_complete(
                NULL,
                ent_delivery,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_delivery = ent_delivery->next;
    }

    /* Check Object Identifier */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTIFIER,
            NULL);

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_delivery_delivery_complete_delivery_identifier");
    #endif
}

void adm_sim_acquire_identifier_event_delivery_delete_delivery_delivery_identifier(
    void)
{
    adm_ent_delivery_typ * ent_delivery;
    adm_base_boolean_typ entity_not_found;
    adm_base_integer_typ key_num_pump_pump_number;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_delivery_delete_delivery_delivery_identifier");
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

    ent_delivery = adm_entity_system.ent_delivery.live_list_head;

    while (
        entity_not_found &&
        ent_delivery != NULL) {

        if (
            ((
                ent_delivery->rel_being_made_using_pump_head)->
                ent_pump)->atb_pump_number == key_num_pump_pump_number) {

            adm_send_event_delivery_delete_delivery(
                NULL,
                ent_delivery,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_delivery = ent_delivery->next;
    }

    /* Check Object Identifier */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTIFIER,
            NULL);

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_delivery_delete_delivery_delivery_identifier");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */