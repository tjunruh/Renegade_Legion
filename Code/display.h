#pragma once

#include <string>
#include <vector>
#include <ascii_engine/frame.h>
#include <ascii_engine/label.h>
#include <ascii_engine/text_box.h>
#include <ascii_engine/menu.h>
#include <ascii_engine/ascii_board.h>
#include <ascii_engine/format_tools.h>
#include "tank.h"

class display
{
public:
	display(frame* tank_view_display, frame* tank_damage_display, frame* scenario_setup_display, frame* tank_fleet_setup_display);
	void display_tank_view(const std::string& tank_name, const std::string& tank_side);
	void display_tank_view(const std::string& tank_one_name, const std::string& tank_one_side, const std::string& tank_two_name, const std::string& tank_two_side);
	void scroll_tank_image(int image_number, const std::string& direction, unsigned int amount);
	void display_tank_stats(tank& tank_data);
	void display_scenario_setup(unsigned int& number_of_players, int& budget, bool& faction_mixing_allowed);
	void display_tank_fleet_setup(int budget, bool faction_mixing_allowed, std::vector<tank>& tank_templates, std::string& player_name, std::string& faction, std::vector<tank>& tank_fleet);

private:
	board_configuration build_damage_config(const std::string& name_id, const std::string& value, char ignore_character, const std::vector<format_tools::index_format>& colors);
	void setup_tank_view();
	void setup_tank_stats();
	void setup_scenario_setup();
	void setup_tank_fleet_setup();
	bool is_number(const std::string& number_string);

	void create_tank_views();
	struct tank_view
	{
		std::string name = "";
		std::string top_view = "";
		std::string right_view = "";
		std::string left_view = "";
	};

	frame* tank_view_frame;
	label tank_image_one;
	label tank_image_two;

	frame* tank_damage_frame;
	ascii_board tank_stats;

	frame* scenario_setup_frame;
	label player_number_prompt;
	menu player_number_input;
	label budget_prompt;
	menu budget_input;
	label faction_mixing_prompt;
	menu faction_mixing_input;
	label scenario_setup_spacer;
	label finalize_scenario_setup;
	label scenario_setup_decal;

	frame* tank_fleet_setup_frame;
	label player_name_prompt;
	text_box player_name_input;
	label faction_prompt;
	menu faction_input;
	label tank_fleet_setup_decal;
	label tank_selection_prompt;
	menu tank_selection_input;
	label owned_tank_prompt;
	menu owned_tank_input;
	label budget_data;
	label fleet_cost_data;
	label tank_fleet_setup_spacer;
	label finalize_fleet_setup;

	std::vector<tank_view> tank_views;
};