
/* Simulator System Prototype Internals Header */

/* Display Entity Prototypes */

void adm_sim_display_entity_delivery(
    void);

void adm_sim_display_entity_pump(
    void);

void adm_sim_display_entity_tank(
    void);

void adm_sim_display_entity_transaction(
    void);

void adm_sim_display_entity_fuel_grade(
    void);

void adm_sim_display_entity_pending_transaction(
    void);

void adm_sim_display_entity_evaded_transaction(
    void);

void adm_sim_display_entity_transaction_policy(
    void);

void adm_sim_display_entity_paid_transaction(
    void);


/* Acquire Identity Event Prototypes */

void adm_sim_acquire_identity_event_delivery_fuel_unit_delivered(
    void);

void adm_sim_acquire_identity_event_delivery_delivery_complete(
    void);

void adm_sim_acquire_identity_event_delivery_delete_delivery(
    void);

void adm_sim_acquire_identity_event_delivery_create_delivery(
    void);

void adm_sim_acquire_identity_event_pump_gun_removed(
    void);

void adm_sim_acquire_identity_event_pump_gun_replaced(
    void);

void adm_sim_acquire_identity_event_pump_fuel_level_low(
    void);

void adm_sim_acquire_identity_event_pump_fuel_available(
    void);

void adm_sim_acquire_identity_event_pump_pump_enabled(
    void);

void adm_sim_acquire_identity_event_pump_trigger_depressed(
    void);

void adm_sim_acquire_identity_event_pump_trigger_released(
    void);

void adm_sim_acquire_identity_event_pump_customer_finished(
    void);

void adm_sim_acquire_identity_event_tank_level_below_threshold(
    void);

void adm_sim_acquire_identity_event_tank_level_above_threshold(
    void);

void adm_sim_acquire_identity_event_tank_tanker_delivery(
    void);

void adm_sim_acquire_identity_event_tank_fuel_used(
    void);

void adm_sim_acquire_identity_event_transaction_payment_received(
    void);

void adm_sim_acquire_identity_event_transaction_customer_absconds(
    void);

void adm_sim_acquire_identity_event_transaction_create_transaction(
    void);

void adm_sim_acquire_identity_event_transaction_close_transaction(
    void);


/* Acquire Identifier Event Prototypes */

void adm_sim_acquire_identifier_event_delivery_fuel_unit_delivered_delivery_identifier(
    void);

void adm_sim_acquire_identifier_event_delivery_delivery_complete_delivery_identifier(
    void);

void adm_sim_acquire_identifier_event_delivery_delete_delivery_delivery_identifier(
    void);

void adm_sim_acquire_identifier_event_pump_gun_removed_pump_identifier(
    void);

void adm_sim_acquire_identifier_event_pump_gun_replaced_pump_identifier(
    void);

void adm_sim_acquire_identifier_event_pump_fuel_level_low_pump_identifier(
    void);

void adm_sim_acquire_identifier_event_pump_fuel_available_pump_identifier(
    void);

void adm_sim_acquire_identifier_event_pump_pump_enabled_pump_identifier(
    void);

void adm_sim_acquire_identifier_event_pump_trigger_depressed_pump_identifier(
    void);

void adm_sim_acquire_identifier_event_pump_trigger_released_pump_identifier(
    void);

void adm_sim_acquire_identifier_event_pump_customer_finished_pump_identifier(
    void);

void adm_sim_acquire_identifier_event_tank_level_below_threshold_tank_identifier(
    void);

void adm_sim_acquire_identifier_event_tank_level_above_threshold_tank_identifier(
    void);

void adm_sim_acquire_identifier_event_tank_tanker_delivery_tank_identifier(
    void);

void adm_sim_acquire_identifier_event_tank_fuel_used_tank_identifier(
    void);

void adm_sim_acquire_identifier_event_transaction_payment_received_transaction_identifier(
    void);

void adm_sim_acquire_identifier_event_transaction_customer_absconds_transaction_identifier(
    void);

void adm_sim_acquire_identifier_event_transaction_close_transaction_transaction_identifier(
    void);


/* Display Event Prototypes */

void adm_sim_display_event_delivery_fuel_unit_delivered(
    const adm_ent_delivery_typ * const ent_delivery,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_delivery_delivery_complete(
    const adm_ent_delivery_typ * const ent_delivery,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_delivery_delete_delivery(
    const adm_ent_delivery_typ * const ent_delivery,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_delivery_create_delivery(
    const adm_int_equipment_number_typ evd_pump_number,
    const adm_int_time_hour_typ evd_timestamp_hours,
    const adm_int_time_minute_typ evd_timestamp_minutes,
    const adm_int_time_second_typ evd_timestamp_seconds,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_pump_gun_removed(
    const adm_ent_pump_typ * const ent_pump,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_pump_gun_replaced(
    const adm_ent_pump_typ * const ent_pump,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_pump_fuel_level_low(
    const adm_ent_pump_typ * const ent_pump,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_pump_fuel_available(
    const adm_ent_pump_typ * const ent_pump,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_pump_pump_enabled(
    const adm_ent_pump_typ * const ent_pump,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_pump_trigger_depressed(
    const adm_ent_pump_typ * const ent_pump,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_pump_trigger_released(
    const adm_ent_pump_typ * const ent_pump,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_pump_customer_finished(
    const adm_ent_pump_typ * const ent_pump,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_tank_level_below_threshold(
    const adm_ent_tank_typ * const ent_tank,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_tank_level_above_threshold(
    const adm_ent_tank_typ * const ent_tank,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_tank_tanker_delivery(
    const adm_ent_tank_typ * const ent_tank,
    const adm_fxd_volume_typ evd_added_volume,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_tank_fuel_used(
    const adm_ent_tank_typ * const ent_tank,
    const adm_fxd_volume_typ evd_delivered_volume,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_transaction_payment_received(
    const adm_ent_transaction_typ * const ent_transaction,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_transaction_customer_absconds(
    const adm_ent_transaction_typ * const ent_transaction,
    const adm_str_text_typ * const evd_customer_details,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_transaction_create_transaction(
    const adm_int_equipment_number_typ evd_delivery_pump,
    const adm_fxd_money_typ evd_delivery_cost,
    const adm_int_time_hour_typ evd_delivery_time_hours,
    const adm_int_time_minute_typ evd_delivery_time_minutes,
    const adm_int_time_second_typ evd_delivery_time_seconds,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_transaction_close_transaction(
    const adm_ent_transaction_typ * const ent_transaction,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);


/* Display State Prototypes */

void adm_sim_display_state_delivery_creating_delivery(
    adm_pool_target_delivery_typ * pool_target);

void adm_sim_display_state_delivery_calculating_price_of_unconstrained_delivery(
    adm_pool_target_delivery_typ * pool_target);

void adm_sim_display_state_delivery_delivery_complete_state(
    adm_pool_target_delivery_typ * pool_target);

void adm_sim_display_state_delivery_delivery_cancelled(
    adm_pool_target_delivery_typ * pool_target);

void adm_sim_display_state_delivery_delivery_vanishes(
    adm_pool_target_delivery_typ * pool_target);

void adm_sim_display_state_pump_waiting_for_customer(
    adm_pool_target_pump_typ * pool_target);

void adm_sim_display_state_pump_waiting_pump_enable(
    adm_pool_target_pump_typ * pool_target);

void adm_sim_display_state_pump_fuel_unavailable(
    adm_pool_target_pump_typ * pool_target);

void adm_sim_display_state_pump_fuel_delivery_complete(
    adm_pool_target_pump_typ * pool_target);

void adm_sim_display_state_pump_ready_to_pump(
    adm_pool_target_pump_typ * pool_target);

void adm_sim_display_state_pump_pumping_paused(
    adm_pool_target_pump_typ * pool_target);

void adm_sim_display_state_pump_pumping(
    adm_pool_target_pump_typ * pool_target);

void adm_sim_display_state_tank_checking_levels_after_tanker_delivery(
    adm_pool_target_tank_typ * pool_target);

void adm_sim_display_state_tank_waiting_for_tanker_delivery(
    adm_pool_target_tank_typ * pool_target);

void adm_sim_display_state_tank_reset_waiting_pumps(
    adm_pool_target_tank_typ * pool_target);

void adm_sim_display_state_tank_checking_levels_after_pump_usage(
    adm_pool_target_tank_typ * pool_target);

void adm_sim_display_state_tank_updating_fuel_levels(
    adm_pool_target_tank_typ * pool_target);

void adm_sim_display_state_transaction_creating_pending_transaction(
    adm_pool_target_transaction_typ * pool_target);

void adm_sim_display_state_transaction_paid_state(
    adm_pool_target_transaction_typ * pool_target);

void adm_sim_display_state_transaction_evaded_state(
    adm_pool_target_transaction_typ * pool_target);

void adm_sim_display_state_transaction_transaction_vanishes(
    adm_pool_target_transaction_typ * pool_target);


/* Find Event Name Prototype */

adm_base_string_typ * adm_sim_find_event_name(
    adm_base_integer_typ entity_index,
    adm_base_integer_typ entity_event_index);

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */