
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Simulator Transaction Display State */

void adm_sim_display_state_transaction_creating_pending_transaction(
    adm_pool_target_transaction_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_transaction_creating_pending_transaction");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (5:37:31) - Transaction[");
        printf("%d", (pool_target->ent_transaction)->identity);
        printf("] ");
        printf("Creating_Pending_Transaction");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_TRANSACTION, pool_target->evente));
        printf("} (");
        printf("Delivery_pump:");
        printf("%d", (pool_target->dataset.creation_data)->delivery_pump);
        printf(", ");
        printf("Delivery_cost:");
        printf("%f", (pool_target->dataset.creation_data)->delivery_cost);
        printf(", ");
        printf("Delivery_time_hours:");
        printf("%d", (pool_target->dataset.creation_data)->delivery_time_hours);
        printf(", ");
        printf("Delivery_time_minutes:");
        printf("%d", (pool_target->dataset.creation_data)->delivery_time_minutes);
        printf(", ");
        printf("Delivery_time_seconds:");
        printf("%d", (pool_target->dataset.creation_data)->delivery_time_seconds);
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_transaction_creating_pending_transaction");
    #endif
}

void adm_sim_display_state_transaction_paid_state(
    adm_pool_target_transaction_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_transaction_paid_state");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (5:99:26) - Transaction[");
        printf("%d", (pool_target->ent_transaction)->identity);
        printf("] ");
        printf("Paid_State");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_TRANSACTION, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_transaction[(pool_target->ent_transaction)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_transaction_paid_state");
    #endif
}

void adm_sim_display_state_transaction_evaded_state(
    adm_pool_target_transaction_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_transaction_evaded_state");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (5:158:30) - Transaction[");
        printf("%d", (pool_target->ent_transaction)->identity);
        printf("] ");
        printf("Evaded_State");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_TRANSACTION, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_transaction[(pool_target->ent_transaction)->status]);
        printf("} (");
        printf("Customer_details:");
        printf("\"%s\"", (pool_target->dataset.customer_details)->customer_details);
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_transaction_evaded_state");
    #endif
}

void adm_sim_display_state_transaction_transaction_vanishes(
    adm_pool_target_transaction_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_transaction_transaction_vanishes");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (5:206:27) - Transaction[");
        printf("%d", (pool_target->ent_transaction)->identity);
        printf("] ");
        printf("Transaction_Vanishes");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_TRANSACTION, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_transaction[(pool_target->ent_transaction)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_transaction_transaction_vanishes");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */