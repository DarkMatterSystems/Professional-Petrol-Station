
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Simulator Tank Display Event */

void adm_sim_display_event_tank_level_below_threshold(
    const adm_ent_tank_typ * const ent_tank,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_tank_level_below_threshold");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.events) {

        printf(NEWLINE);

        if (error_file != ADM_SIM_MATRIX_SCRIPT_EVENT) {

            printf(ADM_SIM_INDENT);
            printf(ADM_SIM_INDENT);
        }

        printf("EVENT (");
        printf("%d:%d:%d)", error_file, error_line, error_rank);
        printf(" - Tank[");
        printf("%d", ent_tank->identity);
        printf("] Level_below_threshold (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_tank_level_below_threshold");
    #endif
}

void adm_sim_display_event_tank_level_above_threshold(
    const adm_ent_tank_typ * const ent_tank,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_tank_level_above_threshold");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.events) {

        printf(NEWLINE);

        if (error_file != ADM_SIM_MATRIX_SCRIPT_EVENT) {

            printf(ADM_SIM_INDENT);
            printf(ADM_SIM_INDENT);
        }

        printf("EVENT (");
        printf("%d:%d:%d)", error_file, error_line, error_rank);
        printf(" - Tank[");
        printf("%d", ent_tank->identity);
        printf("] Level_above_threshold (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_tank_level_above_threshold");
    #endif
}

void adm_sim_display_event_tank_tanker_delivery(
    const adm_ent_tank_typ * const ent_tank,
    const adm_fxd_volume_typ evd_added_volume,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_tank_tanker_delivery");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.events) {

        printf(NEWLINE);

        if (error_file != ADM_SIM_MATRIX_SCRIPT_EVENT) {

            printf(ADM_SIM_INDENT);
            printf(ADM_SIM_INDENT);
        }

        printf("EVENT (");
        printf("%d:%d:%d)", error_file, error_line, error_rank);
        printf(" - Tank[");
        printf("%d", ent_tank->identity);
        printf("] Tanker_delivery (");
        printf("Added_volume:%f", evd_added_volume);
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_tank_tanker_delivery");
    #endif
}

void adm_sim_display_event_tank_fuel_used(
    const adm_ent_tank_typ * const ent_tank,
    const adm_fxd_volume_typ evd_delivered_volume,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_tank_fuel_used");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.events) {

        printf(NEWLINE);

        if (error_file != ADM_SIM_MATRIX_SCRIPT_EVENT) {

            printf(ADM_SIM_INDENT);
            printf(ADM_SIM_INDENT);
        }

        printf("EVENT (");
        printf("%d:%d:%d)", error_file, error_line, error_rank);
        printf(" - Tank[");
        printf("%d", ent_tank->identity);
        printf("] Fuel_used (");
        printf("Delivered_volume:%f", evd_delivered_volume);
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_tank_fuel_used");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */