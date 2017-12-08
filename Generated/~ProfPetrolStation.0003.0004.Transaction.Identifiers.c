
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Check Transaction Identifiers Unique */

void adm_check_identifiers_unique_transaction(
    adm_ent_transaction_typ * ent_source_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_ent_transaction_typ * ent_target_transaction;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_IDENTIFIER, "adm_check_identifiers_unique_transaction");
    #endif

    ent_target_transaction = adm_entity_system.ent_transaction.live_list_head;

    while (ent_target_transaction != NULL) {

        if (
            ent_target_transaction->atb_transaction_number == ent_source_transaction->atb_transaction_number) {

            adm_error_report(
                ADM_ERROR_OBJECT_IDENTIFIER_ATTRIBUTES_NOT_UNIQUE,
                error_file, error_line, error_rank,
                "Transaction",
                ent_target_transaction->identity,
                NULL,
                NULL);
        }

        ent_target_transaction = ent_target_transaction->next;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_IDENTIFIER, "adm_check_identifiers_unique_transaction");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */