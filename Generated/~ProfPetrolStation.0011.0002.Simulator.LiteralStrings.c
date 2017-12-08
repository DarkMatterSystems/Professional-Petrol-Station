
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Simulator System Literal Strings */

/* Status Literal Strings */

adm_base_string_typ * adm_sim_status_delivery[] = {
    "Creating_Delivery",
    "Calculating_Price_Of_Unconstrained_Delivery",
    "Delivery_Complete_State",
    "Delivery_Cancelled",
    "Delivery_Vanishes"
};

adm_base_string_typ * adm_sim_status_pump[] = {
    "Waiting_For_Customer",
    "Waiting_Pump_Enable",
    "Fuel_Unavailable",
    "Fuel_Delivery_Complete",
    "Ready_To_Pump",
    "Pumping_Paused",
    "Pumping"
};

adm_base_string_typ * adm_sim_status_tank[] = {
    "Checking_Levels_After_Tanker_Delivery",
    "Waiting_For_Tanker_Delivery",
    "Reset_Waiting_Pumps",
    "Checking_Levels_After_Pump_Usage",
    "Updating_Fuel_Levels"
};

adm_base_string_typ * adm_sim_status_transaction[] = {
    "Creating_Pending_Transaction",
    "Paid_State",
    "Evaded_State",
    "Transaction_Vanishes"
};

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */