
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Check Tank Identifiers Unique */

void adm_check_identifiers_unique_tank(
    adm_ent_tank_typ * ent_source_tank,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_ent_tank_typ * ent_target_tank;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_IDENTIFIER, "adm_check_identifiers_unique_tank");
    #endif

    ent_target_tank = adm_entity_system.ent_tank.live_list_head;

    while (ent_target_tank != NULL) {

        if (
            ent_target_tank->atb_tank_number == ent_source_tank->atb_tank_number) {

            adm_error_report(
                ADM_ERROR_OBJECT_IDENTIFIER_ATTRIBUTES_NOT_UNIQUE,
                error_file, error_line, error_rank,
                "Tank",
                ent_target_tank->identity,
                NULL,
                NULL);
        }

        ent_target_tank = ent_target_tank->next;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_IDENTIFIER, "adm_check_identifiers_unique_tank");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */