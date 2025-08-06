#include "game_operations.h"
#include <ascii_engine/file_manager.h>
#include <ascii_engine/ascii_io.h>
#include <time.h>
#include <thread>
#include <chrono>


game_operations::game_operations(frame* tank_view_display, frame* tank_damage_display, frame* scenario_setup_display, frame* tank_fleet_display) : display_manager(tank_view_display, tank_damage_display, scenario_setup_display, tank_fleet_display)
{
	tank_templates = logic_manager.get_tank_templates();
}

void game_operations::run_tank_view()
{
	int input = ascii_io::undefined;
	int image = 1;
	unsigned int image_one_tank_name_index = 0;
	std::string image_one_side = "top";
	unsigned int image_two_tank_name_index = 1;
	std::string image_two_side = "top";
	display_manager.display_tank_view(tank_names[image_one_tank_name_index], image_one_side, tank_names[image_two_tank_name_index], image_two_side);
	bool refresh_display = false;
	while (input != ascii_io::q)
	{
		input = ascii_io::getchar();
		if (input == ascii_io::up)
		{
			refresh_display = true;
			if (image == 1)
			{
				if (image_one_tank_name_index > 0)
				{
					image_one_tank_name_index--;
				}
				else
				{
					image_one_tank_name_index = tank_names.size() - 1;
				}
			}
			else if (image == 2)
			{
				if (image_two_tank_name_index > 0)
				{
					image_two_tank_name_index--;
				}
				else
				{
					image_two_tank_name_index = tank_names.size() - 1;
				}
			}
		}
		else if (input == ascii_io::down)
		{
			refresh_display = true;
			if (image == 1)
			{
				if (image_one_tank_name_index < (tank_names.size() - 1))
				{
					image_one_tank_name_index++;
				}
				else
				{
					image_one_tank_name_index = 0;
				}
			}
			else if (image == 2)
			{
				if (image_two_tank_name_index < (tank_names.size() - 1))
				{
					image_two_tank_name_index++;
				}
				else
				{
					image_two_tank_name_index = 0;
				}
			}
		}
		else if (input == ascii_io::left)
		{
			image = 1;
		}
		else if (input == ascii_io::right)
		{
			image = 2;
		}
		else if (input == ascii_io::t)
		{
			refresh_display = true;
			if (image == 1)
			{
				image_one_side = "top";
			}
			else if (image == 2)
			{
				image_two_side = "top";
			}
		}
		else if (input == ascii_io::l)
		{
			refresh_display = true;
			if (image == 1)
			{
				image_one_side = "left";
			}
			else if (image == 2)
			{
				image_two_side = "left";
			}
		}
		else if (input == ascii_io::r)
		{
			refresh_display = true;
			if (image == 1)
			{
				image_one_side = "right";
			}
			else if (image == 2)
			{
				image_two_side = "right";
			}
		}
		else if (input == ascii_io::w)
		{
			display_manager.scroll_tank_image(image, "up", 10);
		}
		else if (input == ascii_io::s)
		{
			display_manager.scroll_tank_image(image, "down", 10);
		}
		else if (input == ascii_io::a)
		{
			display_manager.scroll_tank_image(image, "left", 3);
		}
		else if (input == ascii_io::d)
		{
			display_manager.scroll_tank_image(image, "right", 3);
		}
		else if (input == ascii_io::enter)
		{
			if (image == 1)
			{
				for (unsigned int i = 0; i < tank_templates.size(); i++)
				{
					if (tank_templates[i].get_name() == tank_names[image_one_tank_name_index])
					{
						display_manager.display_tank_stats(tank_templates[i]);
						refresh_display = true;
						ascii_io::wait_for_keystroke({ ascii_io::q, ascii_io::enter });
						break;
					}
				}
			}
			else if (image == 2)
			{
				for (unsigned int i = 0; i < tank_templates.size(); i++)
				{
					if (tank_templates[i].get_name() == tank_names[image_two_tank_name_index])
					{
						display_manager.display_tank_stats(tank_templates[i]);
						refresh_display = true;
						ascii_io::wait_for_keystroke({ ascii_io::q, ascii_io::enter });
						break;
					}
				}
			}
		}

		if (refresh_display)
		{
			display_manager.display_tank_view(tank_names[image_one_tank_name_index], image_one_side, tank_names[image_two_tank_name_index], image_two_side);
			refresh_display = false;
		}
	}

	ascii_io::zoom_to_level(0);
	std::this_thread::sleep_for(std::chrono::milliseconds(300));
}

void game_operations::run_new_game_setup()
{
	unsigned int number_of_players = 0;
	int budget = 0;
	bool faction_mixing_allowed = false;
	display_manager.display_scenario_setup(number_of_players, budget, faction_mixing_allowed);
	for (unsigned int i = 0; i < number_of_players; i++)
	{
		std::string player_name = "";
		std::vector<tank> tank_fleet;
		std::string faction = "none";
		display_manager.display_tank_fleet_setup(budget, faction_mixing_allowed, tank_templates, player_name, faction, tank_fleet);
	}
}