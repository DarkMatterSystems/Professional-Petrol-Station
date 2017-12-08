
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Pump Dispatcher */

/* Dispatcher */

void adm_dispatcher_pump(
    void)
{
    adm_pool_target_pump_typ * pool_target_pump;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_pump");
    #endif

    pool_target_pump = adm_find_away_target_event_pump();

    adm_dispatch_state_action_pump(pool_target_pump);

    adm_dispatch_home_pool_pump();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_pump");
    #endif
}


/* Dispatch Home Pool */

void adm_dispatch_home_pool_pump(
    void)
{
    adm_pool_target_pump_typ * pool_target_pump;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_pump");
    #endif

    while (adm_entity_system.ent_pump.home_pool_head != NULL) {

        pool_target_pump = adm_find_home_target_event_pump();

        adm_dispatch_state_action_pump(pool_target_pump);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_pump");
    #endif
}


/* Find Home Target Event */

adm_pool_target_pump_typ * adm_find_home_target_event_pump(
    void)
{
    adm_pool_target_pump_typ * pool_target_pump;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_pump");
    #endif

    pool_target_pump = adm_entity_system.ent_pump.home_pool_head;

    adm_entity_system.ent_pump.home_pool_head = pool_target_pump->next;

    if (adm_entity_system.ent_pump.home_pool_head == NULL) {

        adm_entity_system.ent_pump.home_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_pump");
    #endif

    return (pool_target_pump);
}


/* Find Away Target Event */

adm_pool_target_pump_typ * adm_find_away_target_event_pump(
    void)
{
    adm_pool_target_pump_typ * pool_target_pump;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_pump");
    #endif

    pool_target_pump = adm_entity_system.ent_pump.away_pool_head;

    adm_entity_system.ent_pump.away_pool_head = pool_target_pump->next;

    if (adm_entity_system.ent_pump.away_pool_head == NULL) {

        adm_entity_system.ent_pump.away_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_pump");
    #endif

    return (pool_target_pump);
}


/* Dispatch State Action */

void adm_dispatch_state_action_pump(
    adm_pool_target_pump_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_pump");
    #endif

    if (pool_target->ent_pump != NULL) {

        adm_object_existent_pump(
            pool_target->ent_pump,
            pool_target->error_location.file,
            pool_target->error_location.line,
            pool_target->error_location.rank);
    }

    switch (pool_target->evente) {

        /* Dynamic Events */

        case ADM_EVENT_PUMP_GUN_REMOVED :

            switch ((pool_target->ent_pump)->status) {

                case ADM_STATUS_PUMP_WAITING_FOR_CUSTOMER :

                    adm_sim_display_state_pump_waiting_pump_enable(pool_target);

                    (pool_target->ent_pump)->status = ADM_STATUS_PUMP_WAITING_PUMP_ENABLE;

                    adm_state_action_pump_waiting_pump_enable(
                        pool_target->ent_pump);

                break;
            }

        break;

        case ADM_EVENT_PUMP_GUN_REPLACED :

            switch ((pool_target->ent_pump)->status) {

                case ADM_STATUS_PUMP_WAITING_PUMP_ENABLE :

                    adm_sim_display_state_pump_waiting_for_customer(pool_target);

                    (pool_target->ent_pump)->status = ADM_STATUS_PUMP_WAITING_FOR_CUSTOMER;

                break;

                case ADM_STATUS_PUMP_READY_TO_PUMP :

                    adm_sim_display_state_pump_fuel_delivery_complete(pool_target);

                    (pool_target->ent_pump)->status = ADM_STATUS_PUMP_FUEL_DELIVERY_COMPLETE;

                    adm_state_action_pump_fuel_delivery_complete(
                        pool_target->ent_pump);

                break;

                case ADM_STATUS_PUMP_PUMPING_PAUSED :

                    adm_sim_display_state_pump_fuel_delivery_complete(pool_target);

                    (pool_target->ent_pump)->status = ADM_STATUS_PUMP_FUEL_DELIVERY_COMPLETE;

                    adm_state_action_pump_fuel_delivery_complete(
                        pool_target->ent_pump);

                break;
            }

        break;

        case ADM_EVENT_PUMP_FUEL_LEVEL_LOW :

            switch ((pool_target->ent_pump)->status) {

                case ADM_STATUS_PUMP_WAITING_PUMP_ENABLE :

                    adm_sim_display_state_pump_fuel_unavailable(pool_target);

                    (pool_target->ent_pump)->status = ADM_STATUS_PUMP_FUEL_UNAVAILABLE;

                    adm_state_action_pump_fuel_unavailable(
                        pool_target->ent_pump);

                break;
            }

        break;

        case ADM_EVENT_PUMP_FUEL_AVAILABLE :

            switch ((pool_target->ent_pump)->status) {

                case ADM_STATUS_PUMP_FUEL_UNAVAILABLE :

                    adm_sim_display_state_pump_waiting_for_customer(pool_target);

                    (pool_target->ent_pump)->status = ADM_STATUS_PUMP_WAITING_FOR_CUSTOMER;

                break;
            }

        break;

        case ADM_EVENT_PUMP_PUMP_ENABLED :

            switch ((pool_target->ent_pump)->status) {

                case ADM_STATUS_PUMP_WAITING_PUMP_ENABLE :

                    adm_sim_display_state_pump_ready_to_pump(pool_target);

                    (pool_target->ent_pump)->status = ADM_STATUS_PUMP_READY_TO_PUMP;

                    adm_state_action_pump_ready_to_pump(
                        pool_target->ent_pump);

                break;
            }

        break;

        case ADM_EVENT_PUMP_TRIGGER_DEPRESSED :

            switch ((pool_target->ent_pump)->status) {

                case ADM_STATUS_PUMP_READY_TO_PUMP :

                    adm_sim_display_state_pump_pumping(pool_target);

                    (pool_target->ent_pump)->status = ADM_STATUS_PUMP_PUMPING;

                    adm_state_action_pump_pumping(
                        pool_target->ent_pump);

                break;

                case ADM_STATUS_PUMP_PUMPING_PAUSED :

                    adm_sim_display_state_pump_pumping(pool_target);

                    (pool_target->ent_pump)->status = ADM_STATUS_PUMP_PUMPING;

                    adm_state_action_pump_pumping(
                        pool_target->ent_pump);

                break;
            }

        break;

        case ADM_EVENT_PUMP_TRIGGER_RELEASED :

            switch ((pool_target->ent_pump)->status) {

                case ADM_STATUS_PUMP_PUMPING :

                    adm_sim_display_state_pump_pumping_paused(pool_target);

                    (pool_target->ent_pump)->status = ADM_STATUS_PUMP_PUMPING_PAUSED;

                    adm_state_action_pump_pumping_paused(
                        pool_target->ent_pump);

                break;
            }

        break;

        case ADM_EVENT_PUMP_CUSTOMER_FINISHED :

            switch ((pool_target->ent_pump)->status) {

                case ADM_STATUS_PUMP_FUEL_DELIVERY_COMPLETE :

                    adm_sim_display_state_pump_waiting_for_customer(pool_target);

                    (pool_target->ent_pump)->status = ADM_STATUS_PUMP_WAITING_FOR_CUSTOMER;

                break;
            }

        break;
    }

    adm_deallocate_memory(pool_target);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_pump");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */