
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Check Pump Identifiers Unique */

void adm_check_identifiers_unique_pump(
    adm_ent_pump_typ * ent_source_pump,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_ent_pump_typ * ent_target_pump;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_IDENTIFIER, "adm_check_identifiers_unique_pump");
    #endif

    ent_target_pump = adm_entity_system.ent_pump.live_list_head;

    while (ent_target_pump != NULL) {

        if (
            ent_target_pump->atb_pump_number == ent_source_pump->atb_pump_number) {

            adm_error_report(
                ADM_ERROR_OBJECT_IDENTIFIER_ATTRIBUTES_NOT_UNIQUE,
                error_file, error_line, error_rank,
                "Pump",
                ent_target_pump->identity,
                NULL,
                NULL);
        }

        ent_target_pump = ent_target_pump->next;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_IDENTIFIER, "adm_check_identifiers_unique_pump");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */