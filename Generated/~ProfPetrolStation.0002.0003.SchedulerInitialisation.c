
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Domain Scheduler Initialisation */

void adm_scheduler_initialisation_petrol_station_control(
    void)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_INITIALISATION, "adm_scheduler_initialisation_petrol_station_control");
    #endif

    adm_dispatch_home_pool_delivery();
    adm_dispatch_home_pool_pump();
    adm_dispatch_home_pool_tank();
    adm_dispatch_home_pool_transaction();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_INITIALISATION, "adm_scheduler_initialisation_petrol_station_control");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */