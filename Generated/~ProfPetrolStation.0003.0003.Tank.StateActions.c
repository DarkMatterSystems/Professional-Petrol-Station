
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Tank State Actions */

void adm_state_action_tank_checking_levels_after_tanker_delivery(
    adm_ent_tank_typ * const ent_tank,
    const adm_dst_tank_added_volume_typ * const dst_added_volume)
{
    /* Process Data */
    adm_bln_flag_typ pdt_below_threshold;
    adm_fxd_volume_typ pdt_percent_level;

    /* Entity Objects */
    adm_ent_pump_typ * ent_pump_0000000001;

    /* Relationship Relations */
    adm_rel_tank_providing_fuel_for_pump_typ * rel_tank_providing_fuel_for_pump_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_tank_checking_levels_after_tanker_delivery");
    #endif

    /* Assignment - Evaluation */

    ent_tank->atb_tank_level =
        +(
            +(
                +ent_tank->atb_tank_level
                +
                +dst_added_volume->added_volume
            )
        );

    if (
        ent_tank->atb_tank_level < ADM_TYPE_MINIMUM_VOLUME ||
        ent_tank->atb_tank_level > ADM_TYPE_MAXIMUM_VOLUME) {

        adm_error_report(
            ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
            4, 50, 36,
            "Tank",
            ent_tank->identity,
            "Tank_level",
            adm_sim_lib_fxtoa(ent_tank->atb_tank_level));
    }

    /* Assignment - Evaluation */

    pdt_percent_level =
        +(
            +(
                +(
                    +(
                        +ent_tank->atb_tank_level
                    )
                )
            )
            /
            +(
                +(
                    +(
                        +ent_tank->atb_tank_capacity
                    )
                )
            )
        );

    if (
        pdt_percent_level < ADM_TYPE_MINIMUM_VOLUME ||
        pdt_percent_level > ADM_TYPE_MAXIMUM_VOLUME) {

        adm_error_report(
            ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
            4, 71, 36,
            "percent_level",
            null,
            NULL,
            adm_sim_lib_fxtoa(pdt_percent_level));
    }

    /* CaseSelection */

    if (
        (
            (
                pdt_percent_level < ent_tank->atb_empty_threshold
            )
        )) {

        /* Assignment - Set */

        pdt_below_threshold = TRUE;

    } else {

        /* Assignment - Set */

        pdt_below_threshold = FALSE;
    }

    /* CaseSelection */

    if (
        (
            (
                pdt_below_threshold
            )
        )) {

        /* Assignment - Set */

        ent_tank->atb_tank_empty_flag = TRUE;

        /* GenerateEvent */

        adm_send_event_tank_level_below_threshold(
            ent_tank,
            ent_tank,
            4, 127, 37);

    } else {

        /* Assignment - Set */

        ent_tank->atb_tank_empty_flag = FALSE;

        /* Traverse - TraverseSelection */

        adm_object_existent_tank(
            ent_tank,
            4, 134, 37);

        rel_tank_providing_fuel_for_pump_0000000001 = ent_tank->rel_providing_fuel_for_pump_head;

        while (rel_tank_providing_fuel_for_pump_0000000001 != NULL) {

            ent_pump_0000000001 = rel_tank_providing_fuel_for_pump_0000000001->ent_pump;

            /* GenerateEvent */

            adm_send_event_pump_fuel_available(
                ent_tank,
                ent_pump_0000000001,
                4, 137, 41);

            rel_tank_providing_fuel_for_pump_0000000001 = rel_tank_providing_fuel_for_pump_0000000001->next;
        }

        /* GenerateEvent */

        adm_send_event_tank_level_above_threshold(
            ent_tank,
            ent_tank,
            4, 139, 33);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_tank_checking_levels_after_tanker_delivery");
    #endif
}

void adm_state_action_tank_checking_levels_after_pump_usage(
    adm_ent_tank_typ * const ent_tank,
    const adm_dst_tank_delivered_volume_typ * const dst_delivered_volume)
{
    /* Process Data */
    adm_bln_flag_typ pdt_below_threshold;
    adm_flt_level_typ pdt_percent_level;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_tank_checking_levels_after_pump_usage");
    #endif

    /* Assignment - Evaluation */

    ent_tank->atb_tank_level =
        +(
            +(
                +ent_tank->atb_tank_level
                +
                -dst_delivered_volume->delivered_volume
            )
        );

    if (
        ent_tank->atb_tank_level < ADM_TYPE_MINIMUM_VOLUME ||
        ent_tank->atb_tank_level > ADM_TYPE_MAXIMUM_VOLUME) {

        adm_error_report(
            ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
            4, 197, 36,
            "Tank",
            ent_tank->identity,
            "Tank_level",
            adm_sim_lib_fxtoa(ent_tank->atb_tank_level));
    }

    /* Assignment - Evaluation */

    pdt_percent_level =
        +(
            +(
                +(
                    +(
                        +ent_tank->atb_tank_level
                    )
                )
            )
            /
            +(
                +(
                    +(
                        +ent_tank->atb_tank_capacity
                    )
                )
            )
        );

    if (
        pdt_percent_level < ADM_TYPE_MINIMUM_LEVEL ||
        pdt_percent_level > ADM_TYPE_MAXIMUM_LEVEL) {

        adm_error_report(
            ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
            4, 216, 36,
            "percent_level",
            null,
            NULL,
            adm_sim_lib_fltoa(pdt_percent_level));
    }

    /* CaseSelection */

    if (
        (
            (
                pdt_percent_level < ent_tank->atb_empty_threshold
            )
        )) {

        /* Assignment - Set */

        pdt_below_threshold = TRUE;

    } else {

        /* Assignment - Set */

        pdt_below_threshold = FALSE;
    }

    /* CaseSelection */

    if (
        (
            (
                pdt_below_threshold
            )
        )) {

        /* Assignment - Set */

        ent_tank->atb_tank_empty_flag = TRUE;

        /* GenerateEvent */

        adm_send_event_tank_level_below_threshold(
            ent_tank,
            ent_tank,
            4, 257, 37);

    } else {

        /* GenerateEvent */

        adm_send_event_tank_level_above_threshold(
            ent_tank,
            ent_tank,
            4, 260, 33);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_tank_checking_levels_after_pump_usage");
    #endif
}

void adm_state_action_tank_updating_fuel_levels(
    adm_ent_tank_typ * const ent_tank,
    const adm_dst_tank_delivered_volume_typ * const dst_delivered_volume)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_tank_updating_fuel_levels");
    #endif

    /* Assignment - Evaluation */

    ent_tank->atb_tank_level =
        +(
            +(
                +ent_tank->atb_tank_level
                +
                -dst_delivered_volume->delivered_volume
            )
        );

    if (
        ent_tank->atb_tank_level < ADM_TYPE_MINIMUM_VOLUME ||
        ent_tank->atb_tank_level > ADM_TYPE_MAXIMUM_VOLUME) {

        adm_error_report(
            ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
            4, 284, 36,
            "Tank",
            ent_tank->identity,
            "Tank_level",
            adm_sim_lib_fxtoa(ent_tank->atb_tank_level));
    }

    /* GenerateEvent */

    adm_send_event_tank_level_below_threshold(
        ent_tank,
        ent_tank,
        4, 293, 25);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_tank_updating_fuel_levels");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */