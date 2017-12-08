
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Delivery Simulator Display Entity */

void adm_sim_display_entity_delivery(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_delivery_typ * ent_delivery;

    adm_sim_width_delivery_typ width_delivery;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_delivery");
    #endif

    width_delivery.identity = strlen("Identity");
    width_delivery.status = strlen("Status");
    width_delivery.atb_timestamp_hours = strlen("Timestamp_hours");
    width_delivery.atb_timestamp_minutes = strlen("Timestamp_minutes");
    width_delivery.atb_timestamp_seconds = strlen("Timestamp_seconds");
    width_delivery.atb_volume_delivered = strlen("Volume_delivered");
    width_delivery.atb_cost = strlen("Cost");

    ent_delivery = adm_entity_system.ent_delivery.live_list_head;

    while (ent_delivery != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_delivery->identity);
        if (width > width_delivery.identity) width_delivery.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%s", adm_sim_status_delivery[ent_delivery->status]);
        if (width > width_delivery.status) width_delivery.status = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_delivery->atb_timestamp_hours);
        if (width > width_delivery.atb_timestamp_hours) width_delivery.atb_timestamp_hours = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_delivery->atb_timestamp_minutes);
        if (width > width_delivery.atb_timestamp_minutes) width_delivery.atb_timestamp_minutes = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_delivery->atb_timestamp_seconds);
        if (width > width_delivery.atb_timestamp_seconds) width_delivery.atb_timestamp_seconds = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%f", ent_delivery->atb_volume_delivered);
        if (width > width_delivery.atb_volume_delivered) width_delivery.atb_volume_delivered = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%f", ent_delivery->atb_cost);
        if (width > width_delivery.atb_cost) width_delivery.atb_cost = width;

        ent_delivery = ent_delivery->next;
    }

    printf(NEWLINE);
    printf("Delivery:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_delivery.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_delivery.status, "Status");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_delivery.atb_timestamp_hours, "Timestamp_hours");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_delivery.atb_timestamp_minutes, "Timestamp_minutes");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_delivery.atb_timestamp_seconds, "Timestamp_seconds");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_delivery.atb_volume_delivered, "Volume_delivered");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_delivery.atb_cost, "Cost");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_delivery.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_delivery.status);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_delivery.atb_timestamp_hours);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_delivery.atb_timestamp_minutes);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_delivery.atb_timestamp_seconds);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_delivery.atb_volume_delivered);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_delivery.atb_cost);

    ent_delivery = adm_entity_system.ent_delivery.live_list_head;

    while (ent_delivery != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_delivery.identity, ent_delivery->identity);
        printf(ADM_SIM_COLUMN_GAP);

        switch (ent_delivery->status) {
            case ADM_STATUS_DELIVERY_CREATING_DELIVERY :
                printf("%-*s", width_delivery.status, "Creating_Delivery");
            break;
            case ADM_STATUS_DELIVERY_CALCULATING_PRICE_OF_UNCONSTRAINED_DELIVERY :
                printf("%-*s", width_delivery.status, "Calculating_Price_Of_Unconstrained_Delivery");
            break;
            case ADM_STATUS_DELIVERY_DELIVERY_COMPLETE_STATE :
                printf("%-*s", width_delivery.status, "Delivery_Complete_State");
            break;
            case ADM_STATUS_DELIVERY_DELIVERY_CANCELLED :
                printf("%-*s", width_delivery.status, "Delivery_Cancelled");
            break;
            case ADM_STATUS_DELIVERY_DELIVERY_VANISHES :
                printf("%-*s", width_delivery.status, "Delivery_Vanishes");
            break;
            default :
                printf("%-*s", width_delivery.status, "ERROR");
            break;
        }

        printf(ADM_SIM_COLUMN_GAP);
        printf("%*d", width_delivery.atb_timestamp_hours, ent_delivery->atb_timestamp_hours);
        printf(ADM_SIM_COLUMN_GAP);
        printf("%*d", width_delivery.atb_timestamp_minutes, ent_delivery->atb_timestamp_minutes);
        printf(ADM_SIM_COLUMN_GAP);
        printf("%*d", width_delivery.atb_timestamp_seconds, ent_delivery->atb_timestamp_seconds);
        printf(ADM_SIM_COLUMN_GAP);
        printf("%*f", width_delivery.atb_volume_delivered, ent_delivery->atb_volume_delivered);
        printf(ADM_SIM_COLUMN_GAP);
        printf("%*f", width_delivery.atb_cost, ent_delivery->atb_cost);

        ent_delivery = ent_delivery->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_delivery");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */