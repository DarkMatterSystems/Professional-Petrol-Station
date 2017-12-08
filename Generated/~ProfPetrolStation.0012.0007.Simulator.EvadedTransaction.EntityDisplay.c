
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Evaded Transaction Simulator Display Entity */

void adm_sim_display_entity_evaded_transaction(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_evaded_transaction_typ * ent_evaded_transaction;

    adm_sim_width_evaded_transaction_typ width_evaded_transaction;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_evaded_transaction");
    #endif

    width_evaded_transaction.identity = strlen("Identity");
    width_evaded_transaction.atb_observations = strlen("Observations");

    ent_evaded_transaction = adm_entity_system.ent_evaded_transaction.live_list_head;

    while (ent_evaded_transaction != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_evaded_transaction->identity);
        if (width > width_evaded_transaction.identity) width_evaded_transaction.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_evaded_transaction->atb_observations);
        if (width > width_evaded_transaction.atb_observations) width_evaded_transaction.atb_observations = width;

        ent_evaded_transaction = ent_evaded_transaction->next;
    }

    printf(NEWLINE);
    printf("Evaded_Transaction:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_evaded_transaction.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_evaded_transaction.atb_observations, "Observations");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_evaded_transaction.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_evaded_transaction.atb_observations);

    ent_evaded_transaction = adm_entity_system.ent_evaded_transaction.live_list_head;

    while (ent_evaded_transaction != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_evaded_transaction.identity, ent_evaded_transaction->identity);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_evaded_transaction->atb_observations);
        printf("%-*s", width_evaded_transaction.atb_observations, buffer);

        ent_evaded_transaction = ent_evaded_transaction->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_evaded_transaction");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */