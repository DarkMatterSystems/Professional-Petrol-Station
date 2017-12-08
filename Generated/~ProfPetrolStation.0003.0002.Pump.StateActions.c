
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Pump State Actions */

void adm_state_action_pump_waiting_pump_enable(
    adm_ent_pump_typ * const ent_pump)
{
    /* Entity Objects */
    adm_ent_tank_typ * ent_tank_0000000001;

    /* Relationship Relations */
    adm_rel_pump_pumping_fuel_from_tank_typ * rel_pump_pumping_fuel_from_tank_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_pump_waiting_pump_enable");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_pump(
        ent_pump,
        3, 56, 29);

    rel_pump_pumping_fuel_from_tank_0000000001 = ent_pump->rel_pumping_fuel_from_tank_head;

    if (rel_pump_pumping_fuel_from_tank_0000000001 != NULL) {

        ent_tank_0000000001 = rel_pump_pumping_fuel_from_tank_0000000001->ent_tank;

        /* CaseSelection */

        if (
            (
                (
                    ent_tank_0000000001->atb_tank_empty_flag
                )
            )) {

            /* GenerateEvent */

            adm_send_event_pump_fuel_level_low(
                ent_pump,
                ent_pump,
                3, 65, 45);

        } else {

            /* Template */

            adm_write_newline();
            adm_write_str("ATTENDANT~>Request_Pump_Enable");
            adm_write_newline();
        }

    } else {

        adm_error_report(
            ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
            3, 56, 29,
            "Pump",
            ent_pump->identity,
            "Pumping_fuel_from",
            "Tank");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_pump_waiting_pump_enable");
    #endif
}

void adm_state_action_pump_fuel_unavailable(
    adm_ent_pump_typ * const ent_pump)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_pump_fuel_unavailable");
    #endif

    /* Template */

    adm_write_newline();
    adm_write_str("CUSTOMER~>Pump_Unavailable");
    adm_write_newline();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_pump_fuel_unavailable");
    #endif
}

void adm_state_action_pump_fuel_delivery_complete(
    adm_ent_pump_typ * const ent_pump)
{
    /* Entity Objects */
    adm_ent_delivery_typ * ent_delivery_0000000001;

    /* Relationship Relations */
    adm_rel_pump_being_used_for_delivery_typ * rel_pump_being_used_for_delivery_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_pump_fuel_delivery_complete");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_pump(
        ent_pump,
        3, 122, 29);

    rel_pump_being_used_for_delivery_0000000001 = ent_pump->rel_being_used_for_delivery_head;

    if (rel_pump_being_used_for_delivery_0000000001 != NULL) {

        ent_delivery_0000000001 = rel_pump_being_used_for_delivery_0000000001->ent_delivery;

        /* GenerateEvent */

        adm_send_event_delivery_delivery_complete(
            ent_pump,
            ent_delivery_0000000001,
            3, 125, 33);
    }

    /* Template */

    adm_write_newline();
    adm_write_str("MOTOR~>Stop_Motor");
    adm_write_newline();

    /* GenerateEvent */

    adm_send_event_pump_customer_finished(
        ent_pump,
        ent_pump,
        3, 130, 25);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_pump_fuel_delivery_complete");
    #endif
}

void adm_state_action_pump_ready_to_pump(
    adm_ent_pump_typ * const ent_pump)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_pump_ready_to_pump");
    #endif

    /* Template */

    adm_write_newline();
    adm_write_str("MOTOR~>Start_Motor");
    adm_write_newline();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_pump_ready_to_pump");
    #endif
}

void adm_state_action_pump_pumping_paused(
    adm_ent_pump_typ * const ent_pump)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_pump_pumping_paused");
    #endif

    /* Template */

    adm_write_newline();
    adm_write_str("CLUTCH~>Disengage_Clutch");
    adm_write_newline();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_pump_pumping_paused");
    #endif
}

void adm_state_action_pump_pumping(
    adm_ent_pump_typ * const ent_pump)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_pump_pumping");
    #endif

    /* Template */

    adm_write_newline();
    adm_write_str("CLUTCH~>Engage_Clutch");
    adm_write_newline();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_pump_pumping");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */