
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Pump Data Access */

/* Make Entity Object */

adm_ent_pump_typ * adm_make_object_pump(
    adm_sta_pump_typ status)
{
    adm_ent_pump_typ * ent_pump;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_pump");
    #endif

    if (adm_entity_system.ent_pump.dead_list_head != NULL) {

        ent_pump = adm_entity_system.ent_pump.dead_list_head;

        if (adm_entity_system.ent_pump.dead_list_head == ent_pump) {

            adm_entity_system.ent_pump.dead_list_head = ent_pump->next;

        } else {

            (ent_pump->back)->next = ent_pump->next;
        }

        if (adm_entity_system.ent_pump.dead_list_tail == ent_pump) {

            adm_entity_system.ent_pump.dead_list_tail = ent_pump->back;

        } else {

            (ent_pump->next)->back = ent_pump->back;
        }

    } else {

        ent_pump = (adm_ent_pump_typ*)adm_allocate_memory(sizeof(adm_ent_pump_typ));
    }

    ent_pump->identity = ++adm_entity_system.ent_pump.tote;

    ent_pump->unique  = FALSE;
    ent_pump->deleted = FALSE;
    ent_pump->marked  = FALSE;
    ent_pump->status  = status;

    ent_pump->rel_pumping_fuel_from_tank_head = NULL;
    ent_pump->rel_pumping_fuel_from_tank_tail = NULL;

    ent_pump->rel_being_used_for_delivery_head = NULL;
    ent_pump->rel_being_used_for_delivery_tail = NULL;

    ent_pump->back = NULL;
    ent_pump->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_pump");
    #endif

    return (ent_pump);
}


/* Bind Entity Object */

void adm_bind_object_pump(
    adm_ent_pump_typ * ent_pump,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_pump");
    #endif

    adm_object_existent_pump(
        ent_pump,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_pump.live_list_head == NULL) {

        ent_pump->back = NULL;

        adm_entity_system.ent_pump.live_list_head = ent_pump;

    } else {

        ent_pump->back = adm_entity_system.ent_pump.live_list_tail;

        (adm_entity_system.ent_pump.live_list_tail)->next = ent_pump;
    }

    ent_pump->next = NULL;

    adm_entity_system.ent_pump.live_list_tail = ent_pump;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_pump");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_pump(
    void * source_object,
    adm_ent_pump_typ * ent_pump,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_pump");
    #endif

    adm_object_existent_pump(
        ent_pump,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_pump) {

        if (ent_pump->rel_pumping_fuel_from_tank_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Pump",
                ent_pump->identity,
                "Pumping_fuel_from",
                "Tank");
        }

        if (ent_pump->rel_being_used_for_delivery_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Pump",
                ent_pump->identity,
                "Being_used_for",
                "Delivery");
        }

        if (adm_entity_system.ent_pump.live_list_head == ent_pump) {

            adm_entity_system.ent_pump.live_list_head = ent_pump->next;

        } else {

            (ent_pump->back)->next = ent_pump->next;
        }

        if (adm_entity_system.ent_pump.live_list_tail == ent_pump) {

            adm_entity_system.ent_pump.live_list_tail = ent_pump->back;

        } else {

            (ent_pump->next)->back = ent_pump->back;
        }

        ent_pump->deleted = TRUE;

        if (adm_entity_system.ent_pump.dead_list_head == NULL) {

            ent_pump->back = NULL;

            adm_entity_system.ent_pump.dead_list_head = ent_pump;

        } else {

            ent_pump->back = adm_entity_system.ent_pump.dead_list_tail;

            (adm_entity_system.ent_pump.dead_list_tail)->next = ent_pump;
        }

        ent_pump->next = NULL;

        adm_entity_system.ent_pump.dead_list_tail = ent_pump;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Pump",
            ent_pump->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_pump");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_pump_pumping_fuel_from_tank(
    adm_ent_pump_typ * ent_source_pump,
    adm_ent_tank_typ * ent_target_tank,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_pump_pumping_fuel_from_tank_typ * rel_pump_pumping_fuel_from_tank;

    adm_base_boolean_typ tank_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_pump_pumping_fuel_from_tank");
    #endif

    adm_object_existent_pump(
        ent_source_pump,
        error_file,
        error_line,
        error_rank);

    tank_not_found = TRUE;

    rel_pump_pumping_fuel_from_tank = ent_source_pump->rel_pumping_fuel_from_tank_head;

    while (
        tank_not_found &&
        rel_pump_pumping_fuel_from_tank != NULL) {

        if (rel_pump_pumping_fuel_from_tank->ent_tank == ent_target_tank) {

            tank_not_found = FALSE;
        }

        rel_pump_pumping_fuel_from_tank = rel_pump_pumping_fuel_from_tank->next;
    }

    if (tank_not_found) {

        rel_pump_pumping_fuel_from_tank = (adm_rel_pump_pumping_fuel_from_tank_typ*)
            adm_allocate_memory(sizeof(adm_rel_pump_pumping_fuel_from_tank_typ));

        rel_pump_pumping_fuel_from_tank->ent_tank = ent_target_tank;

        if (ent_source_pump->rel_pumping_fuel_from_tank_head == NULL) {

            rel_pump_pumping_fuel_from_tank->back = NULL;

            ent_source_pump->rel_pumping_fuel_from_tank_head = rel_pump_pumping_fuel_from_tank;

        } else {

            rel_pump_pumping_fuel_from_tank->back = ent_source_pump->rel_pumping_fuel_from_tank_tail;

            (ent_source_pump->rel_pumping_fuel_from_tank_tail)->next = rel_pump_pumping_fuel_from_tank;
        }

        rel_pump_pumping_fuel_from_tank->next = NULL;

        ent_source_pump->rel_pumping_fuel_from_tank_tail = rel_pump_pumping_fuel_from_tank;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Pump",
            ent_source_pump->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_pump_pumping_fuel_from_tank");
    #endif
}

void adm_link_relation_pump_being_used_for_delivery(
    adm_ent_pump_typ * ent_source_pump,
    adm_ent_delivery_typ * ent_target_delivery,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_pump_being_used_for_delivery_typ * rel_pump_being_used_for_delivery;

    adm_base_boolean_typ delivery_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_pump_being_used_for_delivery");
    #endif

    adm_object_existent_pump(
        ent_source_pump,
        error_file,
        error_line,
        error_rank);

    delivery_not_found = TRUE;

    rel_pump_being_used_for_delivery = ent_source_pump->rel_being_used_for_delivery_head;

    while (
        delivery_not_found &&
        rel_pump_being_used_for_delivery != NULL) {

        if (rel_pump_being_used_for_delivery->ent_delivery == ent_target_delivery) {

            delivery_not_found = FALSE;
        }

        rel_pump_being_used_for_delivery = rel_pump_being_used_for_delivery->next;
    }

    if (delivery_not_found) {

        rel_pump_being_used_for_delivery = (adm_rel_pump_being_used_for_delivery_typ*)
            adm_allocate_memory(sizeof(adm_rel_pump_being_used_for_delivery_typ));

        rel_pump_being_used_for_delivery->ent_delivery = ent_target_delivery;

        if (ent_source_pump->rel_being_used_for_delivery_head == NULL) {

            rel_pump_being_used_for_delivery->back = NULL;

            ent_source_pump->rel_being_used_for_delivery_head = rel_pump_being_used_for_delivery;

        } else {

            rel_pump_being_used_for_delivery->back = ent_source_pump->rel_being_used_for_delivery_tail;

            (ent_source_pump->rel_being_used_for_delivery_tail)->next = rel_pump_being_used_for_delivery;
        }

        rel_pump_being_used_for_delivery->next = NULL;

        ent_source_pump->rel_being_used_for_delivery_tail = rel_pump_being_used_for_delivery;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Pump",
            ent_source_pump->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_pump_being_used_for_delivery");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_pump_pumping_fuel_from_tank(
    adm_ent_pump_typ * ent_pump,
    adm_rel_pump_pumping_fuel_from_tank_typ * rel_pump_pumping_fuel_from_tank,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_pump_pumping_fuel_from_tank");
    #endif

    adm_object_existent_pump(
        ent_pump,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_pump_pumping_fuel_from_tank->next !=
        (adm_base_integer_typ)rel_pump_pumping_fuel_from_tank->ent_tank) {

        if (ent_pump->rel_pumping_fuel_from_tank_head != NULL) {

            if (ent_pump->rel_pumping_fuel_from_tank_head == rel_pump_pumping_fuel_from_tank) {

                ent_pump->rel_pumping_fuel_from_tank_head = rel_pump_pumping_fuel_from_tank->next;

            } else {

                (rel_pump_pumping_fuel_from_tank->back)->next = rel_pump_pumping_fuel_from_tank->next;
            }

            if (ent_pump->rel_pumping_fuel_from_tank_tail == rel_pump_pumping_fuel_from_tank) {

                ent_pump->rel_pumping_fuel_from_tank_tail = rel_pump_pumping_fuel_from_tank->back;

            } else {

                (rel_pump_pumping_fuel_from_tank->next)->back = rel_pump_pumping_fuel_from_tank->back;
            }

            adm_deallocate_memory(rel_pump_pumping_fuel_from_tank);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Pump",
                ent_pump->identity,
                "Pumping_fuel_from",
                "Tank");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Pump",
            ent_pump->identity,
            "Pumping_fuel_from",
            "Tank");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_pump_pumping_fuel_from_tank");
    #endif
}

void adm_kill_relation_pump_being_used_for_delivery(
    adm_ent_pump_typ * ent_pump,
    adm_rel_pump_being_used_for_delivery_typ * rel_pump_being_used_for_delivery,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_pump_being_used_for_delivery");
    #endif

    adm_object_existent_pump(
        ent_pump,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_pump_being_used_for_delivery->next !=
        (adm_base_integer_typ)rel_pump_being_used_for_delivery->ent_delivery) {

        if (ent_pump->rel_being_used_for_delivery_head != NULL) {

            if (ent_pump->rel_being_used_for_delivery_head == rel_pump_being_used_for_delivery) {

                ent_pump->rel_being_used_for_delivery_head = rel_pump_being_used_for_delivery->next;

            } else {

                (rel_pump_being_used_for_delivery->back)->next = rel_pump_being_used_for_delivery->next;
            }

            if (ent_pump->rel_being_used_for_delivery_tail == rel_pump_being_used_for_delivery) {

                ent_pump->rel_being_used_for_delivery_tail = rel_pump_being_used_for_delivery->back;

            } else {

                (rel_pump_being_used_for_delivery->next)->back = rel_pump_being_used_for_delivery->back;
            }

            adm_deallocate_memory(rel_pump_being_used_for_delivery);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Pump",
                ent_pump->identity,
                "Being_used_for",
                "Delivery");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Pump",
            ent_pump->identity,
            "Being_used_for",
            "Delivery");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_pump_being_used_for_delivery");
    #endif
}


/* Object Existent */

void adm_object_existent_pump(
    const adm_ent_pump_typ * const ent_pump,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_pump");
    #endif

    if (ent_pump->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Pump",
            ent_pump->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_pump");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */