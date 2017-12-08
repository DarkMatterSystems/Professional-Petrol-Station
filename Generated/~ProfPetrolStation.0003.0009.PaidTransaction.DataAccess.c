
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Paid Transaction Data Access */

/* Make Entity Object */

adm_ent_paid_transaction_typ * adm_make_object_paid_transaction(
    void)
{
    adm_ent_paid_transaction_typ * ent_paid_transaction;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_paid_transaction");
    #endif

    if (adm_entity_system.ent_paid_transaction.dead_list_head != NULL) {

        ent_paid_transaction = adm_entity_system.ent_paid_transaction.dead_list_head;

        if (adm_entity_system.ent_paid_transaction.dead_list_head == ent_paid_transaction) {

            adm_entity_system.ent_paid_transaction.dead_list_head = ent_paid_transaction->next;

        } else {

            (ent_paid_transaction->back)->next = ent_paid_transaction->next;
        }

        if (adm_entity_system.ent_paid_transaction.dead_list_tail == ent_paid_transaction) {

            adm_entity_system.ent_paid_transaction.dead_list_tail = ent_paid_transaction->back;

        } else {

            (ent_paid_transaction->next)->back = ent_paid_transaction->back;
        }

    } else {

        ent_paid_transaction = (adm_ent_paid_transaction_typ*)adm_allocate_memory(sizeof(adm_ent_paid_transaction_typ));
    }

    ent_paid_transaction->identity = ++adm_entity_system.ent_paid_transaction.tote;

    ent_paid_transaction->unique  = FALSE;
    ent_paid_transaction->deleted = FALSE;
    ent_paid_transaction->marked  = FALSE;
    ent_paid_transaction->ignore  = null;

    ent_paid_transaction->back = NULL;
    ent_paid_transaction->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_paid_transaction");
    #endif

    return (ent_paid_transaction);
}


/* Bind Entity Object */

void adm_bind_object_paid_transaction(
    adm_ent_paid_transaction_typ * ent_paid_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_paid_transaction");
    #endif

    adm_object_existent_paid_transaction(
        ent_paid_transaction,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_paid_transaction.live_list_head == NULL) {

        ent_paid_transaction->back = NULL;

        adm_entity_system.ent_paid_transaction.live_list_head = ent_paid_transaction;

    } else {

        ent_paid_transaction->back = adm_entity_system.ent_paid_transaction.live_list_tail;

        (adm_entity_system.ent_paid_transaction.live_list_tail)->next = ent_paid_transaction;
    }

    ent_paid_transaction->next = NULL;

    adm_entity_system.ent_paid_transaction.live_list_tail = ent_paid_transaction;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_paid_transaction");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_paid_transaction(
    void * source_object,
    adm_ent_paid_transaction_typ * ent_paid_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_paid_transaction");
    #endif

    adm_object_existent_paid_transaction(
        ent_paid_transaction,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_paid_transaction) {

        if (adm_entity_system.ent_paid_transaction.live_list_head == ent_paid_transaction) {

            adm_entity_system.ent_paid_transaction.live_list_head = ent_paid_transaction->next;

        } else {

            (ent_paid_transaction->back)->next = ent_paid_transaction->next;
        }

        if (adm_entity_system.ent_paid_transaction.live_list_tail == ent_paid_transaction) {

            adm_entity_system.ent_paid_transaction.live_list_tail = ent_paid_transaction->back;

        } else {

            (ent_paid_transaction->next)->back = ent_paid_transaction->back;
        }

        ent_paid_transaction->deleted = TRUE;

        if (adm_entity_system.ent_paid_transaction.dead_list_head == NULL) {

            ent_paid_transaction->back = NULL;

            adm_entity_system.ent_paid_transaction.dead_list_head = ent_paid_transaction;

        } else {

            ent_paid_transaction->back = adm_entity_system.ent_paid_transaction.dead_list_tail;

            (adm_entity_system.ent_paid_transaction.dead_list_tail)->next = ent_paid_transaction;
        }

        ent_paid_transaction->next = NULL;

        adm_entity_system.ent_paid_transaction.dead_list_tail = ent_paid_transaction;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Paid_Transaction",
            ent_paid_transaction->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_paid_transaction");
    #endif
}


/* Object Existent */

void adm_object_existent_paid_transaction(
    const adm_ent_paid_transaction_typ * const ent_paid_transaction,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_paid_transaction");
    #endif

    if (ent_paid_transaction->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Paid_Transaction",
            ent_paid_transaction->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_paid_transaction");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */