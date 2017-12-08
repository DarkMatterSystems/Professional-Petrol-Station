
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Transaction Policy Simulator Display Entity */

void adm_sim_display_entity_transaction_policy(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_transaction_policy_typ * ent_transaction_policy;

    adm_sim_width_transaction_policy_typ width_transaction_policy;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_transaction_policy");
    #endif

    width_transaction_policy.identity = strlen("Identity");
    width_transaction_policy.atb_next_transaction_number = strlen("Next_transaction_number");

    ent_transaction_policy = adm_entity_system.ent_transaction_policy.live_list_head;

    while (ent_transaction_policy != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_transaction_policy->identity);
        if (width > width_transaction_policy.identity) width_transaction_policy.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_transaction_policy->atb_next_transaction_number);
        if (width > width_transaction_policy.atb_next_transaction_number) width_transaction_policy.atb_next_transaction_number = width;

        ent_transaction_policy = ent_transaction_policy->next;
    }

    printf(NEWLINE);
    printf("Transaction_Policy:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_transaction_policy.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_transaction_policy.atb_next_transaction_number, "Next_transaction_number");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_transaction_policy.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_transaction_policy.atb_next_transaction_number);

    ent_transaction_policy = adm_entity_system.ent_transaction_policy.live_list_head;

    while (ent_transaction_policy != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_transaction_policy.identity, ent_transaction_policy->identity);
        printf(ADM_SIM_COLUMN_GAP);
        printf("%*d", width_transaction_policy.atb_next_transaction_number, ent_transaction_policy->atb_next_transaction_number);

        ent_transaction_policy = ent_transaction_policy->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_transaction_policy");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */