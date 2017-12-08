
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Simulator Delivery Display State */

void adm_sim_display_state_delivery_creating_delivery(
    adm_pool_target_delivery_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_delivery_creating_delivery");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (2:30:31) - Delivery[");
        printf("%d", (pool_target->ent_delivery)->identity);
        printf("] ");
        printf("Creating_Delivery");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_DELIVERY, pool_target->evente));
        printf("} (");
        printf("Pump_number:");
        printf("%d", (pool_target->dataset.pump_number)->pump_number);
        printf(", ");
        printf("Timestamp_hours:");
        printf("%d", (pool_target->dataset.pump_number)->timestamp_hours);
        printf(", ");
        printf("Timestamp_minutes:");
        printf("%d", (pool_target->dataset.pump_number)->timestamp_minutes);
        printf(", ");
        printf("Timestamp_seconds:");
        printf("%d", (pool_target->dataset.pump_number)->timestamp_seconds);
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_delivery_creating_delivery");
    #endif
}

void adm_sim_display_state_delivery_calculating_price_of_unconstrained_delivery(
    adm_pool_target_delivery_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_delivery_calculating_price_of_unconstrained_delivery");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (2:77:26) - Delivery[");
        printf("%d", (pool_target->ent_delivery)->identity);
        printf("] ");
        printf("Calculating_Price_Of_Unconstrained_Delivery");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_DELIVERY, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_delivery[(pool_target->ent_delivery)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_delivery_calculating_price_of_unconstrained_delivery");
    #endif
}

void adm_sim_display_state_delivery_delivery_complete_state(
    adm_pool_target_delivery_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_delivery_delivery_complete_state");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (2:118:26) - Delivery[");
        printf("%d", (pool_target->ent_delivery)->identity);
        printf("] ");
        printf("Delivery_Complete_State");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_DELIVERY, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_delivery[(pool_target->ent_delivery)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_delivery_delivery_complete_state");
    #endif
}

void adm_sim_display_state_delivery_delivery_cancelled(
    adm_pool_target_delivery_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_delivery_delivery_cancelled");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (2:158:26) - Delivery[");
        printf("%d", (pool_target->ent_delivery)->identity);
        printf("] ");
        printf("Delivery_Cancelled");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_DELIVERY, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_delivery[(pool_target->ent_delivery)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_delivery_delivery_cancelled");
    #endif
}

void adm_sim_display_state_delivery_delivery_vanishes(
    adm_pool_target_delivery_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_delivery_delivery_vanishes");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (2:185:27) - Delivery[");
        printf("%d", (pool_target->ent_delivery)->identity);
        printf("] ");
        printf("Delivery_Vanishes");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_DELIVERY, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_delivery[(pool_target->ent_delivery)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_delivery_delivery_vanishes");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */