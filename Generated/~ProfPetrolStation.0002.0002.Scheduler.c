
#include "~ProfPetrolStation.0000.0000.Header.h"


/* Domain Scheduler */

void adm_scheduler_dom_petrol_station_control(
    void)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SCHEDULER, "adm_scheduler_dom_petrol_station_control");
    #endif

    if (adm_entity_system.ent_delivery.away_pool_head != NULL) adm_dispatcher_delivery();
    if (adm_entity_system.ent_pump.away_pool_head != NULL) adm_dispatcher_pump();
    if (adm_entity_system.ent_tank.away_pool_head != NULL) adm_dispatcher_tank();
    if (adm_entity_system.ent_transaction.away_pool_head != NULL) adm_dispatcher_transaction();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SCHEDULER, "adm_scheduler_dom_petrol_station_control");
    #endif
}

adm_base_boolean_typ adm_scheduler_determine_termination_dom_petrol_station_control(
    void)
{
    adm_base_boolean_typ event_pending;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SCHEDULER, "adm_scheduler_determine_termination_dom_petrol_station_control");
    #endif

    event_pending =
        (adm_entity_system.ent_delivery.away_pool_head != NULL) ||
        (adm_entity_system.ent_pump.away_pool_head != NULL) ||
        (adm_entity_system.ent_tank.away_pool_head != NULL) ||
        (adm_entity_system.ent_transaction.away_pool_head != NULL);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SCHEDULER, "adm_scheduler_determine_termination_dom_petrol_station_control");
    #endif

    return (event_pending);
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */