
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Tank Simulator Display Entity */

void adm_sim_display_entity_tank(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_tank_typ * ent_tank;

    adm_sim_width_tank_typ width_tank;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_tank");
    #endif

    width_tank.identity = strlen("Identity");
    width_tank.status = strlen("Status");
    width_tank.atb_tank_number = strlen("Tank_number");
    width_tank.atb_tank_empty_flag = strlen("Tank_empty_flag");
    width_tank.atb_tank_level = strlen("Tank_level");
    width_tank.atb_tank_capacity = strlen("Tank_capacity");
    width_tank.atb_empty_threshold = strlen("Empty_threshold");

    ent_tank = adm_entity_system.ent_tank.live_list_head;

    while (ent_tank != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_tank->identity);
        if (width > width_tank.identity) width_tank.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%s", adm_sim_status_tank[ent_tank->status]);
        if (width > width_tank.status) width_tank.status = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_tank->atb_tank_number);
        if (width > width_tank.atb_tank_number) width_tank.atb_tank_number = width;

        if (ent_tank->atb_tank_empty_flag == TRUE || ent_tank->atb_tank_empty_flag == FALSE) {
            width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%s", adm_boolean[ent_tank->atb_tank_empty_flag]);
            if (width > width_tank.atb_tank_empty_flag) width_tank.atb_tank_empty_flag = width;}

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%f", ent_tank->atb_tank_level);
        if (width > width_tank.atb_tank_level) width_tank.atb_tank_level = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%f", ent_tank->atb_tank_capacity);
        if (width > width_tank.atb_tank_capacity) width_tank.atb_tank_capacity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%f", ent_tank->atb_empty_threshold);
        if (width > width_tank.atb_empty_threshold) width_tank.atb_empty_threshold = width;

        ent_tank = ent_tank->next;
    }

    printf(NEWLINE);
    printf("Tank:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_tank.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_tank.status, "Status");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_tank.atb_tank_number, "Tank_number");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_tank.atb_tank_empty_flag, "Tank_empty_flag");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_tank.atb_tank_level, "Tank_level");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_tank.atb_tank_capacity, "Tank_capacity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_tank.atb_empty_threshold, "Empty_threshold");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_tank.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_tank.status);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_tank.atb_tank_number);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_tank.atb_tank_empty_flag);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_tank.atb_tank_level);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_tank.atb_tank_capacity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_tank.atb_empty_threshold);

    ent_tank = adm_entity_system.ent_tank.live_list_head;

    while (ent_tank != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_tank.identity, ent_tank->identity);
        printf(ADM_SIM_COLUMN_GAP);

        switch (ent_tank->status) {
            case ADM_STATUS_TANK_CHECKING_LEVELS_AFTER_TANKER_DELIVERY :
                printf("%-*s", width_tank.status, "Checking_Levels_After_Tanker_Delivery");
            break;
            case ADM_STATUS_TANK_WAITING_FOR_TANKER_DELIVERY :
                printf("%-*s", width_tank.status, "Waiting_For_Tanker_Delivery");
            break;
            case ADM_STATUS_TANK_RESET_WAITING_PUMPS :
                printf("%-*s", width_tank.status, "Reset_Waiting_Pumps");
            break;
            case ADM_STATUS_TANK_CHECKING_LEVELS_AFTER_PUMP_USAGE :
                printf("%-*s", width_tank.status, "Checking_Levels_After_Pump_Usage");
            break;
            case ADM_STATUS_TANK_UPDATING_FUEL_LEVELS :
                printf("%-*s", width_tank.status, "Updating_Fuel_Levels");
            break;
            default :
                printf("%-*s", width_tank.status, "ERROR");
            break;
        }

        printf(ADM_SIM_COLUMN_GAP);
        printf("%*d", width_tank.atb_tank_number, ent_tank->atb_tank_number);
        printf(ADM_SIM_COLUMN_GAP);
        if (ent_tank->atb_tank_empty_flag == TRUE || ent_tank->atb_tank_empty_flag == FALSE)
            printf("%-*s", width_tank.atb_tank_empty_flag, adm_boolean[ent_tank->atb_tank_empty_flag]);
        else
            adm_sim_display_row('*', width_tank.atb_tank_empty_flag);
        printf(ADM_SIM_COLUMN_GAP);
        printf("%*f", width_tank.atb_tank_level, ent_tank->atb_tank_level);
        printf(ADM_SIM_COLUMN_GAP);
        printf("%*f", width_tank.atb_tank_capacity, ent_tank->atb_tank_capacity);
        printf(ADM_SIM_COLUMN_GAP);
        printf("%*f", width_tank.atb_empty_threshold, ent_tank->atb_empty_threshold);

        ent_tank = ent_tank->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_tank");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */