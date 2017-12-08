
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Transaction Simulator Display Entity */

void adm_sim_display_entity_transaction(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_transaction_typ * ent_transaction;

    adm_sim_width_transaction_typ width_transaction;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_transaction");
    #endif

    width_transaction.identity = strlen("Identity");
    width_transaction.status = strlen("Status");
    width_transaction.atb_transaction_number = strlen("Transaction_number");
    width_transaction.atb_cost = strlen("Cost");
    width_transaction.atb_delivery_time_hours = strlen("Delivery_time_hours");
    width_transaction.atb_delivery_time_minutes = strlen("Delivery_time_minutes");
    width_transaction.atb_delivery_time_seconds = strlen("Delivery_time_seconds");

    ent_transaction = adm_entity_system.ent_transaction.live_list_head;

    while (ent_transaction != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_transaction->identity);
        if (width > width_transaction.identity) width_transaction.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%s", adm_sim_status_transaction[ent_transaction->status]);
        if (width > width_transaction.status) width_transaction.status = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_transaction->atb_transaction_number);
        if (width > width_transaction.atb_transaction_number) width_transaction.atb_transaction_number = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%f", ent_transaction->atb_cost);
        if (width > width_transaction.atb_cost) width_transaction.atb_cost = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_transaction->atb_delivery_time_hours);
        if (width > width_transaction.atb_delivery_time_hours) width_transaction.atb_delivery_time_hours = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_transaction->atb_delivery_time_minutes);
        if (width > width_transaction.atb_delivery_time_minutes) width_transaction.atb_delivery_time_minutes = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_transaction->atb_delivery_time_seconds);
        if (width > width_transaction.atb_delivery_time_seconds) width_transaction.atb_delivery_time_seconds = width;

        ent_transaction = ent_transaction->next;
    }

    printf(NEWLINE);
    printf("Transaction:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_transaction.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_transaction.status, "Status");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_transaction.atb_transaction_number, "Transaction_number");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_transaction.atb_cost, "Cost");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_transaction.atb_delivery_time_hours, "Delivery_time_hours");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_transaction.atb_delivery_time_minutes, "Delivery_time_minutes");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_transaction.atb_delivery_time_seconds, "Delivery_time_seconds");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_transaction.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_transaction.status);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_transaction.atb_transaction_number);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_transaction.atb_cost);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_transaction.atb_delivery_time_hours);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_transaction.atb_delivery_time_minutes);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_transaction.atb_delivery_time_seconds);

    ent_transaction = adm_entity_system.ent_transaction.live_list_head;

    while (ent_transaction != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_transaction.identity, ent_transaction->identity);
        printf(ADM_SIM_COLUMN_GAP);

        switch (ent_transaction->status) {
            case ADM_STATUS_TRANSACTION_CREATING_PENDING_TRANSACTION :
                printf("%-*s", width_transaction.status, "Creating_Pending_Transaction");
            break;
            case ADM_STATUS_TRANSACTION_PAID_STATE :
                printf("%-*s", width_transaction.status, "Paid_State");
            break;
            case ADM_STATUS_TRANSACTION_EVADED_STATE :
                printf("%-*s", width_transaction.status, "Evaded_State");
            break;
            case ADM_STATUS_TRANSACTION_TRANSACTION_VANISHES :
                printf("%-*s", width_transaction.status, "Transaction_Vanishes");
            break;
            default :
                printf("%-*s", width_transaction.status, "ERROR");
            break;
        }

        printf(ADM_SIM_COLUMN_GAP);
        printf("%*d", width_transaction.atb_transaction_number, ent_transaction->atb_transaction_number);
        printf(ADM_SIM_COLUMN_GAP);
        printf("%*f", width_transaction.atb_cost, ent_transaction->atb_cost);
        printf(ADM_SIM_COLUMN_GAP);
        printf("%*d", width_transaction.atb_delivery_time_hours, ent_transaction->atb_delivery_time_hours);
        printf(ADM_SIM_COLUMN_GAP);
        printf("%*d", width_transaction.atb_delivery_time_minutes, ent_transaction->atb_delivery_time_minutes);
        printf(ADM_SIM_COLUMN_GAP);
        printf("%*d", width_transaction.atb_delivery_time_seconds, ent_transaction->atb_delivery_time_seconds);

        ent_transaction = ent_transaction->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_transaction");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */