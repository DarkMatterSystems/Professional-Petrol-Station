
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Transaction Policy Data Access */

/* Make Entity Object */

adm_ent_transaction_policy_typ * adm_make_object_transaction_policy(
    void)
{
    adm_ent_transaction_policy_typ * ent_transaction_policy;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_transaction_policy");
    #endif

    if (adm_entity_system.ent_transaction_policy.dead_list_head != NULL) {

        ent_transaction_policy = adm_entity_system.ent_transaction_policy.dead_list_head;

        if (adm_entity_system.ent_transaction_policy.dead_list_head == ent_transaction_policy) {

            adm_entity_system.ent_transaction_policy.dead_list_head = ent_transaction_policy->next;

        } else {

            (ent_transaction_policy->back)->next = ent_transaction_policy->next;
        }

        if (adm_entity_system.ent_transaction_policy.dead_list_tail == ent_transaction_policy) {

            adm_entity_system.ent_transaction_policy.dead_list_tail = ent_transaction_policy->back;

        } else {

            (ent_transaction_policy->next)->back = ent_transaction_policy->back;
        }

    } else {

        ent_transaction_policy = (adm_ent_transaction_policy_typ*)adm_allocate_memory(sizeof(adm_ent_transaction_policy_typ));
    }

    ent_transaction_policy->identity = ++adm_entity_system.ent_transaction_policy.tote;

    ent_transaction_policy->unique  = FALSE;
    ent_transaction_policy->deleted = FALSE;
    ent_transaction_policy->marked  = FALSE;
    ent_transaction_policy->ignore  = null;

    ent_transaction_policy->back = NULL;
    ent_transaction_policy->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_transaction_policy");
    #endif

    return (ent_transaction_policy);
}


/* Bind Entity Object */

void adm_bind_object_transaction_policy(
    adm_ent_transaction_policy_typ * ent_transaction_policy,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_transaction_policy");
    #endif

    adm_object_existent_transaction_policy(
        ent_transaction_policy,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_transaction_policy.live_list_head == NULL) {

        ent_transaction_policy->back = NULL;

        adm_entity_system.ent_transaction_policy.live_list_head = ent_transaction_policy;

    } else {

        ent_transaction_policy->back = adm_entity_system.ent_transaction_policy.live_list_tail;

        (adm_entity_system.ent_transaction_policy.live_list_tail)->next = ent_transaction_policy;
    }

    ent_transaction_policy->next = NULL;

    adm_entity_system.ent_transaction_policy.live_list_tail = ent_transaction_policy;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_transaction_policy");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_transaction_policy(
    void * source_object,
    adm_ent_transaction_policy_typ * ent_transaction_policy,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_transaction_policy");
    #endif

    adm_object_existent_transaction_policy(
        ent_transaction_policy,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_transaction_policy) {

        if (adm_entity_system.ent_transaction_policy.live_list_head == ent_transaction_policy) {

            adm_entity_system.ent_transaction_policy.live_list_head = ent_transaction_policy->next;

        } else {

            (ent_transaction_policy->back)->next = ent_transaction_policy->next;
        }

        if (adm_entity_system.ent_transaction_policy.live_list_tail == ent_transaction_policy) {

            adm_entity_system.ent_transaction_policy.live_list_tail = ent_transaction_policy->back;

        } else {

            (ent_transaction_policy->next)->back = ent_transaction_policy->back;
        }

        ent_transaction_policy->deleted = TRUE;

        if (adm_entity_system.ent_transaction_policy.dead_list_head == NULL) {

            ent_transaction_policy->back = NULL;

            adm_entity_system.ent_transaction_policy.dead_list_head = ent_transaction_policy;

        } else {

            ent_transaction_policy->back = adm_entity_system.ent_transaction_policy.dead_list_tail;

            (adm_entity_system.ent_transaction_policy.dead_list_tail)->next = ent_transaction_policy;
        }

        ent_transaction_policy->next = NULL;

        adm_entity_system.ent_transaction_policy.dead_list_tail = ent_transaction_policy;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Transaction_Policy",
            ent_transaction_policy->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_transaction_policy");
    #endif
}


/* Object Existent */

void adm_object_existent_transaction_policy(
    const adm_ent_transaction_policy_typ * const ent_transaction_policy,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_transaction_policy");
    #endif

    if (ent_transaction_policy->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Transaction_Policy",
            ent_transaction_policy->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_transaction_policy");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */