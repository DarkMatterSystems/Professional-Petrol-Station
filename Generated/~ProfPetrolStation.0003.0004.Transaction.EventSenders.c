
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Transaction Event Senders */

void adm_send_event_transaction_payment_received(
    const void * const source_object,
    const adm_ent_transaction_typ * const ent_transaction,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_transaction_typ * pool_target;
    adm_pool_target_transaction_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_transaction_payment_received");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_transaction_payment_received(
            ent_transaction,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_transaction(
            ent_transaction,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_transaction_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_transaction_typ));

        pool_target->evente = ADM_EVENT_TRANSACTION_PAYMENT_RECEIVED;
        pool_target->ent_transaction = (adm_ent_transaction_typ*)ent_transaction;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_transaction) {

            if (adm_entity_system.ent_transaction.home_pool_head == NULL) {

                adm_entity_system.ent_transaction.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_transaction.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_transaction == ent_transaction) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Transaction",
                            ent_transaction->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_transaction.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_transaction.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_transaction.away_pool_head == NULL) {

                adm_entity_system.ent_transaction.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_transaction.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_transaction.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_transaction_payment_received");
    #endif
}

void adm_send_event_transaction_customer_absconds(
    const void * const source_object,
    const adm_ent_transaction_typ * const ent_transaction,
    const adm_str_text_typ * const evd_customer_details,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_transaction_typ * pool_target;
    adm_pool_target_transaction_typ * home_pool_target;

    adm_dst_transaction_customer_details_typ * dst_customer_details;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_transaction_customer_absconds");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_transaction_customer_absconds(
            ent_transaction,
            evd_customer_details,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_transaction(
            ent_transaction,
            error_file,
            error_line,
            error_rank);

        if (strlen(evd_customer_details) > ADM_TYPE_SIZE_TEXT) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                error_file, error_line, error_rank,
                "Transaction",
                ent_transaction->identity,
                "customer_details",
                evd_customer_details);
        }

        {
            typedef struct {
                adm_str_text_typ * customer_details;
            } mem_dst_transaction_customer_details_typ;

            mem_dst_transaction_customer_details_typ * mem_dst_customer_details;

            dst_customer_details = (adm_dst_transaction_customer_details_typ*)
                adm_allocate_memory(sizeof(adm_dst_transaction_customer_details_typ));

            mem_dst_customer_details = (mem_dst_transaction_customer_details_typ*)dst_customer_details;

            mem_dst_customer_details->customer_details = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);

            strcpy_s(mem_dst_customer_details->customer_details, ADM_TYPE_SIZE_TEXT+1, evd_customer_details);
        }

        pool_target = (adm_pool_target_transaction_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_transaction_typ));

        pool_target->evente = ADM_EVENT_TRANSACTION_CUSTOMER_ABSCONDS;
        pool_target->ent_transaction = (adm_ent_transaction_typ*)ent_transaction;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;
        pool_target->dataset.customer_details = dst_customer_details;

        if (source_object == ent_transaction) {

            if (adm_entity_system.ent_transaction.home_pool_head == NULL) {

                adm_entity_system.ent_transaction.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_transaction.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_transaction == ent_transaction) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Transaction",
                            ent_transaction->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_transaction.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_transaction.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_transaction.away_pool_head == NULL) {

                adm_entity_system.ent_transaction.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_transaction.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_transaction.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_transaction_customer_absconds");
    #endif
}

void adm_send_event_transaction_create_transaction(
    const adm_int_equipment_number_typ evd_delivery_pump,
    const adm_fxd_money_typ evd_delivery_cost,
    const adm_int_time_hour_typ evd_delivery_time_hours,
    const adm_int_time_minute_typ evd_delivery_time_minutes,
    const adm_int_time_second_typ evd_delivery_time_seconds,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_transaction_typ * pool_target;

    adm_dst_transaction_creation_data_typ * dst_creation_data;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_transaction_create_transaction");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_transaction_create_transaction(
            evd_delivery_pump,
            evd_delivery_cost,
            evd_delivery_time_hours,
            evd_delivery_time_minutes,
            evd_delivery_time_seconds,
            error_file,
            error_line,
            error_rank);

        if (
            evd_delivery_pump < ADM_TYPE_MINIMUM_EQUIPMENT_NUMBER ||
            evd_delivery_pump > ADM_TYPE_MAXIMUM_EQUIPMENT_NUMBER) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                error_file, error_line, error_rank,
                "Transaction",
                null,
                "delivery_pump",
                adm_sim_lib_itoa(evd_delivery_pump));
        }

        if (
            evd_delivery_cost < ADM_TYPE_MINIMUM_MONEY ||
            evd_delivery_cost > ADM_TYPE_MAXIMUM_MONEY) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                error_file, error_line, error_rank,
                "Transaction",
                null,
                "delivery_cost",
                adm_sim_lib_fxtoa(evd_delivery_cost));
        }

        if (
            evd_delivery_time_hours < ADM_TYPE_MINIMUM_TIME_HOUR ||
            evd_delivery_time_hours > ADM_TYPE_MAXIMUM_TIME_HOUR) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                error_file, error_line, error_rank,
                "Transaction",
                null,
                "delivery_time_hours",
                adm_sim_lib_itoa(evd_delivery_time_hours));
        }

        if (
            evd_delivery_time_minutes < ADM_TYPE_MINIMUM_TIME_MINUTE ||
            evd_delivery_time_minutes > ADM_TYPE_MAXIMUM_TIME_MINUTE) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                error_file, error_line, error_rank,
                "Transaction",
                null,
                "delivery_time_minutes",
                adm_sim_lib_itoa(evd_delivery_time_minutes));
        }

        if (
            evd_delivery_time_seconds < ADM_TYPE_MINIMUM_TIME_SECOND ||
            evd_delivery_time_seconds > ADM_TYPE_MAXIMUM_TIME_SECOND) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                error_file, error_line, error_rank,
                "Transaction",
                null,
                "delivery_time_seconds",
                adm_sim_lib_itoa(evd_delivery_time_seconds));
        }

        {
            typedef struct {
                adm_int_equipment_number_typ delivery_pump;
                adm_fxd_money_typ delivery_cost;
                adm_int_time_hour_typ delivery_time_hours;
                adm_int_time_minute_typ delivery_time_minutes;
                adm_int_time_second_typ delivery_time_seconds;
            } mem_dst_transaction_creation_data_typ;

            mem_dst_transaction_creation_data_typ * mem_dst_creation_data;

            dst_creation_data = (adm_dst_transaction_creation_data_typ*)
                adm_allocate_memory(sizeof(adm_dst_transaction_creation_data_typ));

            mem_dst_creation_data = (mem_dst_transaction_creation_data_typ*)dst_creation_data;

            mem_dst_creation_data->delivery_pump = evd_delivery_pump;
            mem_dst_creation_data->delivery_cost = evd_delivery_cost;
            mem_dst_creation_data->delivery_time_hours = evd_delivery_time_hours;
            mem_dst_creation_data->delivery_time_minutes = evd_delivery_time_minutes;
            mem_dst_creation_data->delivery_time_seconds = evd_delivery_time_seconds;
        }

        pool_target = (adm_pool_target_transaction_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_transaction_typ));

        pool_target->evente = ADM_EVENT_TRANSACTION_CREATE_TRANSACTION;
        pool_target->ent_transaction = NULL;
        pool_target->next = NULL;
        pool_target->dataset.creation_data = dst_creation_data;

        if (adm_entity_system.ent_transaction.away_pool_head == NULL) {

            adm_entity_system.ent_transaction.away_pool_head = pool_target;

        } else {

            (adm_entity_system.ent_transaction.away_pool_tail)->next = pool_target;
        }

        adm_entity_system.ent_transaction.away_pool_tail = pool_target;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_transaction_create_transaction");
    #endif
}

void adm_send_event_transaction_close_transaction(
    const void * const source_object,
    const adm_ent_transaction_typ * const ent_transaction,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_transaction_typ * pool_target;
    adm_pool_target_transaction_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_transaction_close_transaction");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_transaction_close_transaction(
            ent_transaction,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_transaction(
            ent_transaction,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_transaction_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_transaction_typ));

        pool_target->evente = ADM_EVENT_TRANSACTION_CLOSE_TRANSACTION;
        pool_target->ent_transaction = (adm_ent_transaction_typ*)ent_transaction;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_transaction) {

            if (adm_entity_system.ent_transaction.home_pool_head == NULL) {

                adm_entity_system.ent_transaction.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_transaction.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_transaction == ent_transaction) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Transaction",
                            ent_transaction->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_transaction.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_transaction.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_transaction.away_pool_head == NULL) {

                adm_entity_system.ent_transaction.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_transaction.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_transaction.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_transaction_close_transaction");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */