
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Check Delivery Identifiers Unique */

void adm_check_identifiers_unique_delivery(
    adm_ent_delivery_typ * ent_source_delivery,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_ent_delivery_typ * ent_target_delivery;

    adm_ent_pump_typ * ent_pump;

    adm_rel_delivery_being_made_using_pump_typ * rel_delivery_being_made_using_pump;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_IDENTIFIER, "adm_check_identifiers_unique_delivery");
    #endif

    if (!(
        ent_source_delivery->rel_being_made_using_pump_head == NULL ||
        ent_source_delivery->rel_being_made_using_pump_head !=
        ent_source_delivery->rel_being_made_using_pump_tail)) {

        rel_delivery_being_made_using_pump = ent_source_delivery->rel_being_made_using_pump_head;

        ent_pump = rel_delivery_being_made_using_pump->ent_pump;

    } else {

        adm_error_report(
            ADM_ERROR_FOREIGN_KEY_IDENTIFIER_RELATION_INVALID,
            error_file, error_line, error_rank,
            "Delivery",
            ent_source_delivery->identity,
            "Being_made_using",
            "Pump");
    }

    ent_target_delivery = adm_entity_system.ent_delivery.live_list_head;

    while (ent_target_delivery != NULL) {

        if (
            ((
                ent_target_delivery->rel_being_made_using_pump_head)->
                ent_pump)->atb_pump_number == ent_pump->atb_pump_number) {

            adm_error_report(
                ADM_ERROR_OBJECT_IDENTIFIER_ATTRIBUTES_NOT_UNIQUE,
                error_file, error_line, error_rank,
                "Delivery",
                ent_target_delivery->identity,
                NULL,
                NULL);
        }

        ent_target_delivery = ent_target_delivery->next;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_IDENTIFIER, "adm_check_identifiers_unique_delivery");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */