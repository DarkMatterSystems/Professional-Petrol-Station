
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Transaction Data Access */

/* Make Entity Object */

adm_ent_transaction_typ * adm_make_object_transaction(
    adm_sta_transaction_typ status)
{
    adm_ent_transaction_typ * ent_transaction;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_transaction");
    #endif

    if (adm_entity_system.ent_transaction.dead_list_head != NULL) {

        ent_transaction = adm_entity_system.ent_transaction.dead_list_head;

        if (adm_entity_system.ent_transaction.dead_list_head == ent_transaction) {

            adm_entity_system.ent_transaction.dead_list_head = ent_transaction->next;

        } else {

            (ent_transaction->back)->next = ent_transaction->next;
        }

        if (adm_entity_system.ent_transaction.dead_list_tail == ent_transaction) {

            adm_entity_system.ent_transaction.dead_list_tail = ent_transaction->back;

        } else {

            (ent_transaction->next)->back = ent_transaction->back;
        }

    } else {

        ent_transaction = (adm_ent_transaction_typ*)adm_allocate_memory(sizeof(adm_ent_transaction_typ));
    }

    ent_transaction->identity = ++adm_entity_system.ent_transaction.tote;

    ent_transaction->unique  = FALSE;
    ent_transaction->deleted = FALSE;
    ent_transaction->marked  = FALSE;
    ent_transaction->status  = status;

    ent_transaction->rel_governed_by_transaction_policy_head = NULL;
    ent_transaction->rel_governed_by_transaction_policy_tail = NULL;

    ent_transaction->rel_generalisation_pending_transaction_head = NULL;
    ent_transaction->rel_generalisation_pending_transaction_tail = NULL;

    ent_transaction->rel_generalisation_paid_transaction_head = NULL;
    ent_transaction->rel_generalisation_paid_transaction_tail = NULL;

    ent_transaction->rel_generalisation_evaded_transaction_head = NULL;
    ent_transaction->rel_generalisation_evaded_transaction_tail = NULL;

    ent_transaction->back = NULL;
    ent_transaction->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_transaction");
    #endif

    return (ent_transaction);
}


/* Bind Entity Object */

void adm_bind_object_transaction(
    adm_ent_transaction_typ * ent_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_transaction");
    #endif

    adm_object_existent_transaction(
        ent_transaction,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_transaction.live_list_head == NULL) {

        ent_transaction->back = NULL;

        adm_entity_system.ent_transaction.live_list_head = ent_transaction;

    } else {

        ent_transaction->back = adm_entity_system.ent_transaction.live_list_tail;

        (adm_entity_system.ent_transaction.live_list_tail)->next = ent_transaction;
    }

    ent_transaction->next = NULL;

    adm_entity_system.ent_transaction.live_list_tail = ent_transaction;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_transaction");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_transaction(
    void * source_object,
    adm_ent_transaction_typ * ent_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_transaction");
    #endif

    adm_object_existent_transaction(
        ent_transaction,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_transaction) {

        if (ent_transaction->rel_governed_by_transaction_policy_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Transaction",
                ent_transaction->identity,
                "Governed_by",
                "Transaction_Policy");
        }

        if (ent_transaction->rel_generalisation_pending_transaction_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Transaction",
                ent_transaction->identity,
                "Generalisation",
                "Pending_Transaction");
        }

        if (ent_transaction->rel_generalisation_paid_transaction_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Transaction",
                ent_transaction->identity,
                "Generalisation",
                "Paid_Transaction");
        }

        if (ent_transaction->rel_generalisation_evaded_transaction_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Transaction",
                ent_transaction->identity,
                "Generalisation",
                "Evaded_Transaction");
        }

        if (adm_entity_system.ent_transaction.live_list_head == ent_transaction) {

            adm_entity_system.ent_transaction.live_list_head = ent_transaction->next;

        } else {

            (ent_transaction->back)->next = ent_transaction->next;
        }

        if (adm_entity_system.ent_transaction.live_list_tail == ent_transaction) {

            adm_entity_system.ent_transaction.live_list_tail = ent_transaction->back;

        } else {

            (ent_transaction->next)->back = ent_transaction->back;
        }

        ent_transaction->deleted = TRUE;

        if (adm_entity_system.ent_transaction.dead_list_head == NULL) {

            ent_transaction->back = NULL;

            adm_entity_system.ent_transaction.dead_list_head = ent_transaction;

        } else {

            ent_transaction->back = adm_entity_system.ent_transaction.dead_list_tail;

            (adm_entity_system.ent_transaction.dead_list_tail)->next = ent_transaction;
        }

        ent_transaction->next = NULL;

        adm_entity_system.ent_transaction.dead_list_tail = ent_transaction;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Transaction",
            ent_transaction->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_transaction");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_transaction_governed_by_transaction_policy(
    adm_ent_transaction_typ * ent_source_transaction,
    adm_ent_transaction_policy_typ * ent_target_transaction_policy,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_transaction_governed_by_transaction_policy_typ * rel_transaction_governed_by_transaction_policy;

    adm_base_boolean_typ transaction_policy_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_transaction_governed_by_transaction_policy");
    #endif

    adm_object_existent_transaction(
        ent_source_transaction,
        error_file,
        error_line,
        error_rank);

    transaction_policy_not_found = TRUE;

    rel_transaction_governed_by_transaction_policy = ent_source_transaction->rel_governed_by_transaction_policy_head;

    while (
        transaction_policy_not_found &&
        rel_transaction_governed_by_transaction_policy != NULL) {

        if (rel_transaction_governed_by_transaction_policy->ent_transaction_policy == ent_target_transaction_policy) {

            transaction_policy_not_found = FALSE;
        }

        rel_transaction_governed_by_transaction_policy = rel_transaction_governed_by_transaction_policy->next;
    }

    if (transaction_policy_not_found) {

        rel_transaction_governed_by_transaction_policy = (adm_rel_transaction_governed_by_transaction_policy_typ*)
            adm_allocate_memory(sizeof(adm_rel_transaction_governed_by_transaction_policy_typ));

        rel_transaction_governed_by_transaction_policy->ent_transaction_policy = ent_target_transaction_policy;

        if (ent_source_transaction->rel_governed_by_transaction_policy_head == NULL) {

            rel_transaction_governed_by_transaction_policy->back = NULL;

            ent_source_transaction->rel_governed_by_transaction_policy_head = rel_transaction_governed_by_transaction_policy;

        } else {

            rel_transaction_governed_by_transaction_policy->back = ent_source_transaction->rel_governed_by_transaction_policy_tail;

            (ent_source_transaction->rel_governed_by_transaction_policy_tail)->next = rel_transaction_governed_by_transaction_policy;
        }

        rel_transaction_governed_by_transaction_policy->next = NULL;

        ent_source_transaction->rel_governed_by_transaction_policy_tail = rel_transaction_governed_by_transaction_policy;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Transaction",
            ent_source_transaction->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_transaction_governed_by_transaction_policy");
    #endif
}

void adm_link_relation_transaction_generalisation_pending_transaction(
    adm_ent_transaction_typ * ent_source_transaction,
    adm_ent_pending_transaction_typ * ent_target_pending_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_transaction_generalisation_pending_transaction_typ * rel_transaction_generalisation_pending_transaction;

    adm_base_boolean_typ pending_transaction_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_transaction_generalisation_pending_transaction");
    #endif

    adm_object_existent_transaction(
        ent_source_transaction,
        error_file,
        error_line,
        error_rank);

    pending_transaction_not_found = TRUE;

    rel_transaction_generalisation_pending_transaction = ent_source_transaction->rel_generalisation_pending_transaction_head;

    while (
        pending_transaction_not_found &&
        rel_transaction_generalisation_pending_transaction != NULL) {

        if (rel_transaction_generalisation_pending_transaction->ent_pending_transaction == ent_target_pending_transaction) {

            pending_transaction_not_found = FALSE;
        }

        rel_transaction_generalisation_pending_transaction = rel_transaction_generalisation_pending_transaction->next;
    }

    if (pending_transaction_not_found) {

        rel_transaction_generalisation_pending_transaction = (adm_rel_transaction_generalisation_pending_transaction_typ*)
            adm_allocate_memory(sizeof(adm_rel_transaction_generalisation_pending_transaction_typ));

        rel_transaction_generalisation_pending_transaction->ent_pending_transaction = ent_target_pending_transaction;

        if (ent_source_transaction->rel_generalisation_pending_transaction_head == NULL) {

            rel_transaction_generalisation_pending_transaction->back = NULL;

            ent_source_transaction->rel_generalisation_pending_transaction_head = rel_transaction_generalisation_pending_transaction;

        } else {

            rel_transaction_generalisation_pending_transaction->back = ent_source_transaction->rel_generalisation_pending_transaction_tail;

            (ent_source_transaction->rel_generalisation_pending_transaction_tail)->next = rel_transaction_generalisation_pending_transaction;
        }

        rel_transaction_generalisation_pending_transaction->next = NULL;

        ent_source_transaction->rel_generalisation_pending_transaction_tail = rel_transaction_generalisation_pending_transaction;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Transaction",
            ent_source_transaction->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_transaction_generalisation_pending_transaction");
    #endif
}

void adm_link_relation_transaction_generalisation_paid_transaction(
    adm_ent_transaction_typ * ent_source_transaction,
    adm_ent_paid_transaction_typ * ent_target_paid_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_transaction_generalisation_paid_transaction_typ * rel_transaction_generalisation_paid_transaction;

    adm_base_boolean_typ paid_transaction_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_transaction_generalisation_paid_transaction");
    #endif

    adm_object_existent_transaction(
        ent_source_transaction,
        error_file,
        error_line,
        error_rank);

    paid_transaction_not_found = TRUE;

    rel_transaction_generalisation_paid_transaction = ent_source_transaction->rel_generalisation_paid_transaction_head;

    while (
        paid_transaction_not_found &&
        rel_transaction_generalisation_paid_transaction != NULL) {

        if (rel_transaction_generalisation_paid_transaction->ent_paid_transaction == ent_target_paid_transaction) {

            paid_transaction_not_found = FALSE;
        }

        rel_transaction_generalisation_paid_transaction = rel_transaction_generalisation_paid_transaction->next;
    }

    if (paid_transaction_not_found) {

        rel_transaction_generalisation_paid_transaction = (adm_rel_transaction_generalisation_paid_transaction_typ*)
            adm_allocate_memory(sizeof(adm_rel_transaction_generalisation_paid_transaction_typ));

        rel_transaction_generalisation_paid_transaction->ent_paid_transaction = ent_target_paid_transaction;

        if (ent_source_transaction->rel_generalisation_paid_transaction_head == NULL) {

            rel_transaction_generalisation_paid_transaction->back = NULL;

            ent_source_transaction->rel_generalisation_paid_transaction_head = rel_transaction_generalisation_paid_transaction;

        } else {

            rel_transaction_generalisation_paid_transaction->back = ent_source_transaction->rel_generalisation_paid_transaction_tail;

            (ent_source_transaction->rel_generalisation_paid_transaction_tail)->next = rel_transaction_generalisation_paid_transaction;
        }

        rel_transaction_generalisation_paid_transaction->next = NULL;

        ent_source_transaction->rel_generalisation_paid_transaction_tail = rel_transaction_generalisation_paid_transaction;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Transaction",
            ent_source_transaction->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_transaction_generalisation_paid_transaction");
    #endif
}

void adm_link_relation_transaction_generalisation_evaded_transaction(
    adm_ent_transaction_typ * ent_source_transaction,
    adm_ent_evaded_transaction_typ * ent_target_evaded_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_transaction_generalisation_evaded_transaction_typ * rel_transaction_generalisation_evaded_transaction;

    adm_base_boolean_typ evaded_transaction_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_transaction_generalisation_evaded_transaction");
    #endif

    adm_object_existent_transaction(
        ent_source_transaction,
        error_file,
        error_line,
        error_rank);

    evaded_transaction_not_found = TRUE;

    rel_transaction_generalisation_evaded_transaction = ent_source_transaction->rel_generalisation_evaded_transaction_head;

    while (
        evaded_transaction_not_found &&
        rel_transaction_generalisation_evaded_transaction != NULL) {

        if (rel_transaction_generalisation_evaded_transaction->ent_evaded_transaction == ent_target_evaded_transaction) {

            evaded_transaction_not_found = FALSE;
        }

        rel_transaction_generalisation_evaded_transaction = rel_transaction_generalisation_evaded_transaction->next;
    }

    if (evaded_transaction_not_found) {

        rel_transaction_generalisation_evaded_transaction = (adm_rel_transaction_generalisation_evaded_transaction_typ*)
            adm_allocate_memory(sizeof(adm_rel_transaction_generalisation_evaded_transaction_typ));

        rel_transaction_generalisation_evaded_transaction->ent_evaded_transaction = ent_target_evaded_transaction;

        if (ent_source_transaction->rel_generalisation_evaded_transaction_head == NULL) {

            rel_transaction_generalisation_evaded_transaction->back = NULL;

            ent_source_transaction->rel_generalisation_evaded_transaction_head = rel_transaction_generalisation_evaded_transaction;

        } else {

            rel_transaction_generalisation_evaded_transaction->back = ent_source_transaction->rel_generalisation_evaded_transaction_tail;

            (ent_source_transaction->rel_generalisation_evaded_transaction_tail)->next = rel_transaction_generalisation_evaded_transaction;
        }

        rel_transaction_generalisation_evaded_transaction->next = NULL;

        ent_source_transaction->rel_generalisation_evaded_transaction_tail = rel_transaction_generalisation_evaded_transaction;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Transaction",
            ent_source_transaction->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_transaction_generalisation_evaded_transaction");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_transaction_governed_by_transaction_policy(
    adm_ent_transaction_typ * ent_transaction,
    adm_rel_transaction_governed_by_transaction_policy_typ * rel_transaction_governed_by_transaction_policy,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_transaction_governed_by_transaction_policy");
    #endif

    adm_object_existent_transaction(
        ent_transaction,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_transaction_governed_by_transaction_policy->next !=
        (adm_base_integer_typ)rel_transaction_governed_by_transaction_policy->ent_transaction_policy) {

        if (ent_transaction->rel_governed_by_transaction_policy_head != NULL) {

            if (ent_transaction->rel_governed_by_transaction_policy_head == rel_transaction_governed_by_transaction_policy) {

                ent_transaction->rel_governed_by_transaction_policy_head = rel_transaction_governed_by_transaction_policy->next;

            } else {

                (rel_transaction_governed_by_transaction_policy->back)->next = rel_transaction_governed_by_transaction_policy->next;
            }

            if (ent_transaction->rel_governed_by_transaction_policy_tail == rel_transaction_governed_by_transaction_policy) {

                ent_transaction->rel_governed_by_transaction_policy_tail = rel_transaction_governed_by_transaction_policy->back;

            } else {

                (rel_transaction_governed_by_transaction_policy->next)->back = rel_transaction_governed_by_transaction_policy->back;
            }

            adm_deallocate_memory(rel_transaction_governed_by_transaction_policy);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Transaction",
                ent_transaction->identity,
                "Governed_by",
                "Transaction_Policy");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Transaction",
            ent_transaction->identity,
            "Governed_by",
            "Transaction_Policy");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_transaction_governed_by_transaction_policy");
    #endif
}

void adm_kill_relation_transaction_generalisation_pending_transaction(
    adm_ent_transaction_typ * ent_transaction,
    adm_rel_transaction_generalisation_pending_transaction_typ * rel_transaction_generalisation_pending_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_transaction_generalisation_pending_transaction");
    #endif

    adm_object_existent_transaction(
        ent_transaction,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_transaction_generalisation_pending_transaction->next !=
        (adm_base_integer_typ)rel_transaction_generalisation_pending_transaction->ent_pending_transaction) {

        if (ent_transaction->rel_generalisation_pending_transaction_head != NULL) {

            if (ent_transaction->rel_generalisation_pending_transaction_head == rel_transaction_generalisation_pending_transaction) {

                ent_transaction->rel_generalisation_pending_transaction_head = rel_transaction_generalisation_pending_transaction->next;

            } else {

                (rel_transaction_generalisation_pending_transaction->back)->next = rel_transaction_generalisation_pending_transaction->next;
            }

            if (ent_transaction->rel_generalisation_pending_transaction_tail == rel_transaction_generalisation_pending_transaction) {

                ent_transaction->rel_generalisation_pending_transaction_tail = rel_transaction_generalisation_pending_transaction->back;

            } else {

                (rel_transaction_generalisation_pending_transaction->next)->back = rel_transaction_generalisation_pending_transaction->back;
            }

            adm_deallocate_memory(rel_transaction_generalisation_pending_transaction);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Transaction",
                ent_transaction->identity,
                "Generalisation",
                "Pending_Transaction");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Transaction",
            ent_transaction->identity,
            "Generalisation",
            "Pending_Transaction");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_transaction_generalisation_pending_transaction");
    #endif
}

void adm_kill_relation_transaction_generalisation_paid_transaction(
    adm_ent_transaction_typ * ent_transaction,
    adm_rel_transaction_generalisation_paid_transaction_typ * rel_transaction_generalisation_paid_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_transaction_generalisation_paid_transaction");
    #endif

    adm_object_existent_transaction(
        ent_transaction,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_transaction_generalisation_paid_transaction->next !=
        (adm_base_integer_typ)rel_transaction_generalisation_paid_transaction->ent_paid_transaction) {

        if (ent_transaction->rel_generalisation_paid_transaction_head != NULL) {

            if (ent_transaction->rel_generalisation_paid_transaction_head == rel_transaction_generalisation_paid_transaction) {

                ent_transaction->rel_generalisation_paid_transaction_head = rel_transaction_generalisation_paid_transaction->next;

            } else {

                (rel_transaction_generalisation_paid_transaction->back)->next = rel_transaction_generalisation_paid_transaction->next;
            }

            if (ent_transaction->rel_generalisation_paid_transaction_tail == rel_transaction_generalisation_paid_transaction) {

                ent_transaction->rel_generalisation_paid_transaction_tail = rel_transaction_generalisation_paid_transaction->back;

            } else {

                (rel_transaction_generalisation_paid_transaction->next)->back = rel_transaction_generalisation_paid_transaction->back;
            }

            adm_deallocate_memory(rel_transaction_generalisation_paid_transaction);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Transaction",
                ent_transaction->identity,
                "Generalisation",
                "Paid_Transaction");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Transaction",
            ent_transaction->identity,
            "Generalisation",
            "Paid_Transaction");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_transaction_generalisation_paid_transaction");
    #endif
}

void adm_kill_relation_transaction_generalisation_evaded_transaction(
    adm_ent_transaction_typ * ent_transaction,
    adm_rel_transaction_generalisation_evaded_transaction_typ * rel_transaction_generalisation_evaded_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_transaction_generalisation_evaded_transaction");
    #endif

    adm_object_existent_transaction(
        ent_transaction,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_transaction_generalisation_evaded_transaction->next !=
        (adm_base_integer_typ)rel_transaction_generalisation_evaded_transaction->ent_evaded_transaction) {

        if (ent_transaction->rel_generalisation_evaded_transaction_head != NULL) {

            if (ent_transaction->rel_generalisation_evaded_transaction_head == rel_transaction_generalisation_evaded_transaction) {

                ent_transaction->rel_generalisation_evaded_transaction_head = rel_transaction_generalisation_evaded_transaction->next;

            } else {

                (rel_transaction_generalisation_evaded_transaction->back)->next = rel_transaction_generalisation_evaded_transaction->next;
            }

            if (ent_transaction->rel_generalisation_evaded_transaction_tail == rel_transaction_generalisation_evaded_transaction) {

                ent_transaction->rel_generalisation_evaded_transaction_tail = rel_transaction_generalisation_evaded_transaction->back;

            } else {

                (rel_transaction_generalisation_evaded_transaction->next)->back = rel_transaction_generalisation_evaded_transaction->back;
            }

            adm_deallocate_memory(rel_transaction_generalisation_evaded_transaction);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Transaction",
                ent_transaction->identity,
                "Generalisation",
                "Evaded_Transaction");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Transaction",
            ent_transaction->identity,
            "Generalisation",
            "Evaded_Transaction");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_transaction_generalisation_evaded_transaction");
    #endif
}


/* Object Existent */

void adm_object_existent_transaction(
    const adm_ent_transaction_typ * const ent_transaction,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_transaction");
    #endif

    if (ent_transaction->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Transaction",
            ent_transaction->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_transaction");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */