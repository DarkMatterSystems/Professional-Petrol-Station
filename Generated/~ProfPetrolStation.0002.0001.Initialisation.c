
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Domain - Initialisation */

void adm_initialisation_petrol_station_control(
    void)
{
    /* Declare Objects */

    /* Pump */
    adm_ent_pump_typ * ent_pump_0000000001;
    adm_ent_pump_typ * ent_pump_0000000002;
    adm_ent_pump_typ * ent_pump_0000000003;
    adm_ent_pump_typ * ent_pump_0000000004;
    adm_ent_pump_typ * ent_pump_0000000005;
    adm_ent_pump_typ * ent_pump_0000000006;
    adm_ent_pump_typ * ent_pump_0000000007;
    adm_ent_pump_typ * ent_pump_0000000008;
    adm_ent_pump_typ * ent_pump_0000000009;
    adm_ent_pump_typ * ent_pump_0000000010;
    adm_ent_pump_typ * ent_pump_0000000011;
    adm_ent_pump_typ * ent_pump_0000000012;
    adm_ent_pump_typ * ent_pump_0000000013;

    /* Tank */
    adm_ent_tank_typ * ent_tank_0000000014;
    adm_ent_tank_typ * ent_tank_0000000015;
    adm_ent_tank_typ * ent_tank_0000000016;
    adm_ent_tank_typ * ent_tank_0000000017;
    adm_ent_tank_typ * ent_tank_0000000018;
    adm_ent_tank_typ * ent_tank_0000000019;
    adm_ent_tank_typ * ent_tank_0000000020;

    /* Fuel Grade */
    adm_ent_fuel_grade_typ * ent_fuel_grade_0000000021;
    adm_ent_fuel_grade_typ * ent_fuel_grade_0000000022;

    /* Transaction Policy */
    adm_ent_transaction_policy_typ * ent_transaction_policy_0000000023;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_INITIALISATION, "adm_initialisation_petrol_station_control");
    #endif

    /* Entity System */

    adm_entity_system.ent_delivery.tote = 0;
    adm_entity_system.ent_pump.tote = 0;
    adm_entity_system.ent_tank.tote = 0;
    adm_entity_system.ent_transaction.tote = 0;
    adm_entity_system.ent_fuel_grade.tote = 0;
    adm_entity_system.ent_pending_transaction.tote = 0;
    adm_entity_system.ent_evaded_transaction.tote = 0;
    adm_entity_system.ent_transaction_policy.tote = 0;
    adm_entity_system.ent_paid_transaction.tote = 0;

    adm_entity_system.ent_delivery.live_list_head = NULL;
    adm_entity_system.ent_pump.live_list_head = NULL;
    adm_entity_system.ent_tank.live_list_head = NULL;
    adm_entity_system.ent_transaction.live_list_head = NULL;
    adm_entity_system.ent_fuel_grade.live_list_head = NULL;
    adm_entity_system.ent_pending_transaction.live_list_head = NULL;
    adm_entity_system.ent_evaded_transaction.live_list_head = NULL;
    adm_entity_system.ent_transaction_policy.live_list_head = NULL;
    adm_entity_system.ent_paid_transaction.live_list_head = NULL;

    adm_entity_system.ent_delivery.live_list_tail = NULL;
    adm_entity_system.ent_pump.live_list_tail = NULL;
    adm_entity_system.ent_tank.live_list_tail = NULL;
    adm_entity_system.ent_transaction.live_list_tail = NULL;
    adm_entity_system.ent_fuel_grade.live_list_tail = NULL;
    adm_entity_system.ent_pending_transaction.live_list_tail = NULL;
    adm_entity_system.ent_evaded_transaction.live_list_tail = NULL;
    adm_entity_system.ent_transaction_policy.live_list_tail = NULL;
    adm_entity_system.ent_paid_transaction.live_list_tail = NULL;

    adm_entity_system.ent_delivery.dead_list_head = NULL;
    adm_entity_system.ent_pump.dead_list_head = NULL;
    adm_entity_system.ent_tank.dead_list_head = NULL;
    adm_entity_system.ent_transaction.dead_list_head = NULL;
    adm_entity_system.ent_fuel_grade.dead_list_head = NULL;
    adm_entity_system.ent_pending_transaction.dead_list_head = NULL;
    adm_entity_system.ent_evaded_transaction.dead_list_head = NULL;
    adm_entity_system.ent_transaction_policy.dead_list_head = NULL;
    adm_entity_system.ent_paid_transaction.dead_list_head = NULL;

    adm_entity_system.ent_delivery.dead_list_tail = NULL;
    adm_entity_system.ent_pump.dead_list_tail = NULL;
    adm_entity_system.ent_tank.dead_list_tail = NULL;
    adm_entity_system.ent_transaction.dead_list_tail = NULL;
    adm_entity_system.ent_fuel_grade.dead_list_tail = NULL;
    adm_entity_system.ent_pending_transaction.dead_list_tail = NULL;
    adm_entity_system.ent_evaded_transaction.dead_list_tail = NULL;
    adm_entity_system.ent_transaction_policy.dead_list_tail = NULL;
    adm_entity_system.ent_paid_transaction.dead_list_tail = NULL;

    adm_entity_system.ent_delivery.home_pool_head = NULL;
    adm_entity_system.ent_pump.home_pool_head = NULL;
    adm_entity_system.ent_tank.home_pool_head = NULL;
    adm_entity_system.ent_transaction.home_pool_head = NULL;

    adm_entity_system.ent_delivery.home_pool_tail = NULL;
    adm_entity_system.ent_pump.home_pool_tail = NULL;
    adm_entity_system.ent_tank.home_pool_tail = NULL;
    adm_entity_system.ent_transaction.home_pool_tail = NULL;

    adm_entity_system.ent_delivery.away_pool_head = NULL;
    adm_entity_system.ent_pump.away_pool_head = NULL;
    adm_entity_system.ent_tank.away_pool_head = NULL;
    adm_entity_system.ent_transaction.away_pool_head = NULL;

    adm_entity_system.ent_delivery.away_pool_tail = NULL;
    adm_entity_system.ent_pump.away_pool_tail = NULL;
    adm_entity_system.ent_tank.away_pool_tail = NULL;
    adm_entity_system.ent_transaction.away_pool_tail = NULL;


    /* Make Objects */

    /* Pump */
    ent_pump_0000000001 = adm_make_object_pump(ADM_STATUS_PUMP_WAITING_FOR_CUSTOMER);
    ent_pump_0000000002 = adm_make_object_pump(ADM_STATUS_PUMP_WAITING_FOR_CUSTOMER);
    ent_pump_0000000003 = adm_make_object_pump(ADM_STATUS_PUMP_WAITING_FOR_CUSTOMER);
    ent_pump_0000000004 = adm_make_object_pump(ADM_STATUS_PUMP_WAITING_FOR_CUSTOMER);
    ent_pump_0000000005 = adm_make_object_pump(ADM_STATUS_PUMP_WAITING_FOR_CUSTOMER);
    ent_pump_0000000006 = adm_make_object_pump(ADM_STATUS_PUMP_WAITING_FOR_CUSTOMER);
    ent_pump_0000000007 = adm_make_object_pump(ADM_STATUS_PUMP_WAITING_FOR_CUSTOMER);
    ent_pump_0000000008 = adm_make_object_pump(ADM_STATUS_PUMP_WAITING_FOR_CUSTOMER);
    ent_pump_0000000009 = adm_make_object_pump(ADM_STATUS_PUMP_WAITING_FOR_CUSTOMER);
    ent_pump_0000000010 = adm_make_object_pump(ADM_STATUS_PUMP_WAITING_FOR_CUSTOMER);
    ent_pump_0000000011 = adm_make_object_pump(ADM_STATUS_PUMP_WAITING_FOR_CUSTOMER);
    ent_pump_0000000012 = adm_make_object_pump(ADM_STATUS_PUMP_WAITING_FOR_CUSTOMER);
    ent_pump_0000000013 = adm_make_object_pump(ADM_STATUS_PUMP_WAITING_FOR_CUSTOMER);

    /* Tank */
    ent_tank_0000000014 = adm_make_object_tank(ADM_STATUS_TANK_WAITING_FOR_TANKER_DELIVERY);
    ent_tank_0000000015 = adm_make_object_tank(ADM_STATUS_TANK_RESET_WAITING_PUMPS);
    ent_tank_0000000016 = adm_make_object_tank(ADM_STATUS_TANK_RESET_WAITING_PUMPS);
    ent_tank_0000000017 = adm_make_object_tank(ADM_STATUS_TANK_RESET_WAITING_PUMPS);
    ent_tank_0000000018 = adm_make_object_tank(ADM_STATUS_TANK_RESET_WAITING_PUMPS);
    ent_tank_0000000019 = adm_make_object_tank(ADM_STATUS_TANK_RESET_WAITING_PUMPS);
    ent_tank_0000000020 = adm_make_object_tank(ADM_STATUS_TANK_RESET_WAITING_PUMPS);

    /* Fuel Grade */
    ent_fuel_grade_0000000021 = adm_make_object_fuel_grade();
    ent_fuel_grade_0000000022 = adm_make_object_fuel_grade();

    /* Transaction Policy */
    ent_transaction_policy_0000000023 = adm_make_object_transaction_policy();


    /* Object Fact Assignments */

    /* Pump */

    ent_pump_0000000001->atb_pump_number = 1;

    ent_pump_0000000002->atb_pump_number = 2;

    ent_pump_0000000003->atb_pump_number = 3;

    ent_pump_0000000004->atb_pump_number = 1001;

    ent_pump_0000000005->atb_pump_number = 1002;

    ent_pump_0000000006->atb_pump_number = 2001;

    ent_pump_0000000007->atb_pump_number = 2002;

    ent_pump_0000000008->atb_pump_number = 3001;

    ent_pump_0000000009->atb_pump_number = 3002;

    ent_pump_0000000010->atb_pump_number = 4001;

    ent_pump_0000000011->atb_pump_number = 4002;

    ent_pump_0000000012->atb_pump_number = 5001;

    ent_pump_0000000013->atb_pump_number = 5002;

    /* Tank */

    ent_tank_0000000014->atb_tank_number = 1001;
    ent_tank_0000000014->atb_tank_empty_flag = TRUE;
    ent_tank_0000000014->atb_tank_level = (adm_fxd_volume_typ)0.0;
    ent_tank_0000000014->atb_tank_capacity = (adm_fxd_volume_typ)100000.0;
    ent_tank_0000000014->atb_empty_threshold = (adm_fxd_volume_typ)0.040;

    ent_tank_0000000015->atb_tank_number = 1002;
    ent_tank_0000000015->atb_tank_empty_flag = FALSE;
    ent_tank_0000000015->atb_tank_level = (adm_fxd_volume_typ)10000.0;
    ent_tank_0000000015->atb_tank_capacity = (adm_fxd_volume_typ)200000.0;
    ent_tank_0000000015->atb_empty_threshold = (adm_fxd_volume_typ)0.040;

    ent_tank_0000000016->atb_tank_number = 1;
    ent_tank_0000000016->atb_tank_empty_flag = FALSE;
    ent_tank_0000000016->atb_tank_level = (adm_fxd_volume_typ)10.0;
    ent_tank_0000000016->atb_tank_capacity = (adm_fxd_volume_typ)60.0;
    ent_tank_0000000016->atb_empty_threshold = (adm_fxd_volume_typ)0.001;

    ent_tank_0000000017->atb_tank_number = 2;
    ent_tank_0000000017->atb_tank_empty_flag = FALSE;
    ent_tank_0000000017->atb_tank_level = (adm_fxd_volume_typ)20.0;
    ent_tank_0000000017->atb_tank_capacity = (adm_fxd_volume_typ)70.0;
    ent_tank_0000000017->atb_empty_threshold = (adm_fxd_volume_typ)0.002;

    ent_tank_0000000018->atb_tank_number = 3;
    ent_tank_0000000018->atb_tank_empty_flag = FALSE;
    ent_tank_0000000018->atb_tank_level = (adm_fxd_volume_typ)30.0;
    ent_tank_0000000018->atb_tank_capacity = (adm_fxd_volume_typ)80.0;
    ent_tank_0000000018->atb_empty_threshold = (adm_fxd_volume_typ)0.003;

    ent_tank_0000000019->atb_tank_number = 4;
    ent_tank_0000000019->atb_tank_empty_flag = FALSE;
    ent_tank_0000000019->atb_tank_level = (adm_fxd_volume_typ)40.0;
    ent_tank_0000000019->atb_tank_capacity = (adm_fxd_volume_typ)90.0;
    ent_tank_0000000019->atb_empty_threshold = (adm_fxd_volume_typ)0.004;

    ent_tank_0000000020->atb_tank_number = 5;
    ent_tank_0000000020->atb_tank_empty_flag = FALSE;
    ent_tank_0000000020->atb_tank_level = (adm_fxd_volume_typ)50.0;
    ent_tank_0000000020->atb_tank_capacity = (adm_fxd_volume_typ)100.0;
    ent_tank_0000000020->atb_empty_threshold = (adm_fxd_volume_typ)0.005;

    /* Fuel Grade */

    strcpy_s(ent_fuel_grade_0000000021->atb_grade_name, ADM_TYPE_SIZE_TEXT+1,(adm_str_text_typ*)&"Four Star");
    ent_fuel_grade_0000000021->atb_unit_price = (adm_fxd_money_typ)62.90;
    ent_fuel_grade_0000000021->atb_unit_volume = (adm_fxd_volume_typ)0.01;

    strcpy_s(ent_fuel_grade_0000000022->atb_grade_name, ADM_TYPE_SIZE_TEXT+1,(adm_str_text_typ*)&"Unleaded");
    ent_fuel_grade_0000000022->atb_unit_price = (adm_fxd_money_typ)59.50;
    ent_fuel_grade_0000000022->atb_unit_volume = (adm_fxd_volume_typ)0.01;

    /* Transaction Policy */

    ent_transaction_policy_0000000023->atb_next_transaction_number = 1;


    /* Bind Objects */

    /* Pump */
    adm_bind_object_pump(
        ent_pump_0000000001,
        6, 15, 25);
    adm_bind_object_pump(
        ent_pump_0000000002,
        6, 16, 25);
    adm_bind_object_pump(
        ent_pump_0000000003,
        6, 17, 25);
    adm_bind_object_pump(
        ent_pump_0000000004,
        6, 19, 25);
    adm_bind_object_pump(
        ent_pump_0000000005,
        6, 20, 25);
    adm_bind_object_pump(
        ent_pump_0000000006,
        6, 21, 25);
    adm_bind_object_pump(
        ent_pump_0000000007,
        6, 22, 25);
    adm_bind_object_pump(
        ent_pump_0000000008,
        6, 23, 25);
    adm_bind_object_pump(
        ent_pump_0000000009,
        6, 24, 25);
    adm_bind_object_pump(
        ent_pump_0000000010,
        6, 25, 25);
    adm_bind_object_pump(
        ent_pump_0000000011,
        6, 26, 25);
    adm_bind_object_pump(
        ent_pump_0000000012,
        6, 27, 25);
    adm_bind_object_pump(
        ent_pump_0000000013,
        6, 28, 25);

    /* Tank */
    adm_bind_object_tank(
        ent_tank_0000000014,
        6, 49, 25);
    adm_bind_object_tank(
        ent_tank_0000000015,
        6, 50, 25);
    adm_bind_object_tank(
        ent_tank_0000000016,
        6, 52, 25);
    adm_bind_object_tank(
        ent_tank_0000000017,
        6, 53, 25);
    adm_bind_object_tank(
        ent_tank_0000000018,
        6, 54, 25);
    adm_bind_object_tank(
        ent_tank_0000000019,
        6, 55, 25);
    adm_bind_object_tank(
        ent_tank_0000000020,
        6, 56, 25);

    /* Fuel Grade */
    adm_bind_object_fuel_grade(
        ent_fuel_grade_0000000021,
        6, 86, 25);
    adm_bind_object_fuel_grade(
        ent_fuel_grade_0000000022,
        6, 87, 25);

    /* Transaction Policy */
    adm_bind_object_transaction_policy(
        ent_transaction_policy_0000000023,
        6, 93, 25);


    /* Link Relations */

    /* Pump */

    adm_link_relation_pump_pumping_fuel_from_tank(
        ent_pump_0000000001,
        ent_tank_0000000014,
        6, 30, 25);

    adm_link_relation_pump_pumping_fuel_from_tank(
        ent_pump_0000000002,
        ent_tank_0000000015,
        6, 31, 25);

    adm_link_relation_pump_pumping_fuel_from_tank(
        ent_pump_0000000003,
        ent_tank_0000000015,
        6, 32, 25);

    adm_link_relation_pump_pumping_fuel_from_tank(
        ent_pump_0000000004,
        ent_tank_0000000016,
        6, 34, 25);

    adm_link_relation_pump_pumping_fuel_from_tank(
        ent_pump_0000000005,
        ent_tank_0000000016,
        6, 35, 25);

    adm_link_relation_pump_pumping_fuel_from_tank(
        ent_pump_0000000006,
        ent_tank_0000000017,
        6, 36, 25);

    adm_link_relation_pump_pumping_fuel_from_tank(
        ent_pump_0000000007,
        ent_tank_0000000017,
        6, 37, 25);

    adm_link_relation_pump_pumping_fuel_from_tank(
        ent_pump_0000000008,
        ent_tank_0000000018,
        6, 38, 25);

    adm_link_relation_pump_pumping_fuel_from_tank(
        ent_pump_0000000009,
        ent_tank_0000000018,
        6, 39, 25);

    adm_link_relation_pump_pumping_fuel_from_tank(
        ent_pump_0000000010,
        ent_tank_0000000019,
        6, 40, 25);

    adm_link_relation_pump_pumping_fuel_from_tank(
        ent_pump_0000000011,
        ent_tank_0000000019,
        6, 41, 25);

    adm_link_relation_pump_pumping_fuel_from_tank(
        ent_pump_0000000012,
        ent_tank_0000000020,
        6, 42, 25);

    adm_link_relation_pump_pumping_fuel_from_tank(
        ent_pump_0000000013,
        ent_tank_0000000020,
        6, 43, 25);

    /* Tank */

    adm_link_relation_tank_providing_fuel_for_pump(
        ent_tank_0000000014,
        ent_pump_0000000001,
        6, 67, 25);

    adm_link_relation_tank_providing_fuel_for_pump(
        ent_tank_0000000015,
        ent_pump_0000000002,
        6, 68, 25);

    adm_link_relation_tank_providing_fuel_for_pump(
        ent_tank_0000000015,
        ent_pump_0000000003,
        6, 69, 25);

    adm_link_relation_tank_providing_fuel_for_pump(
        ent_tank_0000000016,
        ent_pump_0000000004,
        6, 71, 25);

    adm_link_relation_tank_providing_fuel_for_pump(
        ent_tank_0000000016,
        ent_pump_0000000005,
        6, 72, 25);

    adm_link_relation_tank_providing_fuel_for_pump(
        ent_tank_0000000017,
        ent_pump_0000000006,
        6, 73, 25);

    adm_link_relation_tank_providing_fuel_for_pump(
        ent_tank_0000000017,
        ent_pump_0000000007,
        6, 74, 25);

    adm_link_relation_tank_providing_fuel_for_pump(
        ent_tank_0000000018,
        ent_pump_0000000008,
        6, 75, 25);

    adm_link_relation_tank_providing_fuel_for_pump(
        ent_tank_0000000018,
        ent_pump_0000000009,
        6, 76, 25);

    adm_link_relation_tank_providing_fuel_for_pump(
        ent_tank_0000000019,
        ent_pump_0000000010,
        6, 77, 25);

    adm_link_relation_tank_providing_fuel_for_pump(
        ent_tank_0000000019,
        ent_pump_0000000011,
        6, 78, 25);

    adm_link_relation_tank_providing_fuel_for_pump(
        ent_tank_0000000020,
        ent_pump_0000000012,
        6, 79, 25);

    adm_link_relation_tank_providing_fuel_for_pump(
        ent_tank_0000000020,
        ent_pump_0000000013,
        6, 80, 25);

    adm_link_relation_tank_stores_fuel_grade(
        ent_tank_0000000014,
        ent_fuel_grade_0000000021,
        6, 58, 25);

    adm_link_relation_tank_stores_fuel_grade(
        ent_tank_0000000015,
        ent_fuel_grade_0000000022,
        6, 59, 25);

    adm_link_relation_tank_stores_fuel_grade(
        ent_tank_0000000016,
        ent_fuel_grade_0000000022,
        6, 61, 25);

    adm_link_relation_tank_stores_fuel_grade(
        ent_tank_0000000017,
        ent_fuel_grade_0000000022,
        6, 62, 25);

    adm_link_relation_tank_stores_fuel_grade(
        ent_tank_0000000018,
        ent_fuel_grade_0000000022,
        6, 63, 25);

    adm_link_relation_tank_stores_fuel_grade(
        ent_tank_0000000019,
        ent_fuel_grade_0000000022,
        6, 64, 25);

    adm_link_relation_tank_stores_fuel_grade(
        ent_tank_0000000020,
        ent_fuel_grade_0000000022,
        6, 65, 25);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_INITIALISATION, "adm_initialisation_petrol_station_control");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */