
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Evaded Transaction Data Access */

/* Make Entity Object */

adm_ent_evaded_transaction_typ * adm_make_object_evaded_transaction(
    void)
{
    adm_ent_evaded_transaction_typ * ent_evaded_transaction;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_evaded_transaction");
    #endif

    if (adm_entity_system.ent_evaded_transaction.dead_list_head != NULL) {

        ent_evaded_transaction = adm_entity_system.ent_evaded_transaction.dead_list_head;

        if (adm_entity_system.ent_evaded_transaction.dead_list_head == ent_evaded_transaction) {

            adm_entity_system.ent_evaded_transaction.dead_list_head = ent_evaded_transaction->next;

        } else {

            (ent_evaded_transaction->back)->next = ent_evaded_transaction->next;
        }

        if (adm_entity_system.ent_evaded_transaction.dead_list_tail == ent_evaded_transaction) {

            adm_entity_system.ent_evaded_transaction.dead_list_tail = ent_evaded_transaction->back;

        } else {

            (ent_evaded_transaction->next)->back = ent_evaded_transaction->back;
        }

    } else {

        ent_evaded_transaction = (adm_ent_evaded_transaction_typ*)adm_allocate_memory(sizeof(adm_ent_evaded_transaction_typ));
    }

    ent_evaded_transaction->identity = ++adm_entity_system.ent_evaded_transaction.tote;

    ent_evaded_transaction->unique  = FALSE;
    ent_evaded_transaction->deleted = FALSE;
    ent_evaded_transaction->marked  = FALSE;
    ent_evaded_transaction->ignore  = null;

    ent_evaded_transaction->atb_observations = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);

    ent_evaded_transaction->back = NULL;
    ent_evaded_transaction->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_evaded_transaction");
    #endif

    return (ent_evaded_transaction);
}


/* Bind Entity Object */

void adm_bind_object_evaded_transaction(
    adm_ent_evaded_transaction_typ * ent_evaded_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_evaded_transaction");
    #endif

    adm_object_existent_evaded_transaction(
        ent_evaded_transaction,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_evaded_transaction.live_list_head == NULL) {

        ent_evaded_transaction->back = NULL;

        adm_entity_system.ent_evaded_transaction.live_list_head = ent_evaded_transaction;

    } else {

        ent_evaded_transaction->back = adm_entity_system.ent_evaded_transaction.live_list_tail;

        (adm_entity_system.ent_evaded_transaction.live_list_tail)->next = ent_evaded_transaction;
    }

    ent_evaded_transaction->next = NULL;

    adm_entity_system.ent_evaded_transaction.live_list_tail = ent_evaded_transaction;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_evaded_transaction");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_evaded_transaction(
    void * source_object,
    adm_ent_evaded_transaction_typ * ent_evaded_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_evaded_transaction");
    #endif

    adm_object_existent_evaded_transaction(
        ent_evaded_transaction,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_evaded_transaction) {

        if (adm_entity_system.ent_evaded_transaction.live_list_head == ent_evaded_transaction) {

            adm_entity_system.ent_evaded_transaction.live_list_head = ent_evaded_transaction->next;

        } else {

            (ent_evaded_transaction->back)->next = ent_evaded_transaction->next;
        }

        if (adm_entity_system.ent_evaded_transaction.live_list_tail == ent_evaded_transaction) {

            adm_entity_system.ent_evaded_transaction.live_list_tail = ent_evaded_transaction->back;

        } else {

            (ent_evaded_transaction->next)->back = ent_evaded_transaction->back;
        }

        adm_deallocate_memory(ent_evaded_transaction->atb_observations);

        ent_evaded_transaction->deleted = TRUE;

        if (adm_entity_system.ent_evaded_transaction.dead_list_head == NULL) {

            ent_evaded_transaction->back = NULL;

            adm_entity_system.ent_evaded_transaction.dead_list_head = ent_evaded_transaction;

        } else {

            ent_evaded_transaction->back = adm_entity_system.ent_evaded_transaction.dead_list_tail;

            (adm_entity_system.ent_evaded_transaction.dead_list_tail)->next = ent_evaded_transaction;
        }

        ent_evaded_transaction->next = NULL;

        adm_entity_system.ent_evaded_transaction.dead_list_tail = ent_evaded_transaction;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Evaded_Transaction",
            ent_evaded_transaction->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_evaded_transaction");
    #endif
}


/* Object Existent */

void adm_object_existent_evaded_transaction(
    const adm_ent_evaded_transaction_typ * const ent_evaded_transaction,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_evaded_transaction");
    #endif

    if (ent_evaded_transaction->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Evaded_Transaction",
            ent_evaded_transaction->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_evaded_transaction");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */