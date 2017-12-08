
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Fuel Grade Data Access */

/* Make Entity Object */

adm_ent_fuel_grade_typ * adm_make_object_fuel_grade(
    void)
{
    adm_ent_fuel_grade_typ * ent_fuel_grade;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_fuel_grade");
    #endif

    if (adm_entity_system.ent_fuel_grade.dead_list_head != NULL) {

        ent_fuel_grade = adm_entity_system.ent_fuel_grade.dead_list_head;

        if (adm_entity_system.ent_fuel_grade.dead_list_head == ent_fuel_grade) {

            adm_entity_system.ent_fuel_grade.dead_list_head = ent_fuel_grade->next;

        } else {

            (ent_fuel_grade->back)->next = ent_fuel_grade->next;
        }

        if (adm_entity_system.ent_fuel_grade.dead_list_tail == ent_fuel_grade) {

            adm_entity_system.ent_fuel_grade.dead_list_tail = ent_fuel_grade->back;

        } else {

            (ent_fuel_grade->next)->back = ent_fuel_grade->back;
        }

    } else {

        ent_fuel_grade = (adm_ent_fuel_grade_typ*)adm_allocate_memory(sizeof(adm_ent_fuel_grade_typ));
    }

    ent_fuel_grade->identity = ++adm_entity_system.ent_fuel_grade.tote;

    ent_fuel_grade->unique  = FALSE;
    ent_fuel_grade->deleted = FALSE;
    ent_fuel_grade->marked  = FALSE;
    ent_fuel_grade->ignore  = null;

    ent_fuel_grade->atb_grade_name = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);

    ent_fuel_grade->back = NULL;
    ent_fuel_grade->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_fuel_grade");
    #endif

    return (ent_fuel_grade);
}


/* Bind Entity Object */

void adm_bind_object_fuel_grade(
    adm_ent_fuel_grade_typ * ent_fuel_grade,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_fuel_grade");
    #endif

    adm_object_existent_fuel_grade(
        ent_fuel_grade,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_fuel_grade.live_list_head == NULL) {

        ent_fuel_grade->back = NULL;

        adm_entity_system.ent_fuel_grade.live_list_head = ent_fuel_grade;

    } else {

        ent_fuel_grade->back = adm_entity_system.ent_fuel_grade.live_list_tail;

        (adm_entity_system.ent_fuel_grade.live_list_tail)->next = ent_fuel_grade;
    }

    ent_fuel_grade->next = NULL;

    adm_entity_system.ent_fuel_grade.live_list_tail = ent_fuel_grade;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_fuel_grade");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_fuel_grade(
    void * source_object,
    adm_ent_fuel_grade_typ * ent_fuel_grade,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_fuel_grade");
    #endif

    adm_object_existent_fuel_grade(
        ent_fuel_grade,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_fuel_grade) {

        if (adm_entity_system.ent_fuel_grade.live_list_head == ent_fuel_grade) {

            adm_entity_system.ent_fuel_grade.live_list_head = ent_fuel_grade->next;

        } else {

            (ent_fuel_grade->back)->next = ent_fuel_grade->next;
        }

        if (adm_entity_system.ent_fuel_grade.live_list_tail == ent_fuel_grade) {

            adm_entity_system.ent_fuel_grade.live_list_tail = ent_fuel_grade->back;

        } else {

            (ent_fuel_grade->next)->back = ent_fuel_grade->back;
        }

        adm_deallocate_memory(ent_fuel_grade->atb_grade_name);

        ent_fuel_grade->deleted = TRUE;

        if (adm_entity_system.ent_fuel_grade.dead_list_head == NULL) {

            ent_fuel_grade->back = NULL;

            adm_entity_system.ent_fuel_grade.dead_list_head = ent_fuel_grade;

        } else {

            ent_fuel_grade->back = adm_entity_system.ent_fuel_grade.dead_list_tail;

            (adm_entity_system.ent_fuel_grade.dead_list_tail)->next = ent_fuel_grade;
        }

        ent_fuel_grade->next = NULL;

        adm_entity_system.ent_fuel_grade.dead_list_tail = ent_fuel_grade;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Fuel_Grade",
            ent_fuel_grade->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_fuel_grade");
    #endif
}


/* Object Existent */

void adm_object_existent_fuel_grade(
    const adm_ent_fuel_grade_typ * const ent_fuel_grade,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_fuel_grade");
    #endif

    if (ent_fuel_grade->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Fuel_Grade",
            ent_fuel_grade->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_fuel_grade");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */