
/* System Prototypes Header */

/* Main Prototype */

int main(
    int,
    char * []);


/* System Library */

void * adm_allocate_memory(
    adm_base_integer_typ amount);

void adm_deallocate_memory(
    const void * memory);

void adm_open_stream_file(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_close_stream_file(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_write_int(
    adm_base_integer_typ number);

void adm_write_bln(
    adm_base_boolean_typ value);

void adm_write_fxd(
    adm_base_fixed_typ number);

void adm_write_flt(
    adm_base_float_typ number);

void adm_write_str(
    const adm_base_string_typ * const string);

void adm_write_newline(void);

void adm_template_tab_in(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_template_tab_out(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_display_tab_in(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_display_tab_out(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_convert_string_upper_case(
    const adm_base_string_typ * const source_string,
    adm_base_string_typ * const target_string);

void adm_convert_string_lower_case(
    const adm_base_string_typ * const source_string,
    adm_base_string_typ * const target_string);

void adm_convert_string_sentence_case(
    const adm_base_string_typ * const source_string,
    adm_base_string_typ * const target_string);

void adm_convert_string_capital_case(
    const adm_base_string_typ * const source_string,
    adm_base_string_typ * const target_string);

void adm_convert_string_remove_spaces(
    const adm_base_string_typ * const source_string,
    adm_base_string_typ * const target_string);

void adm_convert_string_convert_underlines(
    const adm_base_string_typ * const source_string,
    adm_base_string_typ * const target_string);

void adm_integrity_check(void);


#if ADM_PROBE

void adm_probe_enter(
    adm_probe_group_typ   group,
    adm_base_string_typ * procedure_name);

void adm_probe_leave(
    adm_probe_group_typ   group,
    adm_base_string_typ * procedure_name);

void adm_add_spaces(
    adm_base_string_typ  * space_string,
    adm_base_integer_typ   space_number);

#endif


/* System Error Handler */

void adm_error_report(
    adm_err_number_typ          error,
    adm_err_file_typ            file,
    adm_err_line_typ            line,
    adm_err_rank_typ            rank,
    adm_err_problem_typ       * source,
    adm_base_integer_typ        identity,
    adm_err_problem_typ       * relation,
    const adm_err_problem_typ * target);


/* Initialisation Prototype */

void adm_initialisation(void);


/* Domain Initialisation Prototypes */

void adm_initialisation_petrol_station_control(void);


/* System Scheduler Prototypes */

void adm_scheduler(void);

void adm_scheduler_dom_petrol_station_control(void);


/* System Initialisation Scheduler Prototypes */

void adm_scheduler_initialisation(void);

void adm_scheduler_initialisation_petrol_station_control(void);


/* System Determine Termination Scheduler Prototypes */

adm_base_boolean_typ adm_scheduler_determine_termination(void);

adm_base_boolean_typ adm_scheduler_determine_termination_dom_petrol_station_control(void);


/* Data Access Prototypes */

adm_ent_delivery_typ * adm_make_object_delivery(
    adm_sta_delivery_typ status);

adm_ent_pump_typ * adm_make_object_pump(
    adm_sta_pump_typ status);

adm_ent_tank_typ * adm_make_object_tank(
    adm_sta_tank_typ status);

adm_ent_transaction_typ * adm_make_object_transaction(
    adm_sta_transaction_typ status);

adm_ent_fuel_grade_typ * adm_make_object_fuel_grade(void);

adm_ent_pending_transaction_typ * adm_make_object_pending_transaction(void);

adm_ent_evaded_transaction_typ * adm_make_object_evaded_transaction(void);

adm_ent_transaction_policy_typ * adm_make_object_transaction_policy(void);

adm_ent_paid_transaction_typ * adm_make_object_paid_transaction(void);

void adm_bind_object_delivery(
    adm_ent_delivery_typ * ent_delivery,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_pump(
    adm_ent_pump_typ * ent_pump,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_tank(
    adm_ent_tank_typ * ent_tank,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_transaction(
    adm_ent_transaction_typ * ent_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_fuel_grade(
    adm_ent_fuel_grade_typ * ent_fuel_grade,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_pending_transaction(
    adm_ent_pending_transaction_typ * ent_pending_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_evaded_transaction(
    adm_ent_evaded_transaction_typ * ent_evaded_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_transaction_policy(
    adm_ent_transaction_policy_typ * ent_transaction_policy,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_paid_transaction(
    adm_ent_paid_transaction_typ * ent_paid_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_delivery(
    void * source_object,
    adm_ent_delivery_typ * ent_delivery,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_pump(
    void * source_object,
    adm_ent_pump_typ * ent_pump,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_tank(
    void * source_object,
    adm_ent_tank_typ * ent_tank,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_transaction(
    void * source_object,
    adm_ent_transaction_typ * ent_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_fuel_grade(
    void * source_object,
    adm_ent_fuel_grade_typ * ent_fuel_grade,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_pending_transaction(
    void * source_object,
    adm_ent_pending_transaction_typ * ent_pending_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_evaded_transaction(
    void * source_object,
    adm_ent_evaded_transaction_typ * ent_evaded_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_transaction_policy(
    void * source_object,
    adm_ent_transaction_policy_typ * ent_transaction_policy,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_paid_transaction(
    void * source_object,
    adm_ent_paid_transaction_typ * ent_paid_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_delivery_being_made_using_pump(
    adm_ent_delivery_typ * ent_source_delivery,
    adm_ent_pump_typ * ent_target_pump,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_pump_pumping_fuel_from_tank(
    adm_ent_pump_typ * ent_source_pump,
    adm_ent_tank_typ * ent_target_tank,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_pump_being_used_for_delivery(
    adm_ent_pump_typ * ent_source_pump,
    adm_ent_delivery_typ * ent_target_delivery,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_tank_providing_fuel_for_pump(
    adm_ent_tank_typ * ent_source_tank,
    adm_ent_pump_typ * ent_target_pump,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_tank_stores_fuel_grade(
    adm_ent_tank_typ * ent_source_tank,
    adm_ent_fuel_grade_typ * ent_target_fuel_grade,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_transaction_governed_by_transaction_policy(
    adm_ent_transaction_typ * ent_source_transaction,
    adm_ent_transaction_policy_typ * ent_target_transaction_policy,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_transaction_generalisation_pending_transaction(
    adm_ent_transaction_typ * ent_source_transaction,
    adm_ent_pending_transaction_typ * ent_target_pending_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_transaction_generalisation_paid_transaction(
    adm_ent_transaction_typ * ent_source_transaction,
    adm_ent_paid_transaction_typ * ent_target_paid_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_transaction_generalisation_evaded_transaction(
    adm_ent_transaction_typ * ent_source_transaction,
    adm_ent_evaded_transaction_typ * ent_target_evaded_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_pending_transaction_pending_for_pump(
    adm_ent_pending_transaction_typ * ent_source_pending_transaction,
    adm_ent_pump_typ * ent_target_pump,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_delivery_being_made_using_pump(
    adm_ent_delivery_typ * ent_delivery,
    adm_rel_delivery_being_made_using_pump_typ * rel_delivery_being_made_using_pump,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_pump_pumping_fuel_from_tank(
    adm_ent_pump_typ * ent_pump,
    adm_rel_pump_pumping_fuel_from_tank_typ * rel_pump_pumping_fuel_from_tank,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_pump_being_used_for_delivery(
    adm_ent_pump_typ * ent_pump,
    adm_rel_pump_being_used_for_delivery_typ * rel_pump_being_used_for_delivery,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_tank_providing_fuel_for_pump(
    adm_ent_tank_typ * ent_tank,
    adm_rel_tank_providing_fuel_for_pump_typ * rel_tank_providing_fuel_for_pump,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_tank_stores_fuel_grade(
    adm_ent_tank_typ * ent_tank,
    adm_rel_tank_stores_fuel_grade_typ * rel_tank_stores_fuel_grade,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_transaction_governed_by_transaction_policy(
    adm_ent_transaction_typ * ent_transaction,
    adm_rel_transaction_governed_by_transaction_policy_typ * rel_transaction_governed_by_transaction_policy,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_transaction_generalisation_pending_transaction(
    adm_ent_transaction_typ * ent_transaction,
    adm_rel_transaction_generalisation_pending_transaction_typ * rel_transaction_generalisation_pending_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_transaction_generalisation_paid_transaction(
    adm_ent_transaction_typ * ent_transaction,
    adm_rel_transaction_generalisation_paid_transaction_typ * rel_transaction_generalisation_paid_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_transaction_generalisation_evaded_transaction(
    adm_ent_transaction_typ * ent_transaction,
    adm_rel_transaction_generalisation_evaded_transaction_typ * rel_transaction_generalisation_evaded_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_pending_transaction_pending_for_pump(
    adm_ent_pending_transaction_typ * ent_pending_transaction,
    adm_rel_pending_transaction_pending_for_pump_typ * rel_pending_transaction_pending_for_pump,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_delivery(
    const adm_ent_delivery_typ * const ent_delivery,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_object_existent_pump(
    const adm_ent_pump_typ * const ent_pump,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_object_existent_tank(
    const adm_ent_tank_typ * const ent_tank,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_object_existent_transaction(
    const adm_ent_transaction_typ * const ent_transaction,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_object_existent_fuel_grade(
    const adm_ent_fuel_grade_typ * const ent_fuel_grade,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_object_existent_pending_transaction(
    const adm_ent_pending_transaction_typ * const ent_pending_transaction,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_object_existent_evaded_transaction(
    const adm_ent_evaded_transaction_typ * const ent_evaded_transaction,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_object_existent_transaction_policy(
    const adm_ent_transaction_policy_typ * const ent_transaction_policy,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_object_existent_paid_transaction(
    const adm_ent_paid_transaction_typ * const ent_paid_transaction,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);


/* Event Sender Prototypes */

void adm_send_event_delivery_fuel_unit_delivered(
    const void * const source_object,
    const adm_ent_delivery_typ * const ent_delivery,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_delivery_delivery_complete(
    const void * const source_object,
    const adm_ent_delivery_typ * const ent_delivery,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_delivery_delete_delivery(
    const void * const source_object,
    const adm_ent_delivery_typ * const ent_delivery,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_delivery_create_delivery(
    const adm_int_equipment_number_typ evd_pump_number,
    const adm_int_time_hour_typ evd_timestamp_hours,
    const adm_int_time_minute_typ evd_timestamp_minutes,
    const adm_int_time_second_typ evd_timestamp_seconds,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_pump_gun_removed(
    const void * const source_object,
    const adm_ent_pump_typ * const ent_pump,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_pump_gun_replaced(
    const void * const source_object,
    const adm_ent_pump_typ * const ent_pump,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_pump_fuel_level_low(
    const void * const source_object,
    const adm_ent_pump_typ * const ent_pump,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_pump_fuel_available(
    const void * const source_object,
    const adm_ent_pump_typ * const ent_pump,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_pump_pump_enabled(
    const void * const source_object,
    const adm_ent_pump_typ * const ent_pump,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_pump_trigger_depressed(
    const void * const source_object,
    const adm_ent_pump_typ * const ent_pump,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_pump_trigger_released(
    const void * const source_object,
    const adm_ent_pump_typ * const ent_pump,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_pump_customer_finished(
    const void * const source_object,
    const adm_ent_pump_typ * const ent_pump,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_tank_level_below_threshold(
    const void * const source_object,
    const adm_ent_tank_typ * const ent_tank,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_tank_level_above_threshold(
    const void * const source_object,
    const adm_ent_tank_typ * const ent_tank,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_tank_tanker_delivery(
    const void * const source_object,
    const adm_ent_tank_typ * const ent_tank,
    const adm_fxd_volume_typ evd_added_volume,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_tank_fuel_used(
    const void * const source_object,
    const adm_ent_tank_typ * const ent_tank,
    const adm_fxd_volume_typ evd_delivered_volume,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_transaction_payment_received(
    const void * const source_object,
    const adm_ent_transaction_typ * const ent_transaction,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_transaction_customer_absconds(
    const void * const source_object,
    const adm_ent_transaction_typ * const ent_transaction,
    const adm_str_text_typ * const evd_customer_details,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_transaction_create_transaction(
    const adm_int_equipment_number_typ evd_delivery_pump,
    const adm_fxd_money_typ evd_delivery_cost,
    const adm_int_time_hour_typ evd_delivery_time_hours,
    const adm_int_time_minute_typ evd_delivery_time_minutes,
    const adm_int_time_second_typ evd_delivery_time_seconds,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_transaction_close_transaction(
    const void * const source_object,
    const adm_ent_transaction_typ * const ent_transaction,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);


/* Dispatcher Prototypes */

void adm_dispatcher_delivery         (void);
void adm_dispatch_home_pool_delivery (void);

adm_pool_target_delivery_typ * adm_find_home_target_event_delivery (void);
adm_pool_target_delivery_typ * adm_find_away_target_event_delivery (void);

void adm_dispatch_state_action_delivery(
    adm_pool_target_delivery_typ * pool_target_delivery);

void adm_dispatcher_pump         (void);
void adm_dispatch_home_pool_pump (void);

adm_pool_target_pump_typ * adm_find_home_target_event_pump (void);
adm_pool_target_pump_typ * adm_find_away_target_event_pump (void);

void adm_dispatch_state_action_pump(
    adm_pool_target_pump_typ * pool_target_pump);

void adm_dispatcher_tank         (void);
void adm_dispatch_home_pool_tank (void);

adm_pool_target_tank_typ * adm_find_home_target_event_tank (void);
adm_pool_target_tank_typ * adm_find_away_target_event_tank (void);

void adm_dispatch_state_action_tank(
    adm_pool_target_tank_typ * pool_target_tank);

void adm_dispatcher_transaction         (void);
void adm_dispatch_home_pool_transaction (void);

adm_pool_target_transaction_typ * adm_find_home_target_event_transaction (void);
adm_pool_target_transaction_typ * adm_find_away_target_event_transaction (void);

void adm_dispatch_state_action_transaction(
    adm_pool_target_transaction_typ * pool_target_transaction);


/* State Action Prototypes */

void adm_state_action_delivery_creating_delivery(
    adm_ent_delivery_typ * const ent_delivery,
    const adm_dst_delivery_pump_number_typ * const dst_pump_number);

void adm_state_action_delivery_calculating_price_of_unconstrained_delivery(
    adm_ent_delivery_typ * const ent_delivery);

void adm_state_action_delivery_delivery_complete_state(
    adm_ent_delivery_typ * const ent_delivery);

void adm_state_action_delivery_delivery_cancelled(
    adm_ent_delivery_typ * const ent_delivery);

void adm_state_action_delivery_delivery_vanishes(
    adm_ent_delivery_typ * const ent_delivery);

void adm_state_action_pump_waiting_pump_enable(
    adm_ent_pump_typ * const ent_pump);

void adm_state_action_pump_fuel_unavailable(
    adm_ent_pump_typ * const ent_pump);

void adm_state_action_pump_fuel_delivery_complete(
    adm_ent_pump_typ * const ent_pump);

void adm_state_action_pump_ready_to_pump(
    adm_ent_pump_typ * const ent_pump);

void adm_state_action_pump_pumping_paused(
    adm_ent_pump_typ * const ent_pump);

void adm_state_action_pump_pumping(
    adm_ent_pump_typ * const ent_pump);

void adm_state_action_tank_checking_levels_after_tanker_delivery(
    adm_ent_tank_typ * const ent_tank,
    const adm_dst_tank_added_volume_typ * const dst_added_volume);

void adm_state_action_tank_checking_levels_after_pump_usage(
    adm_ent_tank_typ * const ent_tank,
    const adm_dst_tank_delivered_volume_typ * const dst_delivered_volume);

void adm_state_action_tank_updating_fuel_levels(
    adm_ent_tank_typ * const ent_tank,
    const adm_dst_tank_delivered_volume_typ * const dst_delivered_volume);

void adm_state_action_transaction_creating_pending_transaction(
    adm_ent_transaction_typ * const ent_transaction,
    const adm_dst_transaction_creation_data_typ * const dst_creation_data);

void adm_state_action_transaction_paid_state(
    adm_ent_transaction_typ * const ent_transaction);

void adm_state_action_transaction_evaded_state(
    adm_ent_transaction_typ * const ent_transaction,
    const adm_dst_transaction_customer_details_typ * const dst_customer_details);

void adm_state_action_transaction_transaction_vanishes(
    adm_ent_transaction_typ * const ent_transaction);


/* Identifier Prototypes */

void adm_check_identifiers_unique_delivery(
    adm_ent_delivery_typ * ent_source_delivery,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_check_identifiers_unique_pump(
    adm_ent_pump_typ * ent_source_pump,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_check_identifiers_unique_tank(
    adm_ent_tank_typ * ent_source_tank,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_check_identifiers_unique_transaction(
    adm_ent_transaction_typ * ent_source_transaction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_check_identifiers_unique_fuel_grade(
    adm_ent_fuel_grade_typ * ent_source_fuel_grade,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */