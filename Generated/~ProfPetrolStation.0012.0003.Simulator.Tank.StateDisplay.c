
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Simulator Tank Display State */

void adm_sim_display_state_tank_checking_levels_after_tanker_delivery(
    adm_pool_target_tank_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_tank_checking_levels_after_tanker_delivery");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (4:31:30) - Tank[");
        printf("%d", (pool_target->ent_tank)->identity);
        printf("] ");
        printf("Checking_Levels_After_Tanker_Delivery");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_TANK, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_tank[(pool_target->ent_tank)->status]);
        printf("} (");
        printf("Added_volume:");
        printf("%f", (pool_target->dataset.added_volume)->added_volume);
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_tank_checking_levels_after_tanker_delivery");
    #endif
}

void adm_sim_display_state_tank_waiting_for_tanker_delivery(
    adm_pool_target_tank_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_tank_waiting_for_tanker_delivery");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (4:150:26) - Tank[");
        printf("%d", (pool_target->ent_tank)->identity);
        printf("] ");
        printf("Waiting_For_Tanker_Delivery");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_TANK, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_tank[(pool_target->ent_tank)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_tank_waiting_for_tanker_delivery");
    #endif
}

void adm_sim_display_state_tank_reset_waiting_pumps(
    adm_pool_target_tank_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_tank_reset_waiting_pumps");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (4:164:26) - Tank[");
        printf("%d", (pool_target->ent_tank)->identity);
        printf("] ");
        printf("Reset_Waiting_Pumps");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_TANK, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_tank[(pool_target->ent_tank)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_tank_reset_waiting_pumps");
    #endif
}

void adm_sim_display_state_tank_checking_levels_after_pump_usage(
    adm_pool_target_tank_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_tank_checking_levels_after_pump_usage");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (4:178:30) - Tank[");
        printf("%d", (pool_target->ent_tank)->identity);
        printf("] ");
        printf("Checking_Levels_After_Pump_Usage");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_TANK, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_tank[(pool_target->ent_tank)->status]);
        printf("} (");
        printf("Delivered_volume:");
        printf("%f", (pool_target->dataset.delivered_volume)->delivered_volume);
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_tank_checking_levels_after_pump_usage");
    #endif
}

void adm_sim_display_state_tank_updating_fuel_levels(
    adm_pool_target_tank_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_tank_updating_fuel_levels");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (4:271:30) - Tank[");
        printf("%d", (pool_target->ent_tank)->identity);
        printf("] ");
        printf("Updating_Fuel_Levels");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_TANK, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_tank[(pool_target->ent_tank)->status]);
        printf("} (");
        printf("Delivered_volume:");
        printf("%f", (pool_target->dataset.delivered_volume)->delivered_volume);
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_tank_updating_fuel_levels");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */