
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Delivery Event Senders */

void adm_send_event_delivery_fuel_unit_delivered(
    const void * const source_object,
    const adm_ent_delivery_typ * const ent_delivery,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_delivery_typ * pool_target;
    adm_pool_target_delivery_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_delivery_fuel_unit_delivered");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_delivery_fuel_unit_delivered(
            ent_delivery,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_delivery(
            ent_delivery,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_delivery_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_delivery_typ));

        pool_target->evente = ADM_EVENT_DELIVERY_FUEL_UNIT_DELIVERED;
        pool_target->ent_delivery = (adm_ent_delivery_typ*)ent_delivery;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_delivery) {

            if (adm_entity_system.ent_delivery.home_pool_head == NULL) {

                adm_entity_system.ent_delivery.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_delivery.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_delivery == ent_delivery) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Delivery",
                            ent_delivery->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_delivery.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_delivery.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_delivery.away_pool_head == NULL) {

                adm_entity_system.ent_delivery.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_delivery.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_delivery.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_delivery_fuel_unit_delivered");
    #endif
}

void adm_send_event_delivery_delivery_complete(
    const void * const source_object,
    const adm_ent_delivery_typ * const ent_delivery,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_delivery_typ * pool_target;
    adm_pool_target_delivery_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_delivery_delivery_complete");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_delivery_delivery_complete(
            ent_delivery,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_delivery(
            ent_delivery,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_delivery_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_delivery_typ));

        pool_target->evente = ADM_EVENT_DELIVERY_DELIVERY_COMPLETE;
        pool_target->ent_delivery = (adm_ent_delivery_typ*)ent_delivery;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_delivery) {

            if (adm_entity_system.ent_delivery.home_pool_head == NULL) {

                adm_entity_system.ent_delivery.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_delivery.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_delivery == ent_delivery) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Delivery",
                            ent_delivery->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_delivery.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_delivery.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_delivery.away_pool_head == NULL) {

                adm_entity_system.ent_delivery.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_delivery.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_delivery.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_delivery_delivery_complete");
    #endif
}

void adm_send_event_delivery_delete_delivery(
    const void * const source_object,
    const adm_ent_delivery_typ * const ent_delivery,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_delivery_typ * pool_target;
    adm_pool_target_delivery_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_delivery_delete_delivery");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_delivery_delete_delivery(
            ent_delivery,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_delivery(
            ent_delivery,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_delivery_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_delivery_typ));

        pool_target->evente = ADM_EVENT_DELIVERY_DELETE_DELIVERY;
        pool_target->ent_delivery = (adm_ent_delivery_typ*)ent_delivery;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_delivery) {

            if (adm_entity_system.ent_delivery.home_pool_head == NULL) {

                adm_entity_system.ent_delivery.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_delivery.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_delivery == ent_delivery) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Delivery",
                            ent_delivery->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_delivery.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_delivery.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_delivery.away_pool_head == NULL) {

                adm_entity_system.ent_delivery.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_delivery.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_delivery.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_delivery_delete_delivery");
    #endif
}

void adm_send_event_delivery_create_delivery(
    const adm_int_equipment_number_typ evd_pump_number,
    const adm_int_time_hour_typ evd_timestamp_hours,
    const adm_int_time_minute_typ evd_timestamp_minutes,
    const adm_int_time_second_typ evd_timestamp_seconds,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_delivery_typ * pool_target;

    adm_dst_delivery_pump_number_typ * dst_pump_number;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_delivery_create_delivery");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_delivery_create_delivery(
            evd_pump_number,
            evd_timestamp_hours,
            evd_timestamp_minutes,
            evd_timestamp_seconds,
            error_file,
            error_line,
            error_rank);

        if (
            evd_pump_number < ADM_TYPE_MINIMUM_EQUIPMENT_NUMBER ||
            evd_pump_number > ADM_TYPE_MAXIMUM_EQUIPMENT_NUMBER) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                error_file, error_line, error_rank,
                "Delivery",
                null,
                "pump_number",
                adm_sim_lib_itoa(evd_pump_number));
        }

        if (
            evd_timestamp_hours < ADM_TYPE_MINIMUM_TIME_HOUR ||
            evd_timestamp_hours > ADM_TYPE_MAXIMUM_TIME_HOUR) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                error_file, error_line, error_rank,
                "Delivery",
                null,
                "timestamp_hours",
                adm_sim_lib_itoa(evd_timestamp_hours));
        }

        if (
            evd_timestamp_minutes < ADM_TYPE_MINIMUM_TIME_MINUTE ||
            evd_timestamp_minutes > ADM_TYPE_MAXIMUM_TIME_MINUTE) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                error_file, error_line, error_rank,
                "Delivery",
                null,
                "timestamp_minutes",
                adm_sim_lib_itoa(evd_timestamp_minutes));
        }

        if (
            evd_timestamp_seconds < ADM_TYPE_MINIMUM_TIME_SECOND ||
            evd_timestamp_seconds > ADM_TYPE_MAXIMUM_TIME_SECOND) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                error_file, error_line, error_rank,
                "Delivery",
                null,
                "timestamp_seconds",
                adm_sim_lib_itoa(evd_timestamp_seconds));
        }

        {
            typedef struct {
                adm_int_equipment_number_typ pump_number;
                adm_int_time_hour_typ timestamp_hours;
                adm_int_time_minute_typ timestamp_minutes;
                adm_int_time_second_typ timestamp_seconds;
            } mem_dst_delivery_pump_number_typ;

            mem_dst_delivery_pump_number_typ * mem_dst_pump_number;

            dst_pump_number = (adm_dst_delivery_pump_number_typ*)
                adm_allocate_memory(sizeof(adm_dst_delivery_pump_number_typ));

            mem_dst_pump_number = (mem_dst_delivery_pump_number_typ*)dst_pump_number;

            mem_dst_pump_number->pump_number = evd_pump_number;
            mem_dst_pump_number->timestamp_hours = evd_timestamp_hours;
            mem_dst_pump_number->timestamp_minutes = evd_timestamp_minutes;
            mem_dst_pump_number->timestamp_seconds = evd_timestamp_seconds;
        }

        pool_target = (adm_pool_target_delivery_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_delivery_typ));

        pool_target->evente = ADM_EVENT_DELIVERY_CREATE_DELIVERY;
        pool_target->ent_delivery = NULL;
        pool_target->next = NULL;
        pool_target->dataset.pump_number = dst_pump_number;

        if (adm_entity_system.ent_delivery.away_pool_head == NULL) {

            adm_entity_system.ent_delivery.away_pool_head = pool_target;

        } else {

            (adm_entity_system.ent_delivery.away_pool_tail)->next = pool_target;
        }

        adm_entity_system.ent_delivery.away_pool_tail = pool_target;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_delivery_create_delivery");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */