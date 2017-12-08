
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Tank Event Senders */

void adm_send_event_tank_level_below_threshold(
    const void * const source_object,
    const adm_ent_tank_typ * const ent_tank,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_tank_typ * pool_target;
    adm_pool_target_tank_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_tank_level_below_threshold");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_tank_level_below_threshold(
            ent_tank,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_tank(
            ent_tank,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_tank_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_tank_typ));

        pool_target->evente = ADM_EVENT_TANK_LEVEL_BELOW_THRESHOLD;
        pool_target->ent_tank = (adm_ent_tank_typ*)ent_tank;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_tank) {

            if (adm_entity_system.ent_tank.home_pool_head == NULL) {

                adm_entity_system.ent_tank.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_tank.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_tank == ent_tank) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Tank",
                            ent_tank->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_tank.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_tank.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_tank.away_pool_head == NULL) {

                adm_entity_system.ent_tank.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_tank.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_tank.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_tank_level_below_threshold");
    #endif
}

void adm_send_event_tank_level_above_threshold(
    const void * const source_object,
    const adm_ent_tank_typ * const ent_tank,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_tank_typ * pool_target;
    adm_pool_target_tank_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_tank_level_above_threshold");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_tank_level_above_threshold(
            ent_tank,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_tank(
            ent_tank,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_tank_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_tank_typ));

        pool_target->evente = ADM_EVENT_TANK_LEVEL_ABOVE_THRESHOLD;
        pool_target->ent_tank = (adm_ent_tank_typ*)ent_tank;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_tank) {

            if (adm_entity_system.ent_tank.home_pool_head == NULL) {

                adm_entity_system.ent_tank.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_tank.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_tank == ent_tank) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Tank",
                            ent_tank->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_tank.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_tank.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_tank.away_pool_head == NULL) {

                adm_entity_system.ent_tank.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_tank.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_tank.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_tank_level_above_threshold");
    #endif
}

void adm_send_event_tank_tanker_delivery(
    const void * const source_object,
    const adm_ent_tank_typ * const ent_tank,
    const adm_fxd_volume_typ evd_added_volume,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_tank_typ * pool_target;
    adm_pool_target_tank_typ * home_pool_target;

    adm_dst_tank_added_volume_typ * dst_added_volume;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_tank_tanker_delivery");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_tank_tanker_delivery(
            ent_tank,
            evd_added_volume,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_tank(
            ent_tank,
            error_file,
            error_line,
            error_rank);

        if (
            evd_added_volume < ADM_TYPE_MINIMUM_VOLUME ||
            evd_added_volume > ADM_TYPE_MAXIMUM_VOLUME) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                error_file, error_line, error_rank,
                "Tank",
                ent_tank->identity,
                "added_volume",
                adm_sim_lib_fxtoa(evd_added_volume));
        }

        {
            typedef struct {
                adm_fxd_volume_typ added_volume;
            } mem_dst_tank_added_volume_typ;

            mem_dst_tank_added_volume_typ * mem_dst_added_volume;

            dst_added_volume = (adm_dst_tank_added_volume_typ*)
                adm_allocate_memory(sizeof(adm_dst_tank_added_volume_typ));

            mem_dst_added_volume = (mem_dst_tank_added_volume_typ*)dst_added_volume;

            mem_dst_added_volume->added_volume = evd_added_volume;
        }

        pool_target = (adm_pool_target_tank_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_tank_typ));

        pool_target->evente = ADM_EVENT_TANK_TANKER_DELIVERY;
        pool_target->ent_tank = (adm_ent_tank_typ*)ent_tank;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;
        pool_target->dataset.added_volume = dst_added_volume;

        if (source_object == ent_tank) {

            if (adm_entity_system.ent_tank.home_pool_head == NULL) {

                adm_entity_system.ent_tank.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_tank.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_tank == ent_tank) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Tank",
                            ent_tank->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_tank.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_tank.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_tank.away_pool_head == NULL) {

                adm_entity_system.ent_tank.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_tank.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_tank.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_tank_tanker_delivery");
    #endif
}

void adm_send_event_tank_fuel_used(
    const void * const source_object,
    const adm_ent_tank_typ * const ent_tank,
    const adm_fxd_volume_typ evd_delivered_volume,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_tank_typ * pool_target;
    adm_pool_target_tank_typ * home_pool_target;

    adm_dst_tank_delivered_volume_typ * dst_delivered_volume;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_tank_fuel_used");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_tank_fuel_used(
            ent_tank,
            evd_delivered_volume,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_tank(
            ent_tank,
            error_file,
            error_line,
            error_rank);

        if (
            evd_delivered_volume < ADM_TYPE_MINIMUM_VOLUME ||
            evd_delivered_volume > ADM_TYPE_MAXIMUM_VOLUME) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                error_file, error_line, error_rank,
                "Tank",
                ent_tank->identity,
                "delivered_volume",
                adm_sim_lib_fxtoa(evd_delivered_volume));
        }

        {
            typedef struct {
                adm_fxd_volume_typ delivered_volume;
            } mem_dst_tank_delivered_volume_typ;

            mem_dst_tank_delivered_volume_typ * mem_dst_delivered_volume;

            dst_delivered_volume = (adm_dst_tank_delivered_volume_typ*)
                adm_allocate_memory(sizeof(adm_dst_tank_delivered_volume_typ));

            mem_dst_delivered_volume = (mem_dst_tank_delivered_volume_typ*)dst_delivered_volume;

            mem_dst_delivered_volume->delivered_volume = evd_delivered_volume;
        }

        pool_target = (adm_pool_target_tank_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_tank_typ));

        pool_target->evente = ADM_EVENT_TANK_FUEL_USED;
        pool_target->ent_tank = (adm_ent_tank_typ*)ent_tank;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;
        pool_target->dataset.delivered_volume = dst_delivered_volume;

        if (source_object == ent_tank) {

            if (adm_entity_system.ent_tank.home_pool_head == NULL) {

                adm_entity_system.ent_tank.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_tank.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_tank == ent_tank) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Tank",
                            ent_tank->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_tank.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_tank.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_tank.away_pool_head == NULL) {

                adm_entity_system.ent_tank.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_tank.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_tank.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_tank_fuel_used");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */