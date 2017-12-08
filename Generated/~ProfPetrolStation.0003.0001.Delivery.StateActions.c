
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Delivery State Actions */

void adm_state_action_delivery_creating_delivery(
    adm_ent_delivery_typ * const ent_delivery,
    const adm_dst_delivery_pump_number_typ * const dst_pump_number)
{
    /* Entity Objects */
    adm_ent_pump_typ * ent_pump_0000000001;
    adm_ent_pump_typ * nxt_pump_0000000001;

    /* Identifier Flags */
    adm_base_boolean_typ identifier_not_found_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_delivery_creating_delivery");
    #endif

    /* Assignment - Set */

    if (
        dst_pump_number->timestamp_hours < ADM_TYPE_MINIMUM_TIME_HOUR ||
        dst_pump_number->timestamp_hours > ADM_TYPE_MAXIMUM_TIME_HOUR) {

        adm_error_report(
            ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
            2, 44, 29,
            "Delivery",
            ent_delivery->identity,
            "Timestamp_hours",
            adm_sim_lib_itoa(dst_pump_number->timestamp_hours));
    }

    ent_delivery->atb_timestamp_hours = +dst_pump_number->timestamp_hours;

    /* Assignment - Set */

    if (
        dst_pump_number->timestamp_minutes < ADM_TYPE_MINIMUM_TIME_MINUTE ||
        dst_pump_number->timestamp_minutes > ADM_TYPE_MAXIMUM_TIME_MINUTE) {

        adm_error_report(
            ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
            2, 45, 29,
            "Delivery",
            ent_delivery->identity,
            "Timestamp_minutes",
            adm_sim_lib_itoa(dst_pump_number->timestamp_minutes));
    }

    ent_delivery->atb_timestamp_minutes = +dst_pump_number->timestamp_minutes;

    /* Assignment - Set */

    if (
        dst_pump_number->timestamp_seconds < ADM_TYPE_MINIMUM_TIME_SECOND ||
        dst_pump_number->timestamp_seconds > ADM_TYPE_MAXIMUM_TIME_SECOND) {

        adm_error_report(
            ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
            2, 46, 29,
            "Delivery",
            ent_delivery->identity,
            "Timestamp_seconds",
            adm_sim_lib_itoa(dst_pump_number->timestamp_seconds));
    }

    ent_delivery->atb_timestamp_seconds = +dst_pump_number->timestamp_seconds;

    /* Assignment - Set */

    if (
        0.0 < ADM_TYPE_MINIMUM_VOLUME ||
        0.0 > ADM_TYPE_MAXIMUM_VOLUME) {

        adm_error_report(
            ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
            2, 48, 29,
            "Delivery",
            ent_delivery->identity,
            "Volume_delivered",
            "0.0");
    }

    ent_delivery->atb_volume_delivered = 0.0;

    /* Assignment - Set */

    if (
        0.0 < ADM_TYPE_MINIMUM_MONEY ||
        0.0 > ADM_TYPE_MAXIMUM_MONEY) {

        adm_error_report(
            ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
            2, 49, 29,
            "Delivery",
            ent_delivery->identity,
            "Cost",
            "0.0");
    }

    ent_delivery->atb_cost = 0.0;

    /* IdentifierSelection */

    identifier_not_found_0000000001 = TRUE;

    ent_pump_0000000001 = adm_entity_system.ent_pump.live_list_head;

    while (
        identifier_not_found_0000000001 &&
        ent_pump_0000000001 != NULL) {

        nxt_pump_0000000001 = ent_pump_0000000001->next;

        if (
            ent_pump_0000000001->atb_pump_number == dst_pump_number->pump_number) {

            identifier_not_found_0000000001 = FALSE;

            /* Relate */

            adm_link_relation_delivery_being_made_using_pump(
                ent_delivery,
                ent_pump_0000000001,
                2, 62, 33);

            /* Relate */

            adm_link_relation_pump_being_used_for_delivery(
                ent_pump_0000000001,
                ent_delivery,
                2, 63, 33);

            /* GenerateEvent */

            adm_send_event_pump_pump_enabled(
                ent_delivery,
                ent_pump_0000000001,
                2, 65, 33);
        }

        ent_pump_0000000001 = nxt_pump_0000000001;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_delivery_creating_delivery");
    #endif
}

void adm_state_action_delivery_calculating_price_of_unconstrained_delivery(
    adm_ent_delivery_typ * const ent_delivery)
{
    /* Entity Objects */
    adm_ent_pump_typ * ent_pump_0000000001;
    adm_ent_tank_typ * ent_tank_0000000001;
    adm_ent_fuel_grade_typ * ent_fuel_grade_0000000001;

    /* Relationship Relations */
    adm_rel_delivery_being_made_using_pump_typ * rel_delivery_being_made_using_pump_0000000001;
    adm_rel_pump_pumping_fuel_from_tank_typ * rel_pump_pumping_fuel_from_tank_0000000001;
    adm_rel_tank_stores_fuel_grade_typ * rel_tank_stores_fuel_grade_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_delivery_calculating_price_of_unconstrained_delivery");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_delivery(
        ent_delivery,
        2, 92, 29);

    rel_delivery_being_made_using_pump_0000000001 = ent_delivery->rel_being_made_using_pump_head;

    if (rel_delivery_being_made_using_pump_0000000001 != NULL) {

        ent_pump_0000000001 = rel_delivery_being_made_using_pump_0000000001->ent_pump;

        rel_pump_pumping_fuel_from_tank_0000000001 = ent_pump_0000000001->rel_pumping_fuel_from_tank_head;

        if (rel_pump_pumping_fuel_from_tank_0000000001 != NULL) {

            ent_tank_0000000001 = rel_pump_pumping_fuel_from_tank_0000000001->ent_tank;

            rel_tank_stores_fuel_grade_0000000001 = ent_tank_0000000001->rel_stores_fuel_grade_head;

            if (rel_tank_stores_fuel_grade_0000000001 != NULL) {

                ent_fuel_grade_0000000001 = rel_tank_stores_fuel_grade_0000000001->ent_fuel_grade;

                /* Assignment - Evaluation */

                ent_delivery->atb_volume_delivered =
                    +(
                        +(
                            +ent_delivery->atb_volume_delivered
                            +
                            +ent_fuel_grade_0000000001->atb_unit_volume
                        )
                    );

                if (
                    ent_delivery->atb_volume_delivered < ADM_TYPE_MINIMUM_VOLUME ||
                    ent_delivery->atb_volume_delivered > ADM_TYPE_MAXIMUM_VOLUME) {

                    adm_error_report(
                        ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                        2, 97, 44,
                        "Delivery",
                        ent_delivery->identity,
                        "Volume_delivered",
                        adm_sim_lib_fxtoa(ent_delivery->atb_volume_delivered));
                }

                /* Assignment - Evaluation */

                ent_delivery->atb_cost =
                    +(
                        +(
                            +ent_delivery->atb_cost
                            +
                            +ent_fuel_grade_0000000001->atb_unit_price
                        )
                    );

                if (
                    ent_delivery->atb_cost < ADM_TYPE_MINIMUM_MONEY ||
                    ent_delivery->atb_cost > ADM_TYPE_MAXIMUM_MONEY) {

                    adm_error_report(
                        ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                        2, 102, 44,
                        "Delivery",
                        ent_delivery->identity,
                        "Cost",
                        adm_sim_lib_fxtoa(ent_delivery->atb_cost));
                }

            } else {

                adm_error_report(
                    ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                    2, 94, 29,
                    "Tank",
                    ent_tank_0000000001->identity,
                    "Stores",
                    "Fuel_Grade");
            }

        } else {

            adm_error_report(
                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                2, 93, 29,
                "Pump",
                ent_pump_0000000001->identity,
                "Pumping_fuel_from",
                "Tank");
        }

    } else {

        adm_error_report(
            ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
            2, 92, 29,
            "Delivery",
            ent_delivery->identity,
            "Being_made_using",
            "Pump");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_delivery_calculating_price_of_unconstrained_delivery");
    #endif
}

void adm_state_action_delivery_delivery_complete_state(
    adm_ent_delivery_typ * const ent_delivery)
{
    /* Entity Objects */
    adm_ent_pump_typ * ent_pump_0000000001;
    adm_ent_tank_typ * ent_tank_0000000001;

    /* Relationship Relations */
    adm_rel_delivery_being_made_using_pump_typ * rel_delivery_being_made_using_pump_0000000001;
    adm_rel_pump_pumping_fuel_from_tank_typ * rel_pump_pumping_fuel_from_tank_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_delivery_delivery_complete_state");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_delivery(
        ent_delivery,
        2, 135, 29);

    rel_delivery_being_made_using_pump_0000000001 = ent_delivery->rel_being_made_using_pump_head;

    if (rel_delivery_being_made_using_pump_0000000001 != NULL) {

        ent_pump_0000000001 = rel_delivery_being_made_using_pump_0000000001->ent_pump;

        rel_pump_pumping_fuel_from_tank_0000000001 = ent_pump_0000000001->rel_pumping_fuel_from_tank_head;

        if (rel_pump_pumping_fuel_from_tank_0000000001 != NULL) {

            ent_tank_0000000001 = rel_pump_pumping_fuel_from_tank_0000000001->ent_tank;

            /* GenerateEvent */

            adm_send_event_transaction_create_transaction(
                ent_pump_0000000001->atb_pump_number,
                ent_delivery->atb_cost,
                ent_delivery->atb_timestamp_hours,
                ent_delivery->atb_timestamp_minutes,
                ent_delivery->atb_timestamp_seconds,
                2, 138, 47);

            /* GenerateEvent */

            adm_send_event_tank_fuel_used(
                ent_delivery,
                ent_tank_0000000001,
                ent_delivery->atb_volume_delivered,
                2, 144, 47);

        } else {

            adm_error_report(
                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                2, 136, 29,
                "Pump",
                ent_pump_0000000001->identity,
                "Pumping_fuel_from",
                "Tank");
        }

    } else {

        adm_error_report(
            ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
            2, 135, 29,
            "Delivery",
            ent_delivery->identity,
            "Being_made_using",
            "Pump");
    }

    /* GenerateEvent */

    adm_send_event_delivery_delete_delivery(
        ent_delivery,
        ent_delivery,
        2, 147, 25);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_delivery_delivery_complete_state");
    #endif
}

void adm_state_action_delivery_delivery_cancelled(
    adm_ent_delivery_typ * const ent_delivery)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_delivery_delivery_cancelled");
    #endif

    /* Template */

    adm_write_newline();
    adm_write_str("ATTENDANT~>Delivery_Cancelled");
    adm_write_newline();

    /* GenerateEvent */

    adm_send_event_delivery_delete_delivery(
        ent_delivery,
        ent_delivery,
        2, 174, 25);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_delivery_delivery_cancelled");
    #endif
}

void adm_state_action_delivery_delivery_vanishes(
    adm_ent_delivery_typ * const ent_delivery)
{
    /* Entity Objects */
    adm_ent_pump_typ * ent_pump_0000000001;

    /* Relationship Relations */
    adm_rel_delivery_being_made_using_pump_typ * rel_delivery_being_made_using_pump_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_delivery_delivery_vanishes");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_delivery(
        ent_delivery,
        2, 189, 29);

    rel_delivery_being_made_using_pump_0000000001 = ent_delivery->rel_being_made_using_pump_head;

    if (rel_delivery_being_made_using_pump_0000000001 != NULL) {

        ent_pump_0000000001 = rel_delivery_being_made_using_pump_0000000001->ent_pump;

        /* Unrelate */

        adm_kill_relation_delivery_being_made_using_pump(
            ent_delivery,
            rel_delivery_being_made_using_pump_0000000001,
            2, 192, 33);

    } else {

        adm_error_report(
            ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
            2, 189, 29,
            "Delivery",
            ent_delivery->identity,
            "Being_made_using",
            "Pump");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_delivery_delivery_vanishes");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */