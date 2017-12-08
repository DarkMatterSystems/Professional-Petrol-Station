
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Check Fuel Grade Identifiers Unique */

void adm_check_identifiers_unique_fuel_grade(
    adm_ent_fuel_grade_typ * ent_source_fuel_grade,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_ent_fuel_grade_typ * ent_target_fuel_grade;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_IDENTIFIER, "adm_check_identifiers_unique_fuel_grade");
    #endif

    ent_target_fuel_grade = adm_entity_system.ent_fuel_grade.live_list_head;

    while (ent_target_fuel_grade != NULL) {

        if (
            !strcmp(
                ent_target_fuel_grade->atb_grade_name, ent_source_fuel_grade->atb_grade_name)) {

            adm_error_report(
                ADM_ERROR_OBJECT_IDENTIFIER_ATTRIBUTES_NOT_UNIQUE,
                error_file, error_line, error_rank,
                "Fuel_Grade",
                ent_target_fuel_grade->identity,
                NULL,
                NULL);
        }

        ent_target_fuel_grade = ent_target_fuel_grade->next;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_IDENTIFIER, "adm_check_identifiers_unique_fuel_grade");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */