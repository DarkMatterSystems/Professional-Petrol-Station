
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Pump Event Senders */

void adm_send_event_pump_gun_removed(
    const void * const source_object,
    const adm_ent_pump_typ * const ent_pump,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_pump_typ * pool_target;
    adm_pool_target_pump_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_pump_gun_removed");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_pump_gun_removed(
            ent_pump,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_pump(
            ent_pump,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_pump_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_pump_typ));

        pool_target->evente = ADM_EVENT_PUMP_GUN_REMOVED;
        pool_target->ent_pump = (adm_ent_pump_typ*)ent_pump;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_pump) {

            if (adm_entity_system.ent_pump.home_pool_head == NULL) {

                adm_entity_system.ent_pump.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_pump.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_pump == ent_pump) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Pump",
                            ent_pump->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_pump.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_pump.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_pump.away_pool_head == NULL) {

                adm_entity_system.ent_pump.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_pump.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_pump.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_pump_gun_removed");
    #endif
}

void adm_send_event_pump_gun_replaced(
    const void * const source_object,
    const adm_ent_pump_typ * const ent_pump,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_pump_typ * pool_target;
    adm_pool_target_pump_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_pump_gun_replaced");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_pump_gun_replaced(
            ent_pump,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_pump(
            ent_pump,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_pump_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_pump_typ));

        pool_target->evente = ADM_EVENT_PUMP_GUN_REPLACED;
        pool_target->ent_pump = (adm_ent_pump_typ*)ent_pump;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_pump) {

            if (adm_entity_system.ent_pump.home_pool_head == NULL) {

                adm_entity_system.ent_pump.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_pump.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_pump == ent_pump) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Pump",
                            ent_pump->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_pump.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_pump.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_pump.away_pool_head == NULL) {

                adm_entity_system.ent_pump.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_pump.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_pump.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_pump_gun_replaced");
    #endif
}

void adm_send_event_pump_fuel_level_low(
    const void * const source_object,
    const adm_ent_pump_typ * const ent_pump,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_pump_typ * pool_target;
    adm_pool_target_pump_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_pump_fuel_level_low");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_pump_fuel_level_low(
            ent_pump,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_pump(
            ent_pump,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_pump_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_pump_typ));

        pool_target->evente = ADM_EVENT_PUMP_FUEL_LEVEL_LOW;
        pool_target->ent_pump = (adm_ent_pump_typ*)ent_pump;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_pump) {

            if (adm_entity_system.ent_pump.home_pool_head == NULL) {

                adm_entity_system.ent_pump.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_pump.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_pump == ent_pump) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Pump",
                            ent_pump->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_pump.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_pump.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_pump.away_pool_head == NULL) {

                adm_entity_system.ent_pump.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_pump.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_pump.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_pump_fuel_level_low");
    #endif
}

void adm_send_event_pump_fuel_available(
    const void * const source_object,
    const adm_ent_pump_typ * const ent_pump,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_pump_typ * pool_target;
    adm_pool_target_pump_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_pump_fuel_available");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_pump_fuel_available(
            ent_pump,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_pump(
            ent_pump,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_pump_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_pump_typ));

        pool_target->evente = ADM_EVENT_PUMP_FUEL_AVAILABLE;
        pool_target->ent_pump = (adm_ent_pump_typ*)ent_pump;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_pump) {

            if (adm_entity_system.ent_pump.home_pool_head == NULL) {

                adm_entity_system.ent_pump.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_pump.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_pump == ent_pump) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Pump",
                            ent_pump->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_pump.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_pump.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_pump.away_pool_head == NULL) {

                adm_entity_system.ent_pump.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_pump.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_pump.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_pump_fuel_available");
    #endif
}

void adm_send_event_pump_pump_enabled(
    const void * const source_object,
    const adm_ent_pump_typ * const ent_pump,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_pump_typ * pool_target;
    adm_pool_target_pump_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_pump_pump_enabled");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_pump_pump_enabled(
            ent_pump,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_pump(
            ent_pump,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_pump_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_pump_typ));

        pool_target->evente = ADM_EVENT_PUMP_PUMP_ENABLED;
        pool_target->ent_pump = (adm_ent_pump_typ*)ent_pump;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_pump) {

            if (adm_entity_system.ent_pump.home_pool_head == NULL) {

                adm_entity_system.ent_pump.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_pump.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_pump == ent_pump) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Pump",
                            ent_pump->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_pump.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_pump.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_pump.away_pool_head == NULL) {

                adm_entity_system.ent_pump.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_pump.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_pump.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_pump_pump_enabled");
    #endif
}

void adm_send_event_pump_trigger_depressed(
    const void * const source_object,
    const adm_ent_pump_typ * const ent_pump,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_pump_typ * pool_target;
    adm_pool_target_pump_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_pump_trigger_depressed");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_pump_trigger_depressed(
            ent_pump,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_pump(
            ent_pump,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_pump_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_pump_typ));

        pool_target->evente = ADM_EVENT_PUMP_TRIGGER_DEPRESSED;
        pool_target->ent_pump = (adm_ent_pump_typ*)ent_pump;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_pump) {

            if (adm_entity_system.ent_pump.home_pool_head == NULL) {

                adm_entity_system.ent_pump.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_pump.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_pump == ent_pump) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Pump",
                            ent_pump->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_pump.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_pump.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_pump.away_pool_head == NULL) {

                adm_entity_system.ent_pump.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_pump.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_pump.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_pump_trigger_depressed");
    #endif
}

void adm_send_event_pump_trigger_released(
    const void * const source_object,
    const adm_ent_pump_typ * const ent_pump,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_pump_typ * pool_target;
    adm_pool_target_pump_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_pump_trigger_released");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_pump_trigger_released(
            ent_pump,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_pump(
            ent_pump,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_pump_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_pump_typ));

        pool_target->evente = ADM_EVENT_PUMP_TRIGGER_RELEASED;
        pool_target->ent_pump = (adm_ent_pump_typ*)ent_pump;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_pump) {

            if (adm_entity_system.ent_pump.home_pool_head == NULL) {

                adm_entity_system.ent_pump.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_pump.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_pump == ent_pump) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Pump",
                            ent_pump->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_pump.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_pump.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_pump.away_pool_head == NULL) {

                adm_entity_system.ent_pump.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_pump.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_pump.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_pump_trigger_released");
    #endif
}

void adm_send_event_pump_customer_finished(
    const void * const source_object,
    const adm_ent_pump_typ * const ent_pump,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_pump_typ * pool_target;
    adm_pool_target_pump_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_pump_customer_finished");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_pump_customer_finished(
            ent_pump,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_pump(
            ent_pump,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_pump_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_pump_typ));

        pool_target->evente = ADM_EVENT_PUMP_CUSTOMER_FINISHED;
        pool_target->ent_pump = (adm_ent_pump_typ*)ent_pump;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_pump) {

            if (adm_entity_system.ent_pump.home_pool_head == NULL) {

                adm_entity_system.ent_pump.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_pump.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_pump == ent_pump) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Pump",
                            ent_pump->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_pump.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_pump.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_pump.away_pool_head == NULL) {

                adm_entity_system.ent_pump.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_pump.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_pump.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_pump_customer_finished");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */