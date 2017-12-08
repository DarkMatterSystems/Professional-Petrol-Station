
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Fuel Grade Simulator Display Entity */

void adm_sim_display_entity_fuel_grade(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_fuel_grade_typ * ent_fuel_grade;

    adm_sim_width_fuel_grade_typ width_fuel_grade;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_fuel_grade");
    #endif

    width_fuel_grade.identity = strlen("Identity");
    width_fuel_grade.atb_grade_name = strlen("Grade_name");
    width_fuel_grade.atb_unit_price = strlen("Unit_price");
    width_fuel_grade.atb_unit_volume = strlen("Unit_volume");

    ent_fuel_grade = adm_entity_system.ent_fuel_grade.live_list_head;

    while (ent_fuel_grade != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_fuel_grade->identity);
        if (width > width_fuel_grade.identity) width_fuel_grade.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_fuel_grade->atb_grade_name);
        if (width > width_fuel_grade.atb_grade_name) width_fuel_grade.atb_grade_name = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%f", ent_fuel_grade->atb_unit_price);
        if (width > width_fuel_grade.atb_unit_price) width_fuel_grade.atb_unit_price = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%f", ent_fuel_grade->atb_unit_volume);
        if (width > width_fuel_grade.atb_unit_volume) width_fuel_grade.atb_unit_volume = width;

        ent_fuel_grade = ent_fuel_grade->next;
    }

    printf(NEWLINE);
    printf("Fuel_Grade:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_fuel_grade.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_fuel_grade.atb_grade_name, "Grade_name");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_fuel_grade.atb_unit_price, "Unit_price");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_fuel_grade.atb_unit_volume, "Unit_volume");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_fuel_grade.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_fuel_grade.atb_grade_name);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_fuel_grade.atb_unit_price);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_fuel_grade.atb_unit_volume);

    ent_fuel_grade = adm_entity_system.ent_fuel_grade.live_list_head;

    while (ent_fuel_grade != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_fuel_grade.identity, ent_fuel_grade->identity);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_fuel_grade->atb_grade_name);
        printf("%-*s", width_fuel_grade.atb_grade_name, buffer);
        printf(ADM_SIM_COLUMN_GAP);
        printf("%*f", width_fuel_grade.atb_unit_price, ent_fuel_grade->atb_unit_price);
        printf(ADM_SIM_COLUMN_GAP);
        printf("%*f", width_fuel_grade.atb_unit_volume, ent_fuel_grade->atb_unit_volume);

        ent_fuel_grade = ent_fuel_grade->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_fuel_grade");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */