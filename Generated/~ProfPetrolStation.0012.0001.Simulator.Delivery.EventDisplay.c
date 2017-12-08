
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Simulator Delivery Display Event */

void adm_sim_display_event_delivery_fuel_unit_delivered(
    const adm_ent_delivery_typ * const ent_delivery,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_delivery_fuel_unit_delivered");
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
        printf(" - Delivery[");
        printf("%d", ent_delivery->identity);
        printf("] Fuel_unit_delivered (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_delivery_fuel_unit_delivered");
    #endif
}

void adm_sim_display_event_delivery_delivery_complete(
    const adm_ent_delivery_typ * const ent_delivery,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_delivery_delivery_complete");
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
        printf(" - Delivery[");
        printf("%d", ent_delivery->identity);
        printf("] Delivery_complete (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_delivery_delivery_complete");
    #endif
}

void adm_sim_display_event_delivery_delete_delivery(
    const adm_ent_delivery_typ * const ent_delivery,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_delivery_delete_delivery");
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
        printf(" - Delivery[");
        printf("%d", ent_delivery->identity);
        printf("] Delete_delivery (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_delivery_delete_delivery");
    #endif
}

void adm_sim_display_event_delivery_create_delivery(
    const adm_int_equipment_number_typ evd_pump_number,
    const adm_int_time_hour_typ evd_timestamp_hours,
    const adm_int_time_minute_typ evd_timestamp_minutes,
    const adm_int_time_second_typ evd_timestamp_seconds,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_delivery_create_delivery");
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
        printf(" - Delivery[");
        printf("] Create_delivery (");
        printf("Pump_number:%d", evd_pump_number);
        printf(", ");
        printf("Timestamp_hours:%d", evd_timestamp_hours);
        printf(", ");
        printf("Timestamp_minutes:%d", evd_timestamp_minutes);
        printf(", ");
        printf("Timestamp_seconds:%d", evd_timestamp_seconds);
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_delivery_create_delivery");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */