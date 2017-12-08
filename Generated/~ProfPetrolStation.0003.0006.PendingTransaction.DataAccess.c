
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Pending Transaction Data Access */

/* Make Entity Object */

adm_ent_pending_transaction_typ * adm_make_object_pending_transaction(
    void)
{
    adm_ent_pending_transaction_typ * ent_pending_transaction;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_pending_transaction");
    #endif

    if (adm_entity_system.ent_pending_transaction.dead_list_head != NULL) {

        ent_pending_transaction = adm_entity_system.ent_pending_transaction.dead_list_head;

        if (adm_entity_system.ent_pending_transaction.dead_list_head == ent_pending_transaction) {

            adm_entity_system.ent_pending_transaction.dead_list_head = ent_pending_transaction->next;

        } else {

            (ent_pending_transaction->back)->next = ent_pending_transaction->next;
        }

        if (adm_entity_system.ent_pending_transaction.dead_list_tail == ent_pending_transaction) {

            adm_entity_system.ent_pending_transaction.dead_list_tail = ent_pending_transaction->back;

        } else {

            (ent_pending_transaction->next)->back = ent_pending_transaction->back;
        }

    } else {

        ent_pending_transaction = (adm_ent_pending_transaction_typ*)adm_allocate_memory(sizeof(adm_ent_pending_transaction_typ));
    }

    ent_pending_transaction->identity = ++adm_entity_system.ent_pending_transaction.tote;

    ent_pending_transaction->unique  = FALSE;
    ent_pending_transaction->deleted = FALSE;
    ent_pending_transaction->marked  = FALSE;
    ent_pending_transaction->ignore  = null;

    ent_pending_transaction->rel_pending_for_pump_head = NULL;
    ent_pending_transaction->rel_pending_for_pump_tail = NULL;

    ent_pending_transaction->back = NULL;
    ent_pending_transaction->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_pending_transaction");
    #endif

    return (ent_pending_transaction);
}


/* Bind Entity Object */

void adm_bind_object_pending_transaction(
    adm_ent_pending_transaction_typ * ent_pending_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_pending_transaction");
    #endif

    adm_object_existent_pending_transaction(
        ent_pending_transaction,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_pending_transaction.live_list_head == NULL) {

        ent_pending_transaction->back = NULL;

        adm_entity_system.ent_pending_transaction.live_list_head = ent_pending_transaction;

    } else {

        ent_pending_transaction->back = adm_entity_system.ent_pending_transaction.live_list_tail;

        (adm_entity_system.ent_pending_transaction.live_list_tail)->next = ent_pending_transaction;
    }

    ent_pending_transaction->next = NULL;

    adm_entity_system.ent_pending_transaction.live_list_tail = ent_pending_transaction;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_pending_transaction");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_pending_transaction(
    void * source_object,
    adm_ent_pending_transaction_typ * ent_pending_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_pending_transaction");
    #endif

    adm_object_existent_pending_transaction(
        ent_pending_transaction,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_pending_transaction) {

        if (ent_pending_transaction->rel_pending_for_pump_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Pending_Transaction",
                ent_pending_transaction->identity,
                "Pending_for",
                "Pump");
        }

        if (adm_entity_system.ent_pending_transaction.live_list_head == ent_pending_transaction) {

            adm_entity_system.ent_pending_transaction.live_list_head = ent_pending_transaction->next;

        } else {

            (ent_pending_transaction->back)->next = ent_pending_transaction->next;
        }

        if (adm_entity_system.ent_pending_transaction.live_list_tail == ent_pending_transaction) {

            adm_entity_system.ent_pending_transaction.live_list_tail = ent_pending_transaction->back;

        } else {

            (ent_pending_transaction->next)->back = ent_pending_transaction->back;
        }

        ent_pending_transaction->deleted = TRUE;

        if (adm_entity_system.ent_pending_transaction.dead_list_head == NULL) {

            ent_pending_transaction->back = NULL;

            adm_entity_system.ent_pending_transaction.dead_list_head = ent_pending_transaction;

        } else {

            ent_pending_transaction->back = adm_entity_system.ent_pending_transaction.dead_list_tail;

            (adm_entity_system.ent_pending_transaction.dead_list_tail)->next = ent_pending_transaction;
        }

        ent_pending_transaction->next = NULL;

        adm_entity_system.ent_pending_transaction.dead_list_tail = ent_pending_transaction;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Pending_Transaction",
            ent_pending_transaction->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_pending_transaction");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_pending_transaction_pending_for_pump(
    adm_ent_pending_transaction_typ * ent_source_pending_transaction,
    adm_ent_pump_typ * ent_target_pump,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_pending_transaction_pending_for_pump_typ * rel_pending_transaction_pending_for_pump;

    adm_base_boolean_typ pump_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_pending_transaction_pending_for_pump");
    #endif

    adm_object_existent_pending_transaction(
        ent_source_pending_transaction,
        error_file,
        error_line,
        error_rank);

    pump_not_found = TRUE;

    rel_pending_transaction_pending_for_pump = ent_source_pending_transaction->rel_pending_for_pump_head;

    while (
        pump_not_found &&
        rel_pending_transaction_pending_for_pump != NULL) {

        if (rel_pending_transaction_pending_for_pump->ent_pump == ent_target_pump) {

            pump_not_found = FALSE;
        }

        rel_pending_transaction_pending_for_pump = rel_pending_transaction_pending_for_pump->next;
    }

    if (pump_not_found) {

        rel_pending_transaction_pending_for_pump = (adm_rel_pending_transaction_pending_for_pump_typ*)
            adm_allocate_memory(sizeof(adm_rel_pending_transaction_pending_for_pump_typ));

        rel_pending_transaction_pending_for_pump->ent_pump = ent_target_pump;

        if (ent_source_pending_transaction->rel_pending_for_pump_head == NULL) {

            rel_pending_transaction_pending_for_pump->back = NULL;

            ent_source_pending_transaction->rel_pending_for_pump_head = rel_pending_transaction_pending_for_pump;

        } else {

            rel_pending_transaction_pending_for_pump->back = ent_source_pending_transaction->rel_pending_for_pump_tail;

            (ent_source_pending_transaction->rel_pending_for_pump_tail)->next = rel_pending_transaction_pending_for_pump;
        }

        rel_pending_transaction_pending_for_pump->next = NULL;

        ent_source_pending_transaction->rel_pending_for_pump_tail = rel_pending_transaction_pending_for_pump;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Pending_Transaction",
            ent_source_pending_transaction->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_pending_transaction_pending_for_pump");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_pending_transaction_pending_for_pump(
    adm_ent_pending_transaction_typ * ent_pending_transaction,
    adm_rel_pending_transaction_pending_for_pump_typ * rel_pending_transaction_pending_for_pump,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_pending_transaction_pending_for_pump");
    #endif

    adm_object_existent_pending_transaction(
        ent_pending_transaction,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_pending_transaction_pending_for_pump->next !=
        (adm_base_integer_typ)rel_pending_transaction_pending_for_pump->ent_pump) {

        if (ent_pending_transaction->rel_pending_for_pump_head != NULL) {

            if (ent_pending_transaction->rel_pending_for_pump_head == rel_pending_transaction_pending_for_pump) {

                ent_pending_transaction->rel_pending_for_pump_head = rel_pending_transaction_pending_for_pump->next;

            } else {

                (rel_pending_transaction_pending_for_pump->back)->next = rel_pending_transaction_pending_for_pump->next;
            }

            if (ent_pending_transaction->rel_pending_for_pump_tail == rel_pending_transaction_pending_for_pump) {

                ent_pending_transaction->rel_pending_for_pump_tail = rel_pending_transaction_pending_for_pump->back;

            } else {

                (rel_pending_transaction_pending_for_pump->next)->back = rel_pending_transaction_pending_for_pump->back;
            }

            adm_deallocate_memory(rel_pending_transaction_pending_for_pump);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Pending_Transaction",
                ent_pending_transaction->identity,
                "Pending_for",
                "Pump");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Pending_Transaction",
            ent_pending_transaction->identity,
            "Pending_for",
            "Pump");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_pending_transaction_pending_for_pump");
    #endif
}


/* Object Existent */

void adm_object_existent_pending_transaction(
    const adm_ent_pending_transaction_typ * const ent_pending_transaction,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_pending_transaction");
    #endif

    if (ent_pending_transaction->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Pending_Transaction",
            ent_pending_transaction->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_pending_transaction");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */