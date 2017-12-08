
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Tank Data Access */

/* Make Entity Object */

adm_ent_tank_typ * adm_make_object_tank(
    adm_sta_tank_typ status)
{
    adm_ent_tank_typ * ent_tank;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_tank");
    #endif

    if (adm_entity_system.ent_tank.dead_list_head != NULL) {

        ent_tank = adm_entity_system.ent_tank.dead_list_head;

        if (adm_entity_system.ent_tank.dead_list_head == ent_tank) {

            adm_entity_system.ent_tank.dead_list_head = ent_tank->next;

        } else {

            (ent_tank->back)->next = ent_tank->next;
        }

        if (adm_entity_system.ent_tank.dead_list_tail == ent_tank) {

            adm_entity_system.ent_tank.dead_list_tail = ent_tank->back;

        } else {

            (ent_tank->next)->back = ent_tank->back;
        }

    } else {

        ent_tank = (adm_ent_tank_typ*)adm_allocate_memory(sizeof(adm_ent_tank_typ));
    }

    ent_tank->identity = ++adm_entity_system.ent_tank.tote;

    ent_tank->unique  = FALSE;
    ent_tank->deleted = FALSE;
    ent_tank->marked  = FALSE;
    ent_tank->status  = status;

    ent_tank->rel_providing_fuel_for_pump_head = NULL;
    ent_tank->rel_providing_fuel_for_pump_tail = NULL;

    ent_tank->rel_stores_fuel_grade_head = NULL;
    ent_tank->rel_stores_fuel_grade_tail = NULL;

    ent_tank->back = NULL;
    ent_tank->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_tank");
    #endif

    return (ent_tank);
}


/* Bind Entity Object */

void adm_bind_object_tank(
    adm_ent_tank_typ * ent_tank,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_tank");
    #endif

    adm_object_existent_tank(
        ent_tank,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_tank.live_list_head == NULL) {

        ent_tank->back = NULL;

        adm_entity_system.ent_tank.live_list_head = ent_tank;

    } else {

        ent_tank->back = adm_entity_system.ent_tank.live_list_tail;

        (adm_entity_system.ent_tank.live_list_tail)->next = ent_tank;
    }

    ent_tank->next = NULL;

    adm_entity_system.ent_tank.live_list_tail = ent_tank;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_tank");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_tank(
    void * source_object,
    adm_ent_tank_typ * ent_tank,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_tank");
    #endif

    adm_object_existent_tank(
        ent_tank,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_tank) {

        if (ent_tank->rel_providing_fuel_for_pump_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Tank",
                ent_tank->identity,
                "Providing_fuel_for",
                "Pump");
        }

        if (ent_tank->rel_stores_fuel_grade_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Tank",
                ent_tank->identity,
                "Stores",
                "Fuel_Grade");
        }

        if (adm_entity_system.ent_tank.live_list_head == ent_tank) {

            adm_entity_system.ent_tank.live_list_head = ent_tank->next;

        } else {

            (ent_tank->back)->next = ent_tank->next;
        }

        if (adm_entity_system.ent_tank.live_list_tail == ent_tank) {

            adm_entity_system.ent_tank.live_list_tail = ent_tank->back;

        } else {

            (ent_tank->next)->back = ent_tank->back;
        }

        ent_tank->deleted = TRUE;

        if (adm_entity_system.ent_tank.dead_list_head == NULL) {

            ent_tank->back = NULL;

            adm_entity_system.ent_tank.dead_list_head = ent_tank;

        } else {

            ent_tank->back = adm_entity_system.ent_tank.dead_list_tail;

            (adm_entity_system.ent_tank.dead_list_tail)->next = ent_tank;
        }

        ent_tank->next = NULL;

        adm_entity_system.ent_tank.dead_list_tail = ent_tank;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Tank",
            ent_tank->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_tank");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_tank_providing_fuel_for_pump(
    adm_ent_tank_typ * ent_source_tank,
    adm_ent_pump_typ * ent_target_pump,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_tank_providing_fuel_for_pump_typ * rel_tank_providing_fuel_for_pump;

    adm_base_boolean_typ pump_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_tank_providing_fuel_for_pump");
    #endif

    adm_object_existent_tank(
        ent_source_tank,
        error_file,
        error_line,
        error_rank);

    pump_not_found = TRUE;

    rel_tank_providing_fuel_for_pump = ent_source_tank->rel_providing_fuel_for_pump_head;

    while (
        pump_not_found &&
        rel_tank_providing_fuel_for_pump != NULL) {

        if (rel_tank_providing_fuel_for_pump->ent_pump == ent_target_pump) {

            pump_not_found = FALSE;
        }

        rel_tank_providing_fuel_for_pump = rel_tank_providing_fuel_for_pump->next;
    }

    if (pump_not_found) {

        rel_tank_providing_fuel_for_pump = (adm_rel_tank_providing_fuel_for_pump_typ*)
            adm_allocate_memory(sizeof(adm_rel_tank_providing_fuel_for_pump_typ));

        rel_tank_providing_fuel_for_pump->ent_pump = ent_target_pump;

        if (ent_source_tank->rel_providing_fuel_for_pump_head == NULL) {

            rel_tank_providing_fuel_for_pump->back = NULL;

            ent_source_tank->rel_providing_fuel_for_pump_head = rel_tank_providing_fuel_for_pump;

        } else {

            rel_tank_providing_fuel_for_pump->back = ent_source_tank->rel_providing_fuel_for_pump_tail;

            (ent_source_tank->rel_providing_fuel_for_pump_tail)->next = rel_tank_providing_fuel_for_pump;
        }

        rel_tank_providing_fuel_for_pump->next = NULL;

        ent_source_tank->rel_providing_fuel_for_pump_tail = rel_tank_providing_fuel_for_pump;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Tank",
            ent_source_tank->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_tank_providing_fuel_for_pump");
    #endif
}

void adm_link_relation_tank_stores_fuel_grade(
    adm_ent_tank_typ * ent_source_tank,
    adm_ent_fuel_grade_typ * ent_target_fuel_grade,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_tank_stores_fuel_grade_typ * rel_tank_stores_fuel_grade;

    adm_base_boolean_typ fuel_grade_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_tank_stores_fuel_grade");
    #endif

    adm_object_existent_tank(
        ent_source_tank,
        error_file,
        error_line,
        error_rank);

    fuel_grade_not_found = TRUE;

    rel_tank_stores_fuel_grade = ent_source_tank->rel_stores_fuel_grade_head;

    while (
        fuel_grade_not_found &&
        rel_tank_stores_fuel_grade != NULL) {

        if (rel_tank_stores_fuel_grade->ent_fuel_grade == ent_target_fuel_grade) {

            fuel_grade_not_found = FALSE;
        }

        rel_tank_stores_fuel_grade = rel_tank_stores_fuel_grade->next;
    }

    if (fuel_grade_not_found) {

        rel_tank_stores_fuel_grade = (adm_rel_tank_stores_fuel_grade_typ*)
            adm_allocate_memory(sizeof(adm_rel_tank_stores_fuel_grade_typ));

        rel_tank_stores_fuel_grade->ent_fuel_grade = ent_target_fuel_grade;

        if (ent_source_tank->rel_stores_fuel_grade_head == NULL) {

            rel_tank_stores_fuel_grade->back = NULL;

            ent_source_tank->rel_stores_fuel_grade_head = rel_tank_stores_fuel_grade;

        } else {

            rel_tank_stores_fuel_grade->back = ent_source_tank->rel_stores_fuel_grade_tail;

            (ent_source_tank->rel_stores_fuel_grade_tail)->next = rel_tank_stores_fuel_grade;
        }

        rel_tank_stores_fuel_grade->next = NULL;

        ent_source_tank->rel_stores_fuel_grade_tail = rel_tank_stores_fuel_grade;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Tank",
            ent_source_tank->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_tank_stores_fuel_grade");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_tank_providing_fuel_for_pump(
    adm_ent_tank_typ * ent_tank,
    adm_rel_tank_providing_fuel_for_pump_typ * rel_tank_providing_fuel_for_pump,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_tank_providing_fuel_for_pump");
    #endif

    adm_object_existent_tank(
        ent_tank,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_tank_providing_fuel_for_pump->next !=
        (adm_base_integer_typ)rel_tank_providing_fuel_for_pump->ent_pump) {

        if (ent_tank->rel_providing_fuel_for_pump_head != NULL) {

            if (ent_tank->rel_providing_fuel_for_pump_head == rel_tank_providing_fuel_for_pump) {

                ent_tank->rel_providing_fuel_for_pump_head = rel_tank_providing_fuel_for_pump->next;

            } else {

                (rel_tank_providing_fuel_for_pump->back)->next = rel_tank_providing_fuel_for_pump->next;
            }

            if (ent_tank->rel_providing_fuel_for_pump_tail == rel_tank_providing_fuel_for_pump) {

                ent_tank->rel_providing_fuel_for_pump_tail = rel_tank_providing_fuel_for_pump->back;

            } else {

                (rel_tank_providing_fuel_for_pump->next)->back = rel_tank_providing_fuel_for_pump->back;
            }

            adm_deallocate_memory(rel_tank_providing_fuel_for_pump);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Tank",
                ent_tank->identity,
                "Providing_fuel_for",
                "Pump");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Tank",
            ent_tank->identity,
            "Providing_fuel_for",
            "Pump");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_tank_providing_fuel_for_pump");
    #endif
}

void adm_kill_relation_tank_stores_fuel_grade(
    adm_ent_tank_typ * ent_tank,
    adm_rel_tank_stores_fuel_grade_typ * rel_tank_stores_fuel_grade,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_tank_stores_fuel_grade");
    #endif

    adm_object_existent_tank(
        ent_tank,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_tank_stores_fuel_grade->next !=
        (adm_base_integer_typ)rel_tank_stores_fuel_grade->ent_fuel_grade) {

        if (ent_tank->rel_stores_fuel_grade_head != NULL) {

            if (ent_tank->rel_stores_fuel_grade_head == rel_tank_stores_fuel_grade) {

                ent_tank->rel_stores_fuel_grade_head = rel_tank_stores_fuel_grade->next;

            } else {

                (rel_tank_stores_fuel_grade->back)->next = rel_tank_stores_fuel_grade->next;
            }

            if (ent_tank->rel_stores_fuel_grade_tail == rel_tank_stores_fuel_grade) {

                ent_tank->rel_stores_fuel_grade_tail = rel_tank_stores_fuel_grade->back;

            } else {

                (rel_tank_stores_fuel_grade->next)->back = rel_tank_stores_fuel_grade->back;
            }

            adm_deallocate_memory(rel_tank_stores_fuel_grade);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Tank",
                ent_tank->identity,
                "Stores",
                "Fuel_Grade");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Tank",
            ent_tank->identity,
            "Stores",
            "Fuel_Grade");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_tank_stores_fuel_grade");
    #endif
}


/* Object Existent */

void adm_object_existent_tank(
    const adm_ent_tank_typ * const ent_tank,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_tank");
    #endif

    if (ent_tank->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Tank",
            ent_tank->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_tank");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */