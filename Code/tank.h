#pragma once

#include <string>
#include "weapons.h"

#define MAX_SMLM_MISSLE_COUNT 10
#define MAX_TVLG_MISSLE_COUNT 12
#define MAX_SHIELD_FACTOR 10
#define MAX_WEAPONS 8
#define MAX_DIGGING_CHARGE_COUNT 4
#define MAX_SMOKE_CHARGE_COUNT 4
#define MAX_TURNS 11
#define MAX_ARMOR_THICKNESS 10
#define ARMOR_COLUMNS_PER_SIDE 10
#define ARMOR_ROWS_PER_SIDE 10
#define ROWS_IN_INTERNALS 12
#define COLUMNS_IN_INTERNALS 66
#define STERN_INTERNAL_COLUMN_OFFSET 10
#define LEFT_INTERNAL_COLUMN_OFFSET 22
#define FRONT_INTERNAL_COLUMN_OFFSET 34
#define RIGHT_INTERNAL_COLUMN_OFFSET 46
#define BOTTOM_INTERNAL_COLUMN_OFFSET 56

class tank
{
public:
	struct damage_record
	{
		int turret_armor[ARMOR_ROWS_PER_SIDE][ARMOR_COLUMNS_PER_SIDE] = { 0 };
		int stern_armor[ARMOR_ROWS_PER_SIDE][ARMOR_COLUMNS_PER_SIDE] = { 0 };
		int left_armor[ARMOR_ROWS_PER_SIDE][ARMOR_COLUMNS_PER_SIDE] = { 0 };
		int front_armor[ARMOR_ROWS_PER_SIDE][ARMOR_COLUMNS_PER_SIDE] = { 0 };
		int right_armor[ARMOR_ROWS_PER_SIDE][ARMOR_COLUMNS_PER_SIDE] = { 0 };
		int bottom_armor[ARMOR_ROWS_PER_SIDE][ARMOR_COLUMNS_PER_SIDE] = { 0 };
		int internal[ROWS_IN_INTERNALS][COLUMNS_IN_INTERNALS] = { 0 };
	};

	struct velocity_record_unit
	{
		int velocity = -1;
		int turn = -1;
	};

	struct weapon_entry
	{
		std::string name = "";
		std::string location = "";
		std::string damage = "";
		std::string range = "";
	};

	void set_name(const std::string& name);
	int set_number(int number);
	int set_row(int row);
	int set_column(int column);
	int set_smlm_missle_count(int count);
	int set_tvlg_missle_count(int count);
	int set_stern_shield_factor(int shield_factor);
	int set_left_shield_factor(int shield_factor);
	int set_front_shield_factor(int shield_factor);
	int set_right_shield_factor(int shield_factor);
	int set_bottom_shield_factor(int shield_factor);
	int add_weapon(const std::string& name, const std::string& location, const std::string& damage, const std::string& range);
	void set_fire_modifiers(const std::string& fire_modifiers);
	int set_digging_charge_count(int count);
	int set_smoke_charge_count(int count);
	int set_velocity_record(int velocity, int turn);
	int set_max_thrust(int max_thrust);
	int set_turret_armor_thickness(int thickness);
	int set_stern_armor_thickness(int thickness);
	int set_left_armor_thickness(int thickness);
	int set_front_armor_thickness(int thickness);
	int set_right_armor_thickness(int thickness);
	int set_bottom_armor_thickness(int thickness);
	void set_faction(const std::string& faction);
	void set_cost(float cost);
	int apply_damage(const std::string& side, int column, const std::vector<weapons::damage_coordinate>& damage);
	std::string get_name();
	int get_number();
	int get_row();
	int get_column();
	int get_smlm_missle_count();
	int get_tvlg_missle_count();
	int get_stern_shield_factor();
	int get_left_shield_factor();
	int get_front_shield_factor();
	int get_right_shield_factor();
	int get_bottom_shield_factor();
	std::vector<weapon_entry> get_weapons();
	std::string get_fire_modifiers();
	int get_digging_charge_count();
	int get_smoke_charge_count();
	int get_max_thrust();
	int get_turret_armor_thickness();
	int get_stern_armor_thickness();
	int get_left_armor_thickness();
	int get_front_armor_thickness();
	int get_right_armor_thickness();
	int get_bottom_armor_thickness();
	std::string get_faction();
	float get_cost();
	damage_record get_damage_record();
	std::vector<velocity_record_unit> get_velocity_record();

private:
	void apply_turret_damage(int column, const std::vector<weapons::damage_coordinate>& damage);
	void apply_stern_damage(int column, const std::vector<weapons::damage_coordinate>& damage);
	void apply_left_damage(int column, const std::vector<weapons::damage_coordinate>& damage);
	void apply_front_damage(int column, const std::vector<weapons::damage_coordinate>& damage);
	void apply_right_damage(int column, const std::vector<weapons::damage_coordinate>& damage);
	void apply_bottom_damage(int column, const std::vector<weapons::damage_coordinate>& damage);

	std::string _name = "";
	int _number = -1;
	int _row = 0;
	int _column = 0;
	int smlm_missle_count = 0;
	int tvlg_missle_count = 0;
	int stern_shield_factor = 0;
	int left_shield_factor = 0;
	int front_shield_factor = 0;
	int right_shield_factor = 0;
	int bottom_shield_factor = 0;
	std::vector<weapon_entry> weapon_entries;
	int digging_charge_count = 0;
	std::string _fire_modifiers = "";
	int smoke_charge_count = 0;
	int _max_thrust = 0;
	int turret_armor_thickness = 0;
	int stern_armor_thickness = 0;
	int left_armor_thickness = 0;
	int front_armor_thickness = 0;
	int right_armor_thickness = 0;
	int bottom_armor_thickness = 0;
	std::string _faction = "";
	float _cost = 0.0;
	damage_record total_damage;
	std::vector<velocity_record_unit> velocity_record;

	const std::vector<std::string> valid_side_names = { "turret", "stern", "left", "front", "right", "bottom" };
};