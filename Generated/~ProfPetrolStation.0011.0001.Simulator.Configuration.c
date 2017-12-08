
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Simulator System Configuration */

/* Domain Map */

adm_sim_domain_typ adm_sim_domain[] = {
    {"Petrol_Station_Control"},
    {SNULL}
};

/* Entity Map */

adm_sim_entity_typ adm_sim_entity[] = {
    {ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL, "Delivery", TRUE, adm_sim_display_entity_delivery},
    {ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL, "Pump", TRUE, adm_sim_display_entity_pump},
    {ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL, "Tank", TRUE, adm_sim_display_entity_tank},
    {ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL, "Transaction", TRUE, adm_sim_display_entity_transaction},
    {ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL, "Fuel_Grade", FALSE, adm_sim_display_entity_fuel_grade},
    {ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL, "Pending_Transaction", FALSE, adm_sim_display_entity_pending_transaction},
    {ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL, "Evaded_Transaction", FALSE, adm_sim_display_entity_evaded_transaction},
    {ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL, "Transaction_Policy", FALSE, adm_sim_display_entity_transaction_policy},
    {ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL, "Paid_Transaction", FALSE, adm_sim_display_entity_paid_transaction},
    {null, SNULL, null, NULL}
};

/* Event Map */

adm_sim_event_typ adm_sim_event[] = {
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_DELIVERY,
        "Fuel_unit_delivered",
        FALSE,
        adm_sim_acquire_identity_event_delivery_fuel_unit_delivered
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_DELIVERY,
        "Delivery_complete",
        FALSE,
        adm_sim_acquire_identity_event_delivery_delivery_complete
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_DELIVERY,
        "Delete_delivery",
        FALSE,
        adm_sim_acquire_identity_event_delivery_delete_delivery
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_DELIVERY,
        "Create_delivery",
        TRUE,
        adm_sim_acquire_identity_event_delivery_create_delivery
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_PUMP,
        "Gun_removed",
        FALSE,
        adm_sim_acquire_identity_event_pump_gun_removed
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_PUMP,
        "Gun_replaced",
        FALSE,
        adm_sim_acquire_identity_event_pump_gun_replaced
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_PUMP,
        "Fuel_level_low",
        FALSE,
        adm_sim_acquire_identity_event_pump_fuel_level_low
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_PUMP,
        "Fuel_available",
        FALSE,
        adm_sim_acquire_identity_event_pump_fuel_available
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_PUMP,
        "Pump_enabled",
        FALSE,
        adm_sim_acquire_identity_event_pump_pump_enabled
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_PUMP,
        "Trigger_depressed",
        FALSE,
        adm_sim_acquire_identity_event_pump_trigger_depressed
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_PUMP,
        "Trigger_released",
        FALSE,
        adm_sim_acquire_identity_event_pump_trigger_released
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_PUMP,
        "Customer_finished",
        FALSE,
        adm_sim_acquire_identity_event_pump_customer_finished
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_TANK,
        "Level_below_threshold",
        FALSE,
        adm_sim_acquire_identity_event_tank_level_below_threshold
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_TANK,
        "Level_above_threshold",
        FALSE,
        adm_sim_acquire_identity_event_tank_level_above_threshold
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_TANK,
        "Tanker_delivery",
        FALSE,
        adm_sim_acquire_identity_event_tank_tanker_delivery
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_TANK,
        "Fuel_used",
        FALSE,
        adm_sim_acquire_identity_event_tank_fuel_used
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_TRANSACTION,
        "Payment_received",
        FALSE,
        adm_sim_acquire_identity_event_transaction_payment_received
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_TRANSACTION,
        "Customer_absconds",
        FALSE,
        adm_sim_acquire_identity_event_transaction_customer_absconds
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_TRANSACTION,
        "Create_transaction",
        TRUE,
        adm_sim_acquire_identity_event_transaction_create_transaction
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_TRANSACTION,
        "Close_transaction",
        FALSE,
        adm_sim_acquire_identity_event_transaction_close_transaction
    },
    {
        null,
        null,
        SNULL,
        null,
        NULL
    }
};

/* Identifier Map */

adm_sim_identifier_typ adm_sim_identifier[] = {
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_DELIVERY,
        ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_DELIVERY_FUEL_UNIT_DELIVERED,
        "Delivery_Identifier",
        adm_sim_acquire_identifier_event_delivery_fuel_unit_delivered_delivery_identifier
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_DELIVERY,
        ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_DELIVERY_DELIVERY_COMPLETE,
        "Delivery_Identifier",
        adm_sim_acquire_identifier_event_delivery_delivery_complete_delivery_identifier
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_DELIVERY,
        ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_DELIVERY_DELETE_DELIVERY,
        "Delivery_Identifier",
        adm_sim_acquire_identifier_event_delivery_delete_delivery_delivery_identifier
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_PUMP,
        ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_PUMP_GUN_REMOVED,
        "Pump_Identifier",
        adm_sim_acquire_identifier_event_pump_gun_removed_pump_identifier
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_PUMP,
        ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_PUMP_GUN_REPLACED,
        "Pump_Identifier",
        adm_sim_acquire_identifier_event_pump_gun_replaced_pump_identifier
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_PUMP,
        ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_PUMP_FUEL_LEVEL_LOW,
        "Pump_Identifier",
        adm_sim_acquire_identifier_event_pump_fuel_level_low_pump_identifier
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_PUMP,
        ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_PUMP_FUEL_AVAILABLE,
        "Pump_Identifier",
        adm_sim_acquire_identifier_event_pump_fuel_available_pump_identifier
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_PUMP,
        ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_PUMP_PUMP_ENABLED,
        "Pump_Identifier",
        adm_sim_acquire_identifier_event_pump_pump_enabled_pump_identifier
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_PUMP,
        ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_PUMP_TRIGGER_DEPRESSED,
        "Pump_Identifier",
        adm_sim_acquire_identifier_event_pump_trigger_depressed_pump_identifier
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_PUMP,
        ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_PUMP_TRIGGER_RELEASED,
        "Pump_Identifier",
        adm_sim_acquire_identifier_event_pump_trigger_released_pump_identifier
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_PUMP,
        ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_PUMP_CUSTOMER_FINISHED,
        "Pump_Identifier",
        adm_sim_acquire_identifier_event_pump_customer_finished_pump_identifier
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_TANK,
        ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_TANK_LEVEL_BELOW_THRESHOLD,
        "Tank_Identifier",
        adm_sim_acquire_identifier_event_tank_level_below_threshold_tank_identifier
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_TANK,
        ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_TANK_LEVEL_ABOVE_THRESHOLD,
        "Tank_Identifier",
        adm_sim_acquire_identifier_event_tank_level_above_threshold_tank_identifier
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_TANK,
        ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_TANK_TANKER_DELIVERY,
        "Tank_Identifier",
        adm_sim_acquire_identifier_event_tank_tanker_delivery_tank_identifier
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_TANK,
        ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_TANK_FUEL_USED,
        "Tank_Identifier",
        adm_sim_acquire_identifier_event_tank_fuel_used_tank_identifier
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_TRANSACTION,
        ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_TRANSACTION_PAYMENT_RECEIVED,
        "Transaction_Identifier",
        adm_sim_acquire_identifier_event_transaction_payment_received_transaction_identifier
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_TRANSACTION,
        ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_TRANSACTION_CUSTOMER_ABSCONDS,
        "Transaction_Identifier",
        adm_sim_acquire_identifier_event_transaction_customer_absconds_transaction_identifier
    },
    {
        ADM_SIM_INDEX_DOMAIN_PETROL_STATION_CONTROL,
        ADM_SIM_INDEX_ENTITY_PETROL_STATION_CONTROL_TRANSACTION,
        ADM_SIM_INDEX_EVENT_PETROL_STATION_CONTROL_TRANSACTION_CLOSE_TRANSACTION,
        "Transaction_Identifier",
        adm_sim_acquire_identifier_event_transaction_close_transaction_transaction_identifier
    },
    {
        null,
        null,
        null,
        SNULL,
        NULL
    }
};


/* Find Event Name From Event Index */

adm_base_string_typ * adm_sim_find_event_name(
    adm_base_integer_typ entity_index,
    adm_base_integer_typ entity_event_index)
{
    adm_base_integer_typ index;

    adm_base_boolean_typ event_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_find_event_name");
    #endif

    index = 0;

    event_not_found = TRUE;

    while (event_not_found) {

        if (adm_sim_event[index].entity == entity_index) {

            index += entity_event_index;

            event_not_found = FALSE;

        } else {

            ++index;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_find_event_name");
    #endif

    return (adm_sim_event[index].name);
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */