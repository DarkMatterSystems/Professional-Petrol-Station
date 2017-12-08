
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Pump Simulator Display Entity */

void adm_sim_display_entity_pump(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_pump_typ * ent_pump;

    adm_sim_width_pump_typ width_pump;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_pump");
    #endif

    width_pump.identity = strlen("Identity");
    width_pump.status = strlen("Status");
    width_pump.atb_pump_number = strlen("Pump_number");

    ent_pump = adm_entity_system.ent_pump.live_list_head;

    while (ent_pump != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_pump->identity);
        if (width > width_pump.identity) width_pump.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%s", adm_sim_status_pump[ent_pump->status]);
        if (width > width_pump.status) width_pump.status = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_pump->atb_pump_number);
        if (width > width_pump.atb_pump_number) width_pump.atb_pump_number = width;

        ent_pump = ent_pump->next;
    }

    printf(NEWLINE);
    printf("Pump:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_pump.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_pump.status, "Status");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_pump.atb_pump_number, "Pump_number");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_pump.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_pump.status);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_pump.atb_pump_number);

    ent_pump = adm_entity_system.ent_pump.live_list_head;

    while (ent_pump != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_pump.identity, ent_pump->identity);
        printf(ADM_SIM_COLUMN_GAP);

        switch (ent_pump->status) {
            case ADM_STATUS_PUMP_WAITING_FOR_CUSTOMER :
                printf("%-*s", width_pump.status, "Waiting_For_Customer");
            break;
            case ADM_STATUS_PUMP_WAITING_PUMP_ENABLE :
                printf("%-*s", width_pump.status, "Waiting_Pump_Enable");
            break;
            case ADM_STATUS_PUMP_FUEL_UNAVAILABLE :
                printf("%-*s", width_pump.status, "Fuel_Unavailable");
            break;
            case ADM_STATUS_PUMP_FUEL_DELIVERY_COMPLETE :
                printf("%-*s", width_pump.status, "Fuel_Delivery_Complete");
            break;
            case ADM_STATUS_PUMP_READY_TO_PUMP :
                printf("%-*s", width_pump.status, "Ready_To_Pump");
            break;
            case ADM_STATUS_PUMP_PUMPING_PAUSED :
                printf("%-*s", width_pump.status, "Pumping_Paused");
            break;
            case ADM_STATUS_PUMP_PUMPING :
                printf("%-*s", width_pump.status, "Pumping");
            break;
            default :
                printf("%-*s", width_pump.status, "ERROR");
            break;
        }

        printf(ADM_SIM_COLUMN_GAP);
        printf("%*d", width_pump.atb_pump_number, ent_pump->atb_pump_number);

        ent_pump = ent_pump->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_pump");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */