
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Paid Transaction Simulator Display Entity */

void adm_sim_display_entity_paid_transaction(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_paid_transaction_typ * ent_paid_transaction;

    adm_sim_width_paid_transaction_typ width_paid_transaction;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_paid_transaction");
    #endif

    width_paid_transaction.identity = strlen("Identity");

    ent_paid_transaction = adm_entity_system.ent_paid_transaction.live_list_head;

    while (ent_paid_transaction != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_paid_transaction->identity);
        if (width > width_paid_transaction.identity) width_paid_transaction.identity = width;

        ent_paid_transaction = ent_paid_transaction->next;
    }

    printf(NEWLINE);
    printf("Paid_Transaction:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_paid_transaction.identity, "Identity");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_paid_transaction.identity);

    ent_paid_transaction = adm_entity_system.ent_paid_transaction.live_list_head;

    while (ent_paid_transaction != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_paid_transaction.identity, ent_paid_transaction->identity);

        ent_paid_transaction = ent_paid_transaction->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_paid_transaction");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */