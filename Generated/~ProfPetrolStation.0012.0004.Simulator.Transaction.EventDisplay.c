
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Simulator Transaction Display Event */

void adm_sim_display_event_transaction_payment_received(
    const adm_ent_transaction_typ * const ent_transaction,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_transaction_payment_received");
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
        printf(" - Transaction[");
        printf("%d", ent_transaction->identity);
        printf("] Payment_received (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_transaction_payment_received");
    #endif
}

void adm_sim_display_event_transaction_customer_absconds(
    const adm_ent_transaction_typ * const ent_transaction,
    const adm_str_text_typ * const evd_customer_details,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_transaction_customer_absconds");
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
        printf(" - Transaction[");
        printf("%d", ent_transaction->identity);
        printf("] Customer_absconds (");
        printf("Customer_details:\"%s\"", evd_customer_details);
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_transaction_customer_absconds");
    #endif
}

void adm_sim_display_event_transaction_create_transaction(
    const adm_int_equipment_number_typ evd_delivery_pump,
    const adm_fxd_money_typ evd_delivery_cost,
    const adm_int_time_hour_typ evd_delivery_time_hours,
    const adm_int_time_minute_typ evd_delivery_time_minutes,
    const adm_int_time_second_typ evd_delivery_time_seconds,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_transaction_create_transaction");
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
        printf(" - Transaction[");
        printf("] Create_transaction (");
        printf("Delivery_pump:%d", evd_delivery_pump);
        printf(", ");
        printf("Delivery_cost:%f", evd_delivery_cost);
        printf(", ");
        printf("Delivery_time_hours:%d", evd_delivery_time_hours);
        printf(", ");
        printf("Delivery_time_minutes:%d", evd_delivery_time_minutes);
        printf(", ");
        printf("Delivery_time_seconds:%d", evd_delivery_time_seconds);
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_transaction_create_transaction");
    #endif
}

void adm_sim_display_event_transaction_close_transaction(
    const adm_ent_transaction_typ * const ent_transaction,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_transaction_close_transaction");
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
        printf(" - Transaction[");
        printf("%d", ent_transaction->identity);
        printf("] Close_transaction (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_transaction_close_transaction");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */