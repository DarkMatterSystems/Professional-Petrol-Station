
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Simulator Pump Display State */

void adm_sim_display_state_pump_waiting_for_customer(
    adm_pool_target_pump_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_pump_waiting_for_customer");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (3:21:26) - Pump[");
        printf("%d", (pool_target->ent_pump)->identity);
        printf("] ");
        printf("Waiting_For_Customer");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_PUMP, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_pump[(pool_target->ent_pump)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_pump_waiting_for_customer");
    #endif
}

void adm_sim_display_state_pump_waiting_pump_enable(
    adm_pool_target_pump_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_pump_waiting_pump_enable");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (3:40:26) - Pump[");
        printf("%d", (pool_target->ent_pump)->identity);
        printf("] ");
        printf("Waiting_Pump_Enable");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_PUMP, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_pump[(pool_target->ent_pump)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_pump_waiting_pump_enable");
    #endif
}

void adm_sim_display_state_pump_fuel_unavailable(
    adm_pool_target_pump_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_pump_fuel_unavailable");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (3:84:26) - Pump[");
        printf("%d", (pool_target->ent_pump)->identity);
        printf("] ");
        printf("Fuel_Unavailable");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_PUMP, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_pump[(pool_target->ent_pump)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_pump_fuel_unavailable");
    #endif
}

void adm_sim_display_state_pump_fuel_delivery_complete(
    adm_pool_target_pump_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_pump_fuel_delivery_complete");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (3:108:26) - Pump[");
        printf("%d", (pool_target->ent_pump)->identity);
        printf("] ");
        printf("Fuel_Delivery_Complete");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_PUMP, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_pump[(pool_target->ent_pump)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_pump_fuel_delivery_complete");
    #endif
}

void adm_sim_display_state_pump_ready_to_pump(
    adm_pool_target_pump_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_pump_ready_to_pump");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (3:145:26) - Pump[");
        printf("%d", (pool_target->ent_pump)->identity);
        printf("] ");
        printf("Ready_To_Pump");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_PUMP, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_pump[(pool_target->ent_pump)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_pump_ready_to_pump");
    #endif
}

void adm_sim_display_state_pump_pumping_paused(
    adm_pool_target_pump_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_pump_pumping_paused");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (3:169:26) - Pump[");
        printf("%d", (pool_target->ent_pump)->identity);
        printf("] ");
        printf("Pumping_Paused");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_PUMP, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_pump[(pool_target->ent_pump)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_pump_pumping_paused");
    #endif
}

void adm_sim_display_state_pump_pumping(
    adm_pool_target_pump_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_pump_pumping");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (3:195:26) - Pump[");
        printf("%d", (pool_target->ent_pump)->identity);
        printf("] ");
        printf("Pumping");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_PUMP, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_pump[(pool_target->ent_pump)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_pump_pumping");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */