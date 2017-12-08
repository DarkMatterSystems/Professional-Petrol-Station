
/* Entity Type Defines Header */

/* Entity Status Type Defines */

typedef enum {
    ADM_STATUS_DELIVERY_CREATING_DELIVERY,
    ADM_STATUS_DELIVERY_CALCULATING_PRICE_OF_UNCONSTRAINED_DELIVERY,
    ADM_STATUS_DELIVERY_DELIVERY_COMPLETE_STATE,
    ADM_STATUS_DELIVERY_DELIVERY_CANCELLED,
    ADM_STATUS_DELIVERY_DELIVERY_VANISHES
} adm_sta_delivery_typ;

typedef enum {
    ADM_STATUS_PUMP_WAITING_FOR_CUSTOMER,
    ADM_STATUS_PUMP_WAITING_PUMP_ENABLE,
    ADM_STATUS_PUMP_FUEL_UNAVAILABLE,
    ADM_STATUS_PUMP_FUEL_DELIVERY_COMPLETE,
    ADM_STATUS_PUMP_READY_TO_PUMP,
    ADM_STATUS_PUMP_PUMPING_PAUSED,
    ADM_STATUS_PUMP_PUMPING
} adm_sta_pump_typ;

typedef enum {
    ADM_STATUS_TANK_CHECKING_LEVELS_AFTER_TANKER_DELIVERY,
    ADM_STATUS_TANK_WAITING_FOR_TANKER_DELIVERY,
    ADM_STATUS_TANK_RESET_WAITING_PUMPS,
    ADM_STATUS_TANK_CHECKING_LEVELS_AFTER_PUMP_USAGE,
    ADM_STATUS_TANK_UPDATING_FUEL_LEVELS
} adm_sta_tank_typ;

typedef enum {
    ADM_STATUS_TRANSACTION_CREATING_PENDING_TRANSACTION,
    ADM_STATUS_TRANSACTION_PAID_STATE,
    ADM_STATUS_TRANSACTION_EVADED_STATE,
    ADM_STATUS_TRANSACTION_TRANSACTION_VANISHES
} adm_sta_transaction_typ;


/* Entity Event Type Defines */

typedef enum {
    ADM_EVENT_DELIVERY_FUEL_UNIT_DELIVERED,
    ADM_EVENT_DELIVERY_DELIVERY_COMPLETE,
    ADM_EVENT_DELIVERY_DELETE_DELIVERY,
    ADM_EVENT_DELIVERY_CREATE_DELIVERY
} adm_evt_delivery_typ;

typedef enum {
    ADM_EVENT_PUMP_GUN_REMOVED,
    ADM_EVENT_PUMP_GUN_REPLACED,
    ADM_EVENT_PUMP_FUEL_LEVEL_LOW,
    ADM_EVENT_PUMP_FUEL_AVAILABLE,
    ADM_EVENT_PUMP_PUMP_ENABLED,
    ADM_EVENT_PUMP_TRIGGER_DEPRESSED,
    ADM_EVENT_PUMP_TRIGGER_RELEASED,
    ADM_EVENT_PUMP_CUSTOMER_FINISHED
} adm_evt_pump_typ;

typedef enum {
    ADM_EVENT_TANK_LEVEL_BELOW_THRESHOLD,
    ADM_EVENT_TANK_LEVEL_ABOVE_THRESHOLD,
    ADM_EVENT_TANK_TANKER_DELIVERY,
    ADM_EVENT_TANK_FUEL_USED
} adm_evt_tank_typ;

typedef enum {
    ADM_EVENT_TRANSACTION_PAYMENT_RECEIVED,
    ADM_EVENT_TRANSACTION_CUSTOMER_ABSCONDS,
    ADM_EVENT_TRANSACTION_CREATE_TRANSACTION,
    ADM_EVENT_TRANSACTION_CLOSE_TRANSACTION
} adm_evt_transaction_typ;


/* Entity Type Defines */

/* Delivery */

typedef struct adm_ent_delivery {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_sta_delivery_typ status;
    adm_int_time_hour_typ atb_timestamp_hours;
    adm_int_time_minute_typ atb_timestamp_minutes;
    adm_int_time_second_typ atb_timestamp_seconds;
    adm_fxd_volume_typ atb_volume_delivered;
    adm_fxd_money_typ atb_cost;
    struct adm_rel_delivery_being_made_using_pump * rel_being_made_using_pump_head;
    struct adm_rel_delivery_being_made_using_pump * rel_being_made_using_pump_tail;
    struct adm_ent_delivery * back;
    struct adm_ent_delivery * next;
} adm_ent_delivery_typ;

/* Pump */

typedef struct adm_ent_pump {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_sta_pump_typ status;
    adm_int_equipment_number_typ atb_pump_number;
    struct adm_rel_pump_pumping_fuel_from_tank * rel_pumping_fuel_from_tank_head;
    struct adm_rel_pump_pumping_fuel_from_tank * rel_pumping_fuel_from_tank_tail;
    struct adm_rel_pump_being_used_for_delivery * rel_being_used_for_delivery_head;
    struct adm_rel_pump_being_used_for_delivery * rel_being_used_for_delivery_tail;
    struct adm_ent_pump * back;
    struct adm_ent_pump * next;
} adm_ent_pump_typ;

/* Tank */

typedef struct adm_ent_tank {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_sta_tank_typ status;
    adm_int_equipment_number_typ atb_tank_number;
    adm_bln_flag_typ atb_tank_empty_flag;
    adm_fxd_volume_typ atb_tank_level;
    adm_fxd_volume_typ atb_tank_capacity;
    adm_fxd_volume_typ atb_empty_threshold;
    struct adm_rel_tank_providing_fuel_for_pump * rel_providing_fuel_for_pump_head;
    struct adm_rel_tank_providing_fuel_for_pump * rel_providing_fuel_for_pump_tail;
    struct adm_rel_tank_stores_fuel_grade * rel_stores_fuel_grade_head;
    struct adm_rel_tank_stores_fuel_grade * rel_stores_fuel_grade_tail;
    struct adm_ent_tank * back;
    struct adm_ent_tank * next;
} adm_ent_tank_typ;

/* Transaction */

typedef struct adm_ent_transaction {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_sta_transaction_typ status;
    adm_int_business_number_typ atb_transaction_number;
    adm_fxd_money_typ atb_cost;
    adm_int_time_hour_typ atb_delivery_time_hours;
    adm_int_time_minute_typ atb_delivery_time_minutes;
    adm_int_time_second_typ atb_delivery_time_seconds;
    struct adm_rel_transaction_governed_by_transaction_policy * rel_governed_by_transaction_policy_head;
    struct adm_rel_transaction_governed_by_transaction_policy * rel_governed_by_transaction_policy_tail;
    struct adm_rel_transaction_generalisation_pending_transaction * rel_generalisation_pending_transaction_head;
    struct adm_rel_transaction_generalisation_pending_transaction * rel_generalisation_pending_transaction_tail;
    struct adm_rel_transaction_generalisation_paid_transaction * rel_generalisation_paid_transaction_head;
    struct adm_rel_transaction_generalisation_paid_transaction * rel_generalisation_paid_transaction_tail;
    struct adm_rel_transaction_generalisation_evaded_transaction * rel_generalisation_evaded_transaction_head;
    struct adm_rel_transaction_generalisation_evaded_transaction * rel_generalisation_evaded_transaction_tail;
    struct adm_ent_transaction * back;
    struct adm_ent_transaction * next;
} adm_ent_transaction_typ;

/* Fuel Grade */

typedef struct adm_ent_fuel_grade {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_base_integer_typ ignore;
    adm_str_text_typ * atb_grade_name;
    adm_fxd_money_typ atb_unit_price;
    adm_fxd_volume_typ atb_unit_volume;
    struct adm_ent_fuel_grade * back;
    struct adm_ent_fuel_grade * next;
} adm_ent_fuel_grade_typ;

/* Pending Transaction */

typedef struct adm_ent_pending_transaction {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_base_integer_typ ignore;
    struct adm_rel_pending_transaction_pending_for_pump * rel_pending_for_pump_head;
    struct adm_rel_pending_transaction_pending_for_pump * rel_pending_for_pump_tail;
    struct adm_ent_pending_transaction * back;
    struct adm_ent_pending_transaction * next;
} adm_ent_pending_transaction_typ;

/* Evaded Transaction */

typedef struct adm_ent_evaded_transaction {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_base_integer_typ ignore;
    adm_str_text_typ * atb_observations;
    struct adm_ent_evaded_transaction * back;
    struct adm_ent_evaded_transaction * next;
} adm_ent_evaded_transaction_typ;

/* Transaction Policy */

typedef struct adm_ent_transaction_policy {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_base_integer_typ ignore;
    adm_int_business_number_typ atb_next_transaction_number;
    struct adm_ent_transaction_policy * back;
    struct adm_ent_transaction_policy * next;
} adm_ent_transaction_policy_typ;

/* Paid Transaction */

typedef struct adm_ent_paid_transaction {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_base_integer_typ ignore;
    struct adm_ent_paid_transaction * back;
    struct adm_ent_paid_transaction * next;
} adm_ent_paid_transaction_typ;


/* Relationship Type Defines */

typedef struct adm_rel_delivery_being_made_using_pump {
    adm_ent_pump_typ * ent_pump;
    struct adm_rel_delivery_being_made_using_pump * back;
    struct adm_rel_delivery_being_made_using_pump * next;
} adm_rel_delivery_being_made_using_pump_typ;

typedef struct adm_rel_pump_pumping_fuel_from_tank {
    adm_ent_tank_typ * ent_tank;
    struct adm_rel_pump_pumping_fuel_from_tank * back;
    struct adm_rel_pump_pumping_fuel_from_tank * next;
} adm_rel_pump_pumping_fuel_from_tank_typ;

typedef struct adm_rel_pump_being_used_for_delivery {
    adm_ent_delivery_typ * ent_delivery;
    struct adm_rel_pump_being_used_for_delivery * back;
    struct adm_rel_pump_being_used_for_delivery * next;
} adm_rel_pump_being_used_for_delivery_typ;

typedef struct adm_rel_tank_providing_fuel_for_pump {
    adm_ent_pump_typ * ent_pump;
    struct adm_rel_tank_providing_fuel_for_pump * back;
    struct adm_rel_tank_providing_fuel_for_pump * next;
} adm_rel_tank_providing_fuel_for_pump_typ;

typedef struct adm_rel_tank_stores_fuel_grade {
    adm_ent_fuel_grade_typ * ent_fuel_grade;
    struct adm_rel_tank_stores_fuel_grade * back;
    struct adm_rel_tank_stores_fuel_grade * next;
} adm_rel_tank_stores_fuel_grade_typ;

typedef struct adm_rel_transaction_governed_by_transaction_policy {
    adm_ent_transaction_policy_typ * ent_transaction_policy;
    struct adm_rel_transaction_governed_by_transaction_policy * back;
    struct adm_rel_transaction_governed_by_transaction_policy * next;
} adm_rel_transaction_governed_by_transaction_policy_typ;

typedef struct adm_rel_transaction_generalisation_pending_transaction {
    adm_ent_pending_transaction_typ * ent_pending_transaction;
    struct adm_rel_transaction_generalisation_pending_transaction * back;
    struct adm_rel_transaction_generalisation_pending_transaction * next;
} adm_rel_transaction_generalisation_pending_transaction_typ;

typedef struct adm_rel_transaction_generalisation_paid_transaction {
    adm_ent_paid_transaction_typ * ent_paid_transaction;
    struct adm_rel_transaction_generalisation_paid_transaction * back;
    struct adm_rel_transaction_generalisation_paid_transaction * next;
} adm_rel_transaction_generalisation_paid_transaction_typ;

typedef struct adm_rel_transaction_generalisation_evaded_transaction {
    adm_ent_evaded_transaction_typ * ent_evaded_transaction;
    struct adm_rel_transaction_generalisation_evaded_transaction * back;
    struct adm_rel_transaction_generalisation_evaded_transaction * next;
} adm_rel_transaction_generalisation_evaded_transaction_typ;

typedef struct adm_rel_pending_transaction_pending_for_pump {
    adm_ent_pump_typ * ent_pump;
    struct adm_rel_pending_transaction_pending_for_pump * back;
    struct adm_rel_pending_transaction_pending_for_pump * next;
} adm_rel_pending_transaction_pending_for_pump_typ;


/* Entity Dataset Type Defines */

typedef struct {
    const adm_int_equipment_number_typ pump_number;
    const adm_int_time_hour_typ timestamp_hours;
    const adm_int_time_minute_typ timestamp_minutes;
    const adm_int_time_second_typ timestamp_seconds;
} adm_dst_delivery_pump_number_typ;

typedef struct {
    const adm_fxd_volume_typ added_volume;
} adm_dst_tank_added_volume_typ;

typedef struct {
    const adm_fxd_volume_typ delivered_volume;
} adm_dst_tank_delivered_volume_typ;

typedef struct {
    const adm_int_equipment_number_typ delivery_pump;
    const adm_fxd_money_typ delivery_cost;
    const adm_int_time_hour_typ delivery_time_hours;
    const adm_int_time_minute_typ delivery_time_minutes;
    const adm_int_time_second_typ delivery_time_seconds;
} adm_dst_transaction_creation_data_typ;

typedef struct {
    const adm_str_text_typ * const customer_details;
} adm_dst_transaction_customer_details_typ;


/* Error Location Type Define */

typedef struct {
    adm_base_integer_typ file;
    adm_base_integer_typ line;
    adm_base_integer_typ rank;
} adm_error_location_typ;


/* Entity Event Pool Target Type Defines */

typedef struct adm_pool_target_delivery {
    adm_evt_delivery_typ evente;
    adm_ent_delivery_typ * ent_delivery;
    adm_error_location_typ error_location;
    struct adm_pool_target_delivery * next;
    union {
        adm_dst_delivery_pump_number_typ * pump_number;
    } dataset;
} adm_pool_target_delivery_typ;

typedef struct adm_pool_target_pump {
    adm_evt_pump_typ evente;
    adm_ent_pump_typ * ent_pump;
    adm_error_location_typ error_location;
    struct adm_pool_target_pump * next;
} adm_pool_target_pump_typ;

typedef struct adm_pool_target_tank {
    adm_evt_tank_typ evente;
    adm_ent_tank_typ * ent_tank;
    adm_error_location_typ error_location;
    struct adm_pool_target_tank * next;
    union {
        adm_dst_tank_added_volume_typ * added_volume;
        adm_dst_tank_delivered_volume_typ * delivered_volume;
    } dataset;
} adm_pool_target_tank_typ;

typedef struct adm_pool_target_transaction {
    adm_evt_transaction_typ evente;
    adm_ent_transaction_typ * ent_transaction;
    adm_error_location_typ error_location;
    struct adm_pool_target_transaction * next;
    union {
        adm_dst_transaction_creation_data_typ * creation_data;
        adm_dst_transaction_customer_details_typ * customer_details;
    } dataset;
} adm_pool_target_transaction_typ;


/* Entity System - Entity Type Defines */

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_delivery_typ * live_list_head;
    adm_ent_delivery_typ * live_list_tail;
    adm_ent_delivery_typ * dead_list_head;
    adm_ent_delivery_typ * dead_list_tail;
    adm_pool_target_delivery_typ * home_pool_head;
    adm_pool_target_delivery_typ * home_pool_tail;
    adm_pool_target_delivery_typ * away_pool_head;
    adm_pool_target_delivery_typ * away_pool_tail;
} adm_entity_system_delivery_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_pump_typ * live_list_head;
    adm_ent_pump_typ * live_list_tail;
    adm_ent_pump_typ * dead_list_head;
    adm_ent_pump_typ * dead_list_tail;
    adm_pool_target_pump_typ * home_pool_head;
    adm_pool_target_pump_typ * home_pool_tail;
    adm_pool_target_pump_typ * away_pool_head;
    adm_pool_target_pump_typ * away_pool_tail;
} adm_entity_system_pump_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_tank_typ * live_list_head;
    adm_ent_tank_typ * live_list_tail;
    adm_ent_tank_typ * dead_list_head;
    adm_ent_tank_typ * dead_list_tail;
    adm_pool_target_tank_typ * home_pool_head;
    adm_pool_target_tank_typ * home_pool_tail;
    adm_pool_target_tank_typ * away_pool_head;
    adm_pool_target_tank_typ * away_pool_tail;
} adm_entity_system_tank_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_transaction_typ * live_list_head;
    adm_ent_transaction_typ * live_list_tail;
    adm_ent_transaction_typ * dead_list_head;
    adm_ent_transaction_typ * dead_list_tail;
    adm_pool_target_transaction_typ * home_pool_head;
    adm_pool_target_transaction_typ * home_pool_tail;
    adm_pool_target_transaction_typ * away_pool_head;
    adm_pool_target_transaction_typ * away_pool_tail;
} adm_entity_system_transaction_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_fuel_grade_typ * live_list_head;
    adm_ent_fuel_grade_typ * live_list_tail;
    adm_ent_fuel_grade_typ * dead_list_head;
    adm_ent_fuel_grade_typ * dead_list_tail;
} adm_entity_system_fuel_grade_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_pending_transaction_typ * live_list_head;
    adm_ent_pending_transaction_typ * live_list_tail;
    adm_ent_pending_transaction_typ * dead_list_head;
    adm_ent_pending_transaction_typ * dead_list_tail;
} adm_entity_system_pending_transaction_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_evaded_transaction_typ * live_list_head;
    adm_ent_evaded_transaction_typ * live_list_tail;
    adm_ent_evaded_transaction_typ * dead_list_head;
    adm_ent_evaded_transaction_typ * dead_list_tail;
} adm_entity_system_evaded_transaction_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_transaction_policy_typ * live_list_head;
    adm_ent_transaction_policy_typ * live_list_tail;
    adm_ent_transaction_policy_typ * dead_list_head;
    adm_ent_transaction_policy_typ * dead_list_tail;
} adm_entity_system_transaction_policy_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_paid_transaction_typ * live_list_head;
    adm_ent_paid_transaction_typ * live_list_tail;
    adm_ent_paid_transaction_typ * dead_list_head;
    adm_ent_paid_transaction_typ * dead_list_tail;
} adm_entity_system_paid_transaction_typ;


/* Entity System - System Type Define */

typedef struct {
    adm_entity_system_delivery_typ ent_delivery;
    adm_entity_system_pump_typ ent_pump;
    adm_entity_system_tank_typ ent_tank;
    adm_entity_system_transaction_typ ent_transaction;
    adm_entity_system_fuel_grade_typ ent_fuel_grade;
    adm_entity_system_pending_transaction_typ ent_pending_transaction;
    adm_entity_system_evaded_transaction_typ ent_evaded_transaction;
    adm_entity_system_transaction_policy_typ ent_transaction_policy;
    adm_entity_system_paid_transaction_typ ent_paid_transaction;
} adm_entity_system_typ;

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */