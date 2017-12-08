
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Tank Dispatcher */

/* Dispatcher */

void adm_dispatcher_tank(
    void)
{
    adm_pool_target_tank_typ * pool_target_tank;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_tank");
    #endif

    pool_target_tank = adm_find_away_target_event_tank();

    adm_dispatch_state_action_tank(pool_target_tank);

    adm_dispatch_home_pool_tank();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_tank");
    #endif
}


/* Dispatch Home Pool */

void adm_dispatch_home_pool_tank(
    void)
{
    adm_pool_target_tank_typ * pool_target_tank;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_tank");
    #endif

    while (adm_entity_system.ent_tank.home_pool_head != NULL) {

        pool_target_tank = adm_find_home_target_event_tank();

        adm_dispatch_state_action_tank(pool_target_tank);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_tank");
    #endif
}


/* Find Home Target Event */

adm_pool_target_tank_typ * adm_find_home_target_event_tank(
    void)
{
    adm_pool_target_tank_typ * pool_target_tank;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_tank");
    #endif

    pool_target_tank = adm_entity_system.ent_tank.home_pool_head;

    adm_entity_system.ent_tank.home_pool_head = pool_target_tank->next;

    if (adm_entity_system.ent_tank.home_pool_head == NULL) {

        adm_entity_system.ent_tank.home_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_tank");
    #endif

    return (pool_target_tank);
}


/* Find Away Target Event */

adm_pool_target_tank_typ * adm_find_away_target_event_tank(
    void)
{
    adm_pool_target_tank_typ * pool_target_tank;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_tank");
    #endif

    pool_target_tank = adm_entity_system.ent_tank.away_pool_head;

    adm_entity_system.ent_tank.away_pool_head = pool_target_tank->next;

    if (adm_entity_system.ent_tank.away_pool_head == NULL) {

        adm_entity_system.ent_tank.away_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_tank");
    #endif

    return (pool_target_tank);
}


/* Dispatch State Action */

void adm_dispatch_state_action_tank(
    adm_pool_target_tank_typ * pool_target)
{
    adm_dst_tank_added_volume_typ * dst_added_volume;
    adm_dst_tank_delivered_volume_typ * dst_delivered_volume;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_tank");
    #endif

    if (pool_target->ent_tank != NULL) {

        adm_object_existent_tank(
            pool_target->ent_tank,
            pool_target->error_location.file,
            pool_target->error_location.line,
            pool_target->error_location.rank);
    }

    switch (pool_target->evente) {

        /* Dynamic Events */

        case ADM_EVENT_TANK_LEVEL_BELOW_THRESHOLD :

            switch ((pool_target->ent_tank)->status) {

                case ADM_STATUS_TANK_CHECKING_LEVELS_AFTER_TANKER_DELIVERY :

                    adm_sim_display_state_tank_waiting_for_tanker_delivery(pool_target);

                    (pool_target->ent_tank)->status = ADM_STATUS_TANK_WAITING_FOR_TANKER_DELIVERY;

                break;

                case ADM_STATUS_TANK_WAITING_FOR_TANKER_DELIVERY :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Tank",
                        (pool_target->ent_tank)->identity,
                        "Event:Level_below_threshold",
                        "State:Waiting_For_Tanker_Delivery");

                break;

                case ADM_STATUS_TANK_RESET_WAITING_PUMPS :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Tank",
                        (pool_target->ent_tank)->identity,
                        "Event:Level_below_threshold",
                        "State:Reset_Waiting_Pumps");

                break;

                case ADM_STATUS_TANK_CHECKING_LEVELS_AFTER_PUMP_USAGE :

                    adm_sim_display_state_tank_waiting_for_tanker_delivery(pool_target);

                    (pool_target->ent_tank)->status = ADM_STATUS_TANK_WAITING_FOR_TANKER_DELIVERY;

                break;

                case ADM_STATUS_TANK_UPDATING_FUEL_LEVELS :

                    adm_sim_display_state_tank_waiting_for_tanker_delivery(pool_target);

                    (pool_target->ent_tank)->status = ADM_STATUS_TANK_WAITING_FOR_TANKER_DELIVERY;

                break;
            }

        break;

        case ADM_EVENT_TANK_LEVEL_ABOVE_THRESHOLD :

            switch ((pool_target->ent_tank)->status) {

                case ADM_STATUS_TANK_CHECKING_LEVELS_AFTER_TANKER_DELIVERY :

                    adm_sim_display_state_tank_reset_waiting_pumps(pool_target);

                    (pool_target->ent_tank)->status = ADM_STATUS_TANK_RESET_WAITING_PUMPS;

                break;

                case ADM_STATUS_TANK_WAITING_FOR_TANKER_DELIVERY :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Tank",
                        (pool_target->ent_tank)->identity,
                        "Event:Level_above_threshold",
                        "State:Waiting_For_Tanker_Delivery");

                break;

                case ADM_STATUS_TANK_RESET_WAITING_PUMPS :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Tank",
                        (pool_target->ent_tank)->identity,
                        "Event:Level_above_threshold",
                        "State:Reset_Waiting_Pumps");

                break;

                case ADM_STATUS_TANK_CHECKING_LEVELS_AFTER_PUMP_USAGE :

                    adm_sim_display_state_tank_reset_waiting_pumps(pool_target);

                    (pool_target->ent_tank)->status = ADM_STATUS_TANK_RESET_WAITING_PUMPS;

                break;

                case ADM_STATUS_TANK_UPDATING_FUEL_LEVELS :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Tank",
                        (pool_target->ent_tank)->identity,
                        "Event:Level_above_threshold",
                        "State:Updating_Fuel_Levels");

                break;
            }

        break;

        case ADM_EVENT_TANK_TANKER_DELIVERY :

            switch ((pool_target->ent_tank)->status) {

                case ADM_STATUS_TANK_CHECKING_LEVELS_AFTER_TANKER_DELIVERY :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Tank",
                        (pool_target->ent_tank)->identity,
                        "Event:Tanker_delivery",
                        "State:Checking_Levels_After_Tanker_Delivery");

                break;

                case ADM_STATUS_TANK_WAITING_FOR_TANKER_DELIVERY :

                    dst_added_volume = (adm_dst_tank_added_volume_typ*)pool_target->dataset.added_volume;

                    adm_sim_display_state_tank_checking_levels_after_tanker_delivery(pool_target);

                    (pool_target->ent_tank)->status = ADM_STATUS_TANK_CHECKING_LEVELS_AFTER_TANKER_DELIVERY;

                    adm_state_action_tank_checking_levels_after_tanker_delivery(
                        pool_target->ent_tank,
                        dst_added_volume);

                    adm_deallocate_memory(pool_target->dataset.added_volume);

                break;

                case ADM_STATUS_TANK_RESET_WAITING_PUMPS :

                    dst_added_volume = (adm_dst_tank_added_volume_typ*)pool_target->dataset.added_volume;

                    adm_sim_display_state_tank_checking_levels_after_tanker_delivery(pool_target);

                    (pool_target->ent_tank)->status = ADM_STATUS_TANK_CHECKING_LEVELS_AFTER_TANKER_DELIVERY;

                    adm_state_action_tank_checking_levels_after_tanker_delivery(
                        pool_target->ent_tank,
                        dst_added_volume);

                    adm_deallocate_memory(pool_target->dataset.added_volume);

                break;

                case ADM_STATUS_TANK_CHECKING_LEVELS_AFTER_PUMP_USAGE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Tank",
                        (pool_target->ent_tank)->identity,
                        "Event:Tanker_delivery",
                        "State:Checking_Levels_After_Pump_Usage");

                break;

                case ADM_STATUS_TANK_UPDATING_FUEL_LEVELS :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Tank",
                        (pool_target->ent_tank)->identity,
                        "Event:Tanker_delivery",
                        "State:Updating_Fuel_Levels");

                break;
            }

        break;

        case ADM_EVENT_TANK_FUEL_USED :

            switch ((pool_target->ent_tank)->status) {

                case ADM_STATUS_TANK_CHECKING_LEVELS_AFTER_TANKER_DELIVERY :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Tank",
                        (pool_target->ent_tank)->identity,
                        "Event:Fuel_used",
                        "State:Checking_Levels_After_Tanker_Delivery");

                break;

                case ADM_STATUS_TANK_WAITING_FOR_TANKER_DELIVERY :

                    dst_delivered_volume = (adm_dst_tank_delivered_volume_typ*)pool_target->dataset.delivered_volume;

                    adm_sim_display_state_tank_updating_fuel_levels(pool_target);

                    (pool_target->ent_tank)->status = ADM_STATUS_TANK_UPDATING_FUEL_LEVELS;

                    adm_state_action_tank_updating_fuel_levels(
                        pool_target->ent_tank,
                        dst_delivered_volume);

                    adm_deallocate_memory(pool_target->dataset.delivered_volume);

                break;

                case ADM_STATUS_TANK_RESET_WAITING_PUMPS :

                    dst_delivered_volume = (adm_dst_tank_delivered_volume_typ*)pool_target->dataset.delivered_volume;

                    adm_sim_display_state_tank_checking_levels_after_pump_usage(pool_target);

                    (pool_target->ent_tank)->status = ADM_STATUS_TANK_CHECKING_LEVELS_AFTER_PUMP_USAGE;

                    adm_state_action_tank_checking_levels_after_pump_usage(
                        pool_target->ent_tank,
                        dst_delivered_volume);

                    adm_deallocate_memory(pool_target->dataset.delivered_volume);

                break;

                case ADM_STATUS_TANK_CHECKING_LEVELS_AFTER_PUMP_USAGE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Tank",
                        (pool_target->ent_tank)->identity,
                        "Event:Fuel_used",
                        "State:Checking_Levels_After_Pump_Usage");

                break;

                case ADM_STATUS_TANK_UPDATING_FUEL_LEVELS :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Tank",
                        (pool_target->ent_tank)->identity,
                        "Event:Fuel_used",
                        "State:Updating_Fuel_Levels");

                break;
            }

        break;
    }

    adm_deallocate_memory(pool_target);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_tank");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */