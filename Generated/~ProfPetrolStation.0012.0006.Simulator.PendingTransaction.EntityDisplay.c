
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Pending Transaction Simulator Display Entity */

void adm_sim_display_entity_pending_transaction(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_pending_transaction_typ * ent_pending_transaction;

    adm_sim_width_pending_transaction_typ width_pending_transaction;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_pending_transaction");
    #endif

    width_pending_transaction.identity = strlen("Identity");

    ent_pending_transaction = adm_entity_system.ent_pending_transaction.live_list_head;

    while (ent_pending_transaction != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_pending_transaction->identity);
        if (width > width_pending_transaction.identity) width_pending_transaction.identity = width;

        ent_pending_transaction = ent_pending_transaction->next;
    }

    printf(NEWLINE);
    printf("Pending_Transaction:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_pending_transaction.identity, "Identity");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_pending_transaction.identity);

    ent_pending_transaction = adm_entity_system.ent_pending_transaction.live_list_head;

    while (ent_pending_transaction != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_pending_transaction.identity, ent_pending_transaction->identity);

        ent_pending_transaction = ent_pending_transaction->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_pending_transaction");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */