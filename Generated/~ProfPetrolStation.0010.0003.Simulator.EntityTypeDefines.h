
/* Simulator System Entity Type Defines Header */

/* Domain Enumerations */

typedef enum {
    ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL
} adm_sim_index_domain_typ;

/* Entity Enumerations */

typedef enum {
    ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_DELIVERY,
    ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_PUMP,
    ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_TANK,
    ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_TRANSACTION,
    ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_FUEL_GRADE,
    ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_PENDING_TRANSACTION,
    ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_EVADED_TRANSACTION,
    ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_TRANSACTION_POLICY,
    ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_PAID_TRANSACTION
} adm_sim_index_entity_typ;

/* Event Enumerations */

typedef enum {
    ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_DELIVERY_FUEL_UNIT_DELIVERED,
    ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_DELIVERY_DELIVERY_COMPLETE,
    ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_DELIVERY_DELETE_DELIVERY,
    ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_DELIVERY_CREATE_DELIVERY,
    ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_PUMP_GUN_REMOVED,
    ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_PUMP_GUN_REPLACED,
    ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_PUMP_FUEL_LEVEL_LOW,
    ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_PUMP_FUEL_AVAILABLE,
    ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_PUMP_PUMP_ENABLED,
    ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_PUMP_TRIGGER_DEPRESSED,
    ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_PUMP_TRIGGER_RELEASED,
    ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_PUMP_CUSTOMER_FINISHED,
    ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_TANK_LEVEL_BELOW_THRESHOLD,
    ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_TANK_LEVEL_ABOVE_THRESHOLD,
    ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_TANK_TANKER_DELIVERY,
    ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_TANK_FUEL_USED,
    ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_TRANSACTION_PAYMENT_RECEIVED,
    ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_TRANSACTION_CUSTOMER_ABSCONDS,
    ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_TRANSACTION_CREATE_TRANSACTION,
    ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_TRANSACTION_CLOSE_TRANSACTION
} adm_sim_index_event_typ;

/* Entity Display Widths */

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ status;
    adm_base_integer_typ atb_timestamp_hours;
    adm_base_integer_typ atb_timestamp_minutes;
    adm_base_integer_typ atb_timestamp_seconds;
    adm_base_integer_typ atb_volume_delivered;
    adm_base_integer_typ atb_cost;
} adm_sim_width_delivery_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ status;
    adm_base_integer_typ atb_pump_number;
} adm_sim_width_pump_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ status;
    adm_base_integer_typ atb_tank_number;
    adm_base_integer_typ atb_tank_empty_flag;
    adm_base_integer_typ atb_tank_level;
    adm_base_integer_typ atb_tank_capacity;
    adm_base_integer_typ atb_empty_threshold;
} adm_sim_width_tank_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ status;
    adm_base_integer_typ atb_transaction_number;
    adm_base_integer_typ atb_cost;
    adm_base_integer_typ atb_delivery_time_hours;
    adm_base_integer_typ atb_delivery_time_minutes;
    adm_base_integer_typ atb_delivery_time_seconds;
} adm_sim_width_transaction_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ atb_grade_name;
    adm_base_integer_typ atb_unit_price;
    adm_base_integer_typ atb_unit_volume;
} adm_sim_width_fuel_grade_typ;

typedef struct {
    adm_base_integer_typ identity;
} adm_sim_width_pending_transaction_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ atb_observations;
} adm_sim_width_evaded_transaction_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ atb_next_transaction_number;
} adm_sim_width_transaction_policy_typ;

typedef struct {
    adm_base_integer_typ identity;
} adm_sim_width_paid_transaction_typ;

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */