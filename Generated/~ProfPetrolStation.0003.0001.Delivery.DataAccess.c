
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Delivery Data Access */

/* Make Entity Object */

adm_ent_delivery_typ * adm_make_object_delivery(
    adm_sta_delivery_typ status)
{
    adm_ent_delivery_typ * ent_delivery;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_delivery");
    #endif

    if (adm_entity_system.ent_delivery.dead_list_head != NULL) {

        ent_delivery = adm_entity_system.ent_delivery.dead_list_head;

        if (adm_entity_system.ent_delivery.dead_list_head == ent_delivery) {

            adm_entity_system.ent_delivery.dead_list_head = ent_delivery->next;

        } else {

            (ent_delivery->back)->next = ent_delivery->next;
        }

        if (adm_entity_system.ent_delivery.dead_list_tail == ent_delivery) {

            adm_entity_system.ent_delivery.dead_list_tail = ent_delivery->back;

        } else {

            (ent_delivery->next)->back = ent_delivery->back;
        }

    } else {

        ent_delivery = (adm_ent_delivery_typ*)adm_allocate_memory(sizeof(adm_ent_delivery_typ));
    }

    ent_delivery->identity = ++adm_entity_system.ent_delivery.tote;

    ent_delivery->unique  = FALSE;
    ent_delivery->deleted = FALSE;
    ent_delivery->marked  = FALSE;
    ent_delivery->status  = status;

    ent_delivery->rel_being_made_using_pump_head = NULL;
    ent_delivery->rel_being_made_using_pump_tail = NULL;

    ent_delivery->back = NULL;
    ent_delivery->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_delivery");
    #endif

    return (ent_delivery);
}


/* Bind Entity Object */

void adm_bind_object_delivery(
    adm_ent_delivery_typ * ent_delivery,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_delivery");
    #endif

    adm_object_existent_delivery(
        ent_delivery,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_delivery.live_list_head == NULL) {

        ent_delivery->back = NULL;

        adm_entity_system.ent_delivery.live_list_head = ent_delivery;

    } else {

        ent_delivery->back = adm_entity_system.ent_delivery.live_list_tail;

        (adm_entity_system.ent_delivery.live_list_tail)->next = ent_delivery;
    }

    ent_delivery->next = NULL;

    adm_entity_system.ent_delivery.live_list_tail = ent_delivery;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_delivery");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_delivery(
    void * source_object,
    adm_ent_delivery_typ * ent_delivery,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_delivery");
    #endif

    adm_object_existent_delivery(
        ent_delivery,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_delivery) {

        if (ent_delivery->rel_being_made_using_pump_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Delivery",
                ent_delivery->identity,
                "Being_made_using",
                "Pump");
        }

        if (adm_entity_system.ent_delivery.live_list_head == ent_delivery) {

            adm_entity_system.ent_delivery.live_list_head = ent_delivery->next;

        } else {

            (ent_delivery->back)->next = ent_delivery->next;
        }

        if (adm_entity_system.ent_delivery.live_list_tail == ent_delivery) {

            adm_entity_system.ent_delivery.live_list_tail = ent_delivery->back;

        } else {

            (ent_delivery->next)->back = ent_delivery->back;
        }

        ent_delivery->deleted = TRUE;

        if (adm_entity_system.ent_delivery.dead_list_head == NULL) {

            ent_delivery->back = NULL;

            adm_entity_system.ent_delivery.dead_list_head = ent_delivery;

        } else {

            ent_delivery->back = adm_entity_system.ent_delivery.dead_list_tail;

            (adm_entity_system.ent_delivery.dead_list_tail)->next = ent_delivery;
        }

        ent_delivery->next = NULL;

        adm_entity_system.ent_delivery.dead_list_tail = ent_delivery;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Delivery",
            ent_delivery->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_delivery");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_delivery_being_made_using_pump(
    adm_ent_delivery_typ * ent_source_delivery,
    adm_ent_pump_typ * ent_target_pump,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_delivery_being_made_using_pump_typ * rel_delivery_being_made_using_pump;

    adm_base_boolean_typ pump_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_delivery_being_made_using_pump");
    #endif

    adm_object_existent_delivery(
        ent_source_delivery,
        error_file,
        error_line,
        error_rank);

    pump_not_found = TRUE;

    rel_delivery_being_made_using_pump = ent_source_delivery->rel_being_made_using_pump_head;

    while (
        pump_not_found &&
        rel_delivery_being_made_using_pump != NULL) {

        if (rel_delivery_being_made_using_pump->ent_pump == ent_target_pump) {

            pump_not_found = FALSE;
        }

        rel_delivery_being_made_using_pump = rel_delivery_being_made_using_pump->next;
    }

    if (pump_not_found) {

        rel_delivery_being_made_using_pump = (adm_rel_delivery_being_made_using_pump_typ*)
            adm_allocate_memory(sizeof(adm_rel_delivery_being_made_using_pump_typ));

        rel_delivery_being_made_using_pump->ent_pump = ent_target_pump;

        if (ent_source_delivery->rel_being_made_using_pump_head == NULL) {

            rel_delivery_being_made_using_pump->back = NULL;

            ent_source_delivery->rel_being_made_using_pump_head = rel_delivery_being_made_using_pump;

        } else {

            rel_delivery_being_made_using_pump->back = ent_source_delivery->rel_being_made_using_pump_tail;

            (ent_source_delivery->rel_being_made_using_pump_tail)->next = rel_delivery_being_made_using_pump;
        }

        rel_delivery_being_made_using_pump->next = NULL;

        ent_source_delivery->rel_being_made_using_pump_tail = rel_delivery_being_made_using_pump;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Delivery",
            ent_source_delivery->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_delivery_being_made_using_pump");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_delivery_being_made_using_pump(
    adm_ent_delivery_typ * ent_delivery,
    adm_rel_delivery_being_made_using_pump_typ * rel_delivery_being_made_using_pump,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_delivery_being_made_using_pump");
    #endif

    adm_object_existent_delivery(
        ent_delivery,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_delivery_being_made_using_pump->next !=
        (adm_base_integer_typ)rel_delivery_being_made_using_pump->ent_pump) {

        if (ent_delivery->rel_being_made_using_pump_head != NULL) {

            if (ent_delivery->rel_being_made_using_pump_head == rel_delivery_being_made_using_pump) {

                ent_delivery->rel_being_made_using_pump_head = rel_delivery_being_made_using_pump->next;

            } else {

                (rel_delivery_being_made_using_pump->back)->next = rel_delivery_being_made_using_pump->next;
            }

            if (ent_delivery->rel_being_made_using_pump_tail == rel_delivery_being_made_using_pump) {

                ent_delivery->rel_being_made_using_pump_tail = rel_delivery_being_made_using_pump->back;

            } else {

                (rel_delivery_being_made_using_pump->next)->back = rel_delivery_being_made_using_pump->back;
            }

            adm_deallocate_memory(rel_delivery_being_made_using_pump);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Delivery",
                ent_delivery->identity,
                "Being_made_using",
                "Pump");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Delivery",
            ent_delivery->identity,
            "Being_made_using",
            "Pump");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_delivery_being_made_using_pump");
    #endif
}


/* Object Existent */

void adm_object_existent_delivery(
    const adm_ent_delivery_typ * const ent_delivery,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_delivery");
    #endif

    if (ent_delivery->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Delivery",
            ent_delivery->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_delivery");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */