
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Transaction State Actions */

void adm_state_action_transaction_creating_pending_transaction(
    adm_ent_transaction_typ * const ent_transaction,
    const adm_dst_transaction_creation_data_typ * const dst_creation_data)
{
    /* Entity Objects */
    adm_ent_transaction_policy_typ * ent_transaction_policy_0000000001;
    adm_ent_transaction_policy_typ * ent_transaction_policy_0000000002;
    adm_ent_pending_transaction_typ * ent_pending_transaction_0000000003;
    adm_ent_pump_typ * ent_pump_0000000004;
    adm_ent_pump_typ * nxt_pump_0000000004;

    /* Relationship Relations */
    adm_rel_transaction_governed_by_transaction_policy_typ * rel_transaction_governed_by_transaction_policy_0000000002;

    /* Identifier Flags */
    adm_base_boolean_typ identifier_not_found_0000000004;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_transaction_creating_pending_transaction");
    #endif

    /* EntitySelection - Selection */

    ent_transaction_policy_0000000001 = adm_entity_system.ent_transaction_policy.live_list_head;

    while (ent_transaction_policy_0000000001 != NULL) {

        /* Relate */

        adm_link_relation_transaction_governed_by_transaction_policy(
            ent_transaction,
            ent_transaction_policy_0000000001,
            5, 51, 33);

        ent_transaction_policy_0000000001 = ent_transaction_policy_0000000001->next;
    }

    /* Traverse - TraverseSelection */

    adm_object_existent_transaction(
        ent_transaction,
        5, 54, 29);

    rel_transaction_governed_by_transaction_policy_0000000002 = ent_transaction->rel_governed_by_transaction_policy_head;

    if (rel_transaction_governed_by_transaction_policy_0000000002 != NULL) {

        ent_transaction_policy_0000000002 = rel_transaction_governed_by_transaction_policy_0000000002->ent_transaction_policy;

        /* Assignment - Set */

        if (
            ent_transaction_policy_0000000002->atb_next_transaction_number < ADM_TYPE_MINIMUM_BUSINESS_NUMBER ||
            ent_transaction_policy_0000000002->atb_next_transaction_number > ADM_TYPE_MAXIMUM_BUSINESS_NUMBER) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                5, 58, 37,
                "Transaction",
                ent_transaction->identity,
                "Transaction_number",
                adm_sim_lib_itoa(ent_transaction_policy_0000000002->atb_next_transaction_number));
        }

        ent_transaction->atb_transaction_number = +ent_transaction_policy_0000000002->atb_next_transaction_number;

        /* Assignment - Set */

        if (
            dst_creation_data->delivery_time_hours < ADM_TYPE_MINIMUM_TIME_HOUR ||
            dst_creation_data->delivery_time_hours > ADM_TYPE_MAXIMUM_TIME_HOUR) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                5, 59, 37,
                "Transaction",
                ent_transaction->identity,
                "Delivery_time_hours",
                adm_sim_lib_itoa(dst_creation_data->delivery_time_hours));
        }

        ent_transaction->atb_delivery_time_hours = +dst_creation_data->delivery_time_hours;

        /* Assignment - Set */

        if (
            dst_creation_data->delivery_time_minutes < ADM_TYPE_MINIMUM_TIME_MINUTE ||
            dst_creation_data->delivery_time_minutes > ADM_TYPE_MAXIMUM_TIME_MINUTE) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                5, 60, 37,
                "Transaction",
                ent_transaction->identity,
                "Delivery_time_minutes",
                adm_sim_lib_itoa(dst_creation_data->delivery_time_minutes));
        }

        ent_transaction->atb_delivery_time_minutes = +dst_creation_data->delivery_time_minutes;

        /* Assignment - Set */

        if (
            dst_creation_data->delivery_time_seconds < ADM_TYPE_MINIMUM_TIME_SECOND ||
            dst_creation_data->delivery_time_seconds > ADM_TYPE_MAXIMUM_TIME_SECOND) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                5, 61, 37,
                "Transaction",
                ent_transaction->identity,
                "Delivery_time_seconds",
                adm_sim_lib_itoa(dst_creation_data->delivery_time_seconds));
        }

        ent_transaction->atb_delivery_time_seconds = +dst_creation_data->delivery_time_seconds;

        /* Assignment - Set */

        if (
            dst_creation_data->delivery_cost < ADM_TYPE_MINIMUM_MONEY ||
            dst_creation_data->delivery_cost > ADM_TYPE_MAXIMUM_MONEY) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                5, 63, 37,
                "Transaction",
                ent_transaction->identity,
                "Cost",
                adm_sim_lib_fxtoa(dst_creation_data->delivery_cost));
        }

        ent_transaction->atb_cost = +dst_creation_data->delivery_cost;

        /* Assignment - Evaluation */

        ent_transaction_policy_0000000002->atb_next_transaction_number =
            +(
                +(
                    +ent_transaction_policy_0000000002->atb_next_transaction_number
                    +
                    1
                )
            );

        if (
            ent_transaction_policy_0000000002->atb_next_transaction_number < ADM_TYPE_MINIMUM_BUSINESS_NUMBER ||
            ent_transaction_policy_0000000002->atb_next_transaction_number > ADM_TYPE_MAXIMUM_BUSINESS_NUMBER) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                5, 64, 44,
                "Transaction_Policy",
                ent_transaction_policy_0000000002->identity,
                "Next_transaction_number",
                adm_sim_lib_itoa(ent_transaction_policy_0000000002->atb_next_transaction_number));
        }

    } else {

        adm_error_report(
            ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
            5, 54, 29,
            "Transaction",
            ent_transaction->identity,
            "Governed_by",
            "Transaction_Policy");
    }

    /* Create */

    ent_pending_transaction_0000000003 = adm_make_object_pending_transaction();

    /* Relate */

    adm_link_relation_transaction_generalisation_pending_transaction(
        ent_transaction,
        ent_pending_transaction_0000000003,
        5, 76, 29);

    /* IdentifierSelection */

    identifier_not_found_0000000004 = TRUE;

    ent_pump_0000000004 = adm_entity_system.ent_pump.live_list_head;

    while (
        identifier_not_found_0000000004 &&
        ent_pump_0000000004 != NULL) {

        nxt_pump_0000000004 = ent_pump_0000000004->next;

        if (
            ent_pump_0000000004->atb_pump_number == dst_creation_data->delivery_pump) {

            identifier_not_found_0000000004 = FALSE;

            /* Relate */

            adm_link_relation_pending_transaction_pending_for_pump(
                ent_pending_transaction_0000000003,
                ent_pump_0000000004,
                5, 88, 37);
        }

        ent_pump_0000000004 = nxt_pump_0000000004;
    }

    adm_bind_object_pending_transaction(
        ent_pending_transaction_0000000003,
        5, 74, 35);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_transaction_creating_pending_transaction");
    #endif
}

void adm_state_action_transaction_paid_state(
    adm_ent_transaction_typ * const ent_transaction)
{
    /* Entity Objects */
    adm_ent_pending_transaction_typ * ent_pending_transaction_0000000001;
    adm_ent_pump_typ * ent_pump_0000000001;
    adm_ent_evaded_transaction_typ * ent_evaded_transaction_0000000003;
    adm_ent_paid_transaction_typ * ent_paid_transaction_0000000004;

    /* Relationship Relations */
    adm_rel_transaction_generalisation_pending_transaction_typ * rel_transaction_generalisation_pending_transaction_0000000001;
    adm_rel_pending_transaction_pending_for_pump_typ * rel_pending_transaction_pending_for_pump_0000000001;
    adm_rel_transaction_generalisation_evaded_transaction_typ * rel_transaction_generalisation_evaded_transaction_0000000003;

    /* Traverse Null Selection Flags */
    adm_base_boolean_typ traverse_not_found_0000000002;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_transaction_paid_state");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_transaction(
        ent_transaction,
        5, 121, 29);

    traverse_not_found_0000000002 = TRUE;

    rel_transaction_generalisation_pending_transaction_0000000001 = ent_transaction->rel_generalisation_pending_transaction_head;

    if (rel_transaction_generalisation_pending_transaction_0000000001 != NULL) {

        ent_pending_transaction_0000000001 = rel_transaction_generalisation_pending_transaction_0000000001->ent_pending_transaction;

        rel_pending_transaction_pending_for_pump_0000000001 = ent_pending_transaction_0000000001->rel_pending_for_pump_head;

        if (rel_pending_transaction_pending_for_pump_0000000001 != NULL) {

            ent_pump_0000000001 = rel_pending_transaction_pending_for_pump_0000000001->ent_pump;

            traverse_not_found_0000000002 = FALSE;

            /* Unrelate */

            adm_kill_relation_transaction_generalisation_pending_transaction(
                ent_transaction,
                rel_transaction_generalisation_pending_transaction_0000000001,
                5, 125, 33);

            /* Unrelate */

            adm_kill_relation_pending_transaction_pending_for_pump(
                ent_pending_transaction_0000000001,
                rel_pending_transaction_pending_for_pump_0000000001,
                5, 126, 33);

            /* Delete */

            adm_kill_object_pending_transaction(
                ent_transaction,
                ent_pending_transaction_0000000001,
                5, 128, 33);

        } else {

            adm_error_report(
                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                5, 122, 29,
                "Pending_Transaction",
                ent_pending_transaction_0000000001->identity,
                "Pending_for",
                "Pump");
        }
    }

    /* Traverse - Null Traverse Selection */

    if (traverse_not_found_0000000002) {

        /* Traverse - TraverseSelection */

        adm_object_existent_transaction(
            ent_transaction,
            5, 132, 37);

        rel_transaction_generalisation_evaded_transaction_0000000003 = ent_transaction->rel_generalisation_evaded_transaction_head;

        if (rel_transaction_generalisation_evaded_transaction_0000000003 != NULL) {

            ent_evaded_transaction_0000000003 = rel_transaction_generalisation_evaded_transaction_0000000003->ent_evaded_transaction;

            /* Unrelate */

            adm_kill_relation_transaction_generalisation_evaded_transaction(
                ent_transaction,
                rel_transaction_generalisation_evaded_transaction_0000000003,
                5, 135, 41);

            /* Delete */

            adm_kill_object_evaded_transaction(
                ent_transaction,
                ent_evaded_transaction_0000000003,
                5, 137, 41);
        }
    }

    /* Create */

    ent_paid_transaction_0000000004 = adm_make_object_paid_transaction();

    /* Relate */

    adm_link_relation_transaction_generalisation_paid_transaction(
        ent_transaction,
        ent_paid_transaction_0000000004,
        5, 147, 29);

    adm_bind_object_paid_transaction(
        ent_paid_transaction_0000000004,
        5, 145, 35);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_transaction_paid_state");
    #endif
}

void adm_state_action_transaction_evaded_state(
    adm_ent_transaction_typ * const ent_transaction,
    const adm_dst_transaction_customer_details_typ * const dst_customer_details)
{
    /* Entity Objects */
    adm_ent_pending_transaction_typ * ent_pending_transaction_0000000001;
    adm_ent_pump_typ * ent_pump_0000000001;
    adm_ent_evaded_transaction_typ * ent_evaded_transaction_0000000002;

    /* Relationship Relations */
    adm_rel_transaction_generalisation_pending_transaction_typ * rel_transaction_generalisation_pending_transaction_0000000001;
    adm_rel_pending_transaction_pending_for_pump_typ * rel_pending_transaction_pending_for_pump_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_transaction_evaded_state");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_transaction(
        ent_transaction,
        5, 172, 29);

    rel_transaction_generalisation_pending_transaction_0000000001 = ent_transaction->rel_generalisation_pending_transaction_head;

    if (rel_transaction_generalisation_pending_transaction_0000000001 != NULL) {

        ent_pending_transaction_0000000001 = rel_transaction_generalisation_pending_transaction_0000000001->ent_pending_transaction;

        rel_pending_transaction_pending_for_pump_0000000001 = ent_pending_transaction_0000000001->rel_pending_for_pump_head;

        if (rel_pending_transaction_pending_for_pump_0000000001 != NULL) {

            ent_pump_0000000001 = rel_pending_transaction_pending_for_pump_0000000001->ent_pump;

            /* Unrelate */

            adm_kill_relation_transaction_generalisation_pending_transaction(
                ent_transaction,
                rel_transaction_generalisation_pending_transaction_0000000001,
                5, 176, 33);

            /* Unrelate */

            adm_kill_relation_pending_transaction_pending_for_pump(
                ent_pending_transaction_0000000001,
                rel_pending_transaction_pending_for_pump_0000000001,
                5, 177, 33);

            /* Delete */

            adm_kill_object_pending_transaction(
                ent_transaction,
                ent_pending_transaction_0000000001,
                5, 179, 33);

        } else {

            adm_error_report(
                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                5, 173, 29,
                "Pending_Transaction",
                ent_pending_transaction_0000000001->identity,
                "Pending_for",
                "Pump");
        }
    }

    /* Create */

    ent_evaded_transaction_0000000002 = adm_make_object_evaded_transaction();

    /* Assignment - Set */

    if (strlen(dst_customer_details->customer_details) > ADM_TYPE_SIZE_TEXT) {

        adm_error_report(
            ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
            5, 192, 33,
            "Evaded_Transaction",
            ent_evaded_transaction_0000000002->identity,
            "Observations",
            dst_customer_details->customer_details);
    }

    strcpy_s(
        ent_evaded_transaction_0000000002->atb_observations, 
        ADM_TYPE_SIZE_TEXT+1, 
        dst_customer_details->customer_details);

    /* Relate */

    adm_link_relation_transaction_generalisation_evaded_transaction(
        ent_transaction,
        ent_evaded_transaction_0000000002,
        5, 194, 29);

    adm_bind_object_evaded_transaction(
        ent_evaded_transaction_0000000002,
        5, 189, 35);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_transaction_evaded_state");
    #endif
}

void adm_state_action_transaction_transaction_vanishes(
    adm_ent_transaction_typ * const ent_transaction)
{
    /* Entity Objects */
    adm_ent_paid_transaction_typ * ent_paid_transaction_0000000001;

    /* Relationship Relations */
    adm_rel_transaction_generalisation_paid_transaction_typ * rel_transaction_generalisation_paid_transaction_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_transaction_transaction_vanishes");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_transaction(
        ent_transaction,
        5, 213, 29);

    rel_transaction_generalisation_paid_transaction_0000000001 = ent_transaction->rel_generalisation_paid_transaction_head;

    if (rel_transaction_generalisation_paid_transaction_0000000001 != NULL) {

        ent_paid_transaction_0000000001 = rel_transaction_generalisation_paid_transaction_0000000001->ent_paid_transaction;

        /* Unrelate */

        adm_kill_relation_transaction_generalisation_paid_transaction(
            ent_transaction,
            rel_transaction_generalisation_paid_transaction_0000000001,
            5, 216, 33);

        /* Delete */

        adm_kill_object_paid_transaction(
            ent_transaction,
            ent_paid_transaction_0000000001,
            5, 218, 33);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_transaction_transaction_vanishes");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */