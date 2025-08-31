#pragma once

#include <ascii_engine/frame.h>
#include "display.h"
#include "tank.h"
#include "logic.h"

class game_operations
{
public:
	game_operations(frame* tank_view_display, frame* tank_damage_display, frame* scenario_setup_display, frame* tank_fleet_display, frame* board_display);
	void run_tank_view();
	void run_new_game_setup();
	void run_test_board();

private:
	display display_manager;
	logic logic_manager;
	std::vector<tank> tank_templates;
	const std::vector<std::string> tank_names =
	{
		"Aeneas",
		"Horatius",
		"Liberator",
		"Lupis",
		"Remus",
		"Romulus",
		"Spartius",
		"Viper",
		"Wolverine"
	};
};