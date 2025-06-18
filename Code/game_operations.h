#pragma once

#include <ascii_engine/frame.h>
#include "display.h"
#include "tank.h"
#include "logic.h"

class game_operations
{
public:
	game_operations(frame* tank_view_display, frame* tank_damage_display);
	void run_tank_view();

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