#include "display.h"
#include <ascii_engine/ascii_io.h>
#include <ascii_engine/file_manager.h>
#include <ascii_engine/format_tools.h>
#include "damage_code.h"
#include <time.h>
#include <thread>
#include <chrono>

display::display(frame* tank_view_display, frame* tank_damage_display, frame* scenario_setup_display, frame* tank_fleet_setup_display) :
	tank_image_one(tank_view_display),
	tank_image_two(tank_view_display),

	tank_stats(tank_damage_display, "board_configs/damage_record_template_config.txt", "default"),

	player_number_prompt(scenario_setup_display),
	player_number_input(scenario_setup_display, "merge", 3),
	budget_prompt(scenario_setup_display, "merge"),
	budget_input(scenario_setup_display, "merge", 3),
	faction_mixing_prompt(scenario_setup_display, "merge"),
	faction_mixing_input(scenario_setup_display, "merge", 2),
	scenario_setup_spacer(scenario_setup_display, "merge", -35),
	finalize_scenario_setup(scenario_setup_display, "merge", 1),
	scenario_setup_decal(scenario_setup_display, "none", -2),

	player_name_prompt(tank_fleet_setup_display, "none", 1),
	player_name_input(tank_fleet_setup_display, "merge", 3),
	faction_prompt(tank_fleet_setup_display, "merge", 1),
	faction_input(tank_fleet_setup_display, "merge", 3),
	tank_fleet_setup_decal(tank_fleet_setup_display, "merge", -20),
	tank_selection_prompt(tank_fleet_setup_display, "none", 1),
	tank_selection_input(tank_fleet_setup_display, "merge", 9),
	owned_tank_prompt(tank_fleet_setup_display, "merge", 1),
	owned_tank_input(tank_fleet_setup_display, "merge", 9),
	budget_data(tank_fleet_setup_display, "merge", 1),
	fleet_cost_data(tank_fleet_setup_display, "merge", 1),
	tank_fleet_setup_spacer(tank_fleet_setup_display, "merge", -37),
	finalize_fleet_setup(tank_fleet_setup_display, "merge", 1)
{
	tank_view_frame = tank_view_display;
	tank_damage_frame = tank_damage_display;
	scenario_setup_frame = scenario_setup_display;
	tank_fleet_setup_frame = tank_fleet_setup_display;

	setup_tank_view();
	setup_tank_stats();
	setup_scenario_setup();
	setup_tank_fleet_setup();
}

void display::display_tank_view(const std::string& tank_name, const std::string& tank_side)
{
	ascii_io::zoom_to_level(-7);
	std::this_thread::sleep_for(std::chrono::milliseconds(300));
	for (unsigned int i = 0; i < tank_views.size(); i++)
	{
		if (tank_views[i].name == tank_name)
		{
			if (tank_side == "top")
			{
				tank_image_one.set_output(tank_views[i].top_view);
			}
			else if (tank_side == "left")
			{
				tank_image_one.set_output(tank_views[i].left_view);
			}
			else if (tank_side == "right")
			{
				tank_image_one.set_output(tank_views[i].right_view);
			}

			break;
		}
	}

	tank_view_frame->display();
}

void display::display_tank_view(const std::string& tank_one_name, const std::string& tank_one_side, const std::string& tank_two_name, const std::string& tank_two_side)
{
	ascii_io::zoom_to_level(-7);
	std::this_thread::sleep_for(std::chrono::milliseconds(300));
	for (unsigned int i = 0; i < tank_views.size(); i++)
	{
		if (tank_views[i].name == tank_one_name)
		{
			if (tank_one_side == "top")
			{
				tank_image_one.set_output(tank_views[i].top_view);
			}
			else if (tank_one_side == "left")
			{
				tank_image_one.set_output(tank_views[i].left_view);
			}
			else if (tank_one_side == "right")
			{
				tank_image_one.set_output(tank_views[i].right_view);
			}

			break;
		}
	}

	for (unsigned int i = 0; i < tank_views.size(); i++)
	{
		if (tank_views[i].name == tank_two_name)
		{
			if (tank_two_side == "top")
			{
				tank_image_two.set_output(tank_views[i].top_view);
			}
			else if (tank_two_side == "left")
			{
				tank_image_two.set_output(tank_views[i].left_view);
			}
			else if (tank_two_side == "right")
			{
				tank_image_two.set_output(tank_views[i].right_view);
			}

			break;
		}
	}
	
	tank_view_frame->display();
}

void display::display_tank_stats(tank& tank_data)
{
	ascii_io::zoom_to_level(-3);
	std::this_thread::sleep_for(std::chrono::milliseconds(300));
	tank_stats.clear_all();
	tank_stats.set_tile(22, 0, tank_data.get_name());
	tank_stats.set_tile(22, 1, std::to_string(tank_data.get_number()));
	tank_stats.set_tile(23, 0, std::to_string(tank_data.get_stern_shield_factor()));
	tank_stats.set_tile(23, 1, std::to_string(tank_data.get_left_shield_factor()));
	tank_stats.set_tile(23, 2, std::to_string(tank_data.get_front_shield_factor()));
	tank_stats.set_tile(23, 3, std::to_string(tank_data.get_right_shield_factor()));
	tank_stats.set_tile(23, 4, std::to_string(tank_data.get_bottom_shield_factor()));

	int smlm_missle_count = tank_data.get_smlm_missle_count();
	for (int i = 0; i < smlm_missle_count; i++)
	{
		tank_stats.set_tile(24, i, " X ");
	}

	int tvlg_missle_count = tank_data.get_tvlg_missle_count();
	for (int i = 0; i < tvlg_missle_count; i++)
	{
		tank_stats.set_tile(25, i, " X ");
	}

	std::vector<tank::weapon_entry> weapons = tank_data.get_weapons();
	for (unsigned int i = 0; i < weapons.size(); i++)
	{
		tank_stats.set_tile(27, i * 4, weapons[i].name);
		tank_stats.set_tile(27, i * 4 + 1, weapons[i].location);
		tank_stats.set_tile(27, i * 4 + 2, weapons[i].damage);
		tank_stats.set_tile(27, i * 4 + 3, weapons[i].range);
	}

	tank_stats.set_tile(26, 12, format_tools::get_spacing(62, ' ') + format_tools::fill_line(std::to_string(tank_data.get_max_thrust()), 31, "center"));

	tank_stats.set_tile(28, 0, tank_data.get_fire_modifiers());
	
	int digging_charge_count = tank_data.get_digging_charge_count();
	for (int i = 0; i < digging_charge_count; i++)
	{
		tank_stats.set_tile(28, i + 1, " X ");
	}

	int smoke_charge_count = tank_data.get_smoke_charge_count();
	for (int i = 0; i < smoke_charge_count; i++)
	{
		tank_stats.set_tile(28, i + 5, " X ");
	}

	int turret_armor_thickness = tank_data.get_turret_armor_thickness();
	for (int i = 0; i < MAX_ARMOR_THICKNESS - turret_armor_thickness; i++)
	{
		for (int j = 0; j < ARMOR_COLUMNS_PER_SIDE; j++)
		{
			tank_stats.activate_configuration("missing", i, j);
		}
	}

	int stern_armor_thickness = tank_data.get_stern_armor_thickness();
	for (int i = 0; i < MAX_ARMOR_THICKNESS - stern_armor_thickness; i++)
	{
		for (int j = 0; j < ARMOR_COLUMNS_PER_SIDE; j++)
		{
			tank_stats.activate_configuration("missing", i, j + STERN_INTERNAL_COLUMN_OFFSET);
		}
	}

	int left_armor_thickness = tank_data.get_left_armor_thickness();
	for (int i = 0; i < MAX_ARMOR_THICKNESS - left_armor_thickness; i++)
	{
		for (int j = 0; j < ARMOR_COLUMNS_PER_SIDE; j++)
		{
			tank_stats.activate_configuration("missing", i, j + LEFT_INTERNAL_COLUMN_OFFSET);
		}
	}

	int front_armor_thickness = tank_data.get_front_armor_thickness();
	for (int i = 0; i < MAX_ARMOR_THICKNESS - front_armor_thickness; i++)
	{
		for (int j = 0; j < ARMOR_COLUMNS_PER_SIDE; j++)
		{
			tank_stats.activate_configuration("missing", i, j + FRONT_INTERNAL_COLUMN_OFFSET);
		}
	}

	int right_armor_thickness = tank_data.get_right_armor_thickness();
	for (int i = 0; i < MAX_ARMOR_THICKNESS - right_armor_thickness; i++)
	{
		for (int j = 0; j < ARMOR_COLUMNS_PER_SIDE; j++)
		{
			tank_stats.activate_configuration("missing", i, j + RIGHT_INTERNAL_COLUMN_OFFSET);
		}
	}

	int bottom_armor_thickness = tank_data.get_bottom_armor_thickness();
	for (int i = 0; i < MAX_ARMOR_THICKNESS - bottom_armor_thickness; i++)
	{
		for (int j = 0; j < ARMOR_COLUMNS_PER_SIDE; j++)
		{
			tank_stats.activate_configuration("missing", i, j + BOTTOM_INTERNAL_COLUMN_OFFSET);
		}
	}

	tank::damage_record damage = tank_data.get_damage_record();
	for (int i = 0; i < ARMOR_ROWS_PER_SIDE; i++)
	{
		for (int j = 0; j < ARMOR_COLUMNS_PER_SIDE; j++)
		{
			if (damage.turret_armor[i][j] == damaged)
			{
				tank_stats.activate_configuration("damaged", i, j);
			}
		}
	}

	for (int i = 0; i < ARMOR_ROWS_PER_SIDE; i++)
	{
		for (int j = 0; j < ARMOR_COLUMNS_PER_SIDE; j++)
		{
			if (damage.stern_armor[i][j] == damaged)
			{
				tank_stats.activate_configuration("damaged", i, j + STERN_INTERNAL_COLUMN_OFFSET);
			}
		}
	}

	for (int i = 0; i < ARMOR_ROWS_PER_SIDE; i++)
	{
		for (int j = 0; j < ARMOR_COLUMNS_PER_SIDE; j++)
		{
			if (damage.left_armor[i][j] == damaged)
			{
				tank_stats.activate_configuration("damaged", i, j + LEFT_INTERNAL_COLUMN_OFFSET);
			}
		}
	}

	for (int i = 0; i < ARMOR_ROWS_PER_SIDE; i++)
	{
		for (int j = 0; j < ARMOR_COLUMNS_PER_SIDE; j++)
		{
			if (damage.front_armor[i][j] == damaged)
			{
				tank_stats.activate_configuration("damaged", i, j + FRONT_INTERNAL_COLUMN_OFFSET);
			}
		}
	}

	for (int i = 0; i < ARMOR_ROWS_PER_SIDE; i++)
	{
		for (int j = 0; j < ARMOR_COLUMNS_PER_SIDE; j++)
		{
			if (damage.right_armor[i][j] == damaged)
			{
				tank_stats.activate_configuration("damaged", i, j + RIGHT_INTERNAL_COLUMN_OFFSET);
			}
		}
	}

	for (int i = 0; i < ARMOR_ROWS_PER_SIDE; i++)
	{
		for (int j = 0; j < ARMOR_COLUMNS_PER_SIDE; j++)
		{
			if (damage.bottom_armor[i][j] == damaged)
			{
				tank_stats.activate_configuration("damaged", i, j + BOTTOM_INTERNAL_COLUMN_OFFSET);
			}
		}
	}

	for (int i = 0; i < ROWS_IN_INTERNALS; i++)
	{
		for (int j = 0; j < COLUMNS_IN_INTERNALS; j++)
		{
			if (damage.internal[i][j] == damaged)
			{
				tank_stats.activate_configuration("damaged", i + ARMOR_ROWS_PER_SIDE, j);
			}
		}
	}

	tank_stats.build();

	tank_damage_frame->display();
}

void display::display_scenario_setup(unsigned int& number_of_players, int& budget, bool& faction_mixing_allowed)
{
	ascii_io::zoom_to_level(-1);
	int selection = -1;
	std::string raw_number_of_players = "2";
	std::string raw_budget = "500000";
	std::string raw_faction_mixing_allowed = "Yes";
	int key_stroke = ascii_io::undefined;
	scenario_setup_frame->display();
	do
	{
		selection = scenario_setup_frame->get_selection();
		if (selection == player_number_input)
		{
			player_number_input.get_selection(raw_number_of_players, key_stroke);
		}
		else if (selection == budget_input)
		{
			budget_input.get_selection(raw_budget, key_stroke);
		}
		else if (selection == faction_mixing_input)
		{
			faction_mixing_input.get_selection(raw_faction_mixing_allowed, key_stroke);
		}

	} while (selection != finalize_scenario_setup);

	number_of_players = stoi(raw_number_of_players);
	budget = stoi(raw_budget);
	if (raw_faction_mixing_allowed == "Yes")
	{
		faction_mixing_allowed = true;
	}
	else if (raw_faction_mixing_allowed == "No")
	{
		faction_mixing_allowed = false;
	}
}

void display::display_tank_fleet_setup(int budget, bool faction_mixing_allowed, std::vector<tank>& tank_templates, std::string& player_name, std::string& faction, std::vector<tank>& tank_fleet)
{
	ascii_io::zoom_to_level(0);
	faction = "Renegade";
	std::string tog_symbol = "";
	std::string renegade_symbol = "";
	std::string mercenary_symbol = "";
	file_manager::read_file("text_images/Renegade_Symbol.txt", renegade_symbol);
	file_manager::read_file("text_images/TOG_Symbol.txt", tog_symbol);
	file_manager::read_file("text_images/Mercenary_Symbol.txt", mercenary_symbol);
	tank_fleet_setup_decal.set_output(renegade_symbol);
	ascii_io::zoom_to_level(-1);
	fleet_cost_data.set_output("0");
	faction_input.remove_all_items();
	faction_input.append_item("Renegade");
	faction_input.append_item("TOG");
	if (faction_mixing_allowed)
	{
		faction_input.append_item("Mercenary");
	}
	faction_input.set_cursor_item(0);
	faction_input.build();

	budget_data.set_output("Available budget: " + std::to_string(budget));

	owned_tank_input.remove_all_items();
	tank_selection_input.remove_all_items();

	for (unsigned int i = 0; i < tank_templates.size(); i++)
	{
		if (tank_templates[i].get_faction() == faction)
		{
			tank_selection_input.append_item(tank_templates[i].get_name());
			tank_selection_input.set_item_label(tank_templates[i].get_name(), std::to_string(tank_templates[i].get_cost()));
			tank_selection_input.build();
		}
	}

	int selection = -1;
	bool valid_inputs = false;
	int key_stroke = ascii_io::undefined;

	while (!valid_inputs)
	{
		do
		{
			selection = tank_fleet_setup_frame->get_selection();
			if (selection == player_name_input)
			{
				player_name_input.write();
				ascii_io::hide_cursor();
				player_name = player_name_input.get_text();
			}
			else if (selection == faction_input)
			{
				std::string previous_faction = faction;
				faction_input.get_selection(faction, key_stroke);
				if (faction != previous_faction)
				{
					tank_selection_input.remove_all_items();
					if (faction == "Mercenary")
					{
						for (unsigned int i = 0; i < tank_templates.size(); i++)
						{
							tank_selection_input.append_item(tank_templates[i].get_name());
							tank_selection_input.set_item_label(tank_templates[i].get_name(), std::to_string(tank_templates[i].get_cost()));
						}

						tank_fleet_setup_decal.set_output(mercenary_symbol);
					}
					else
					{
						for (unsigned int i = 0; i < tank_templates.size(); i++)
						{
							if (tank_templates[i].get_faction() == faction)
							{
								tank_selection_input.append_item(tank_templates[i].get_name());
								tank_selection_input.set_item_label(tank_templates[i].get_name(), std::to_string(tank_templates[i].get_cost()));
							}
						}
						owned_tank_input.remove_all_items();
						owned_tank_input.build();
						fleet_cost_data.set_output("0");

						if (faction == "Renegade")
						{
							tank_fleet_setup_decal.set_output(renegade_symbol);
						}
						else if (faction == "TOG")
						{
							tank_fleet_setup_decal.set_output(tog_symbol);
						}
					}
					tank_selection_input.build();
				}
			}
			else if (selection == tank_selection_input)
			{
				std::string tank_selection = "";
				tank_selection_input.get_selection(tank_selection, key_stroke);
				if (key_stroke == ascii_io::enter)
				{
					for (unsigned int i = 0; i < tank_templates.size(); i++)
					{
						if (tank_templates[i].get_name() == tank_selection)
						{
							std::string budget_string = fleet_cost_data.get_output();
							int fleet_cost = stoi(budget_string) + tank_templates[i].get_cost();
							if (fleet_cost < budget)
							{
								fleet_cost_data.set_output(std::to_string(fleet_cost));
								int status = owned_tank_input.append_item(tank_templates[i].get_name());
								owned_tank_input.set_item_label(tank_templates[i].get_name(), std::to_string(tank_templates[i].get_cost()));
								owned_tank_input.build();
							}
						}
					}
				}
				else if (key_stroke == ascii_io::v)
				{
					display_tank_view(tank_selection, "top");
					ascii_io::getchar();
					ascii_io::zoom_to_level(-1);
				}
				else if (key_stroke == ascii_io::s)
				{
					for (unsigned int i = 0; i < tank_templates.size(); i++)
					{
						if (tank_templates[i].get_name() == tank_selection)
						{
							display_tank_stats(tank_templates[i]);
							ascii_io::getchar();
							ascii_io::zoom_to_level(-1);
						}
					}
				}
			}
			else if (selection == owned_tank_input)
			{
				std::string tank_selection = "";
				owned_tank_input.get_selection(tank_selection, key_stroke);
				if (key_stroke == ascii_io::DEL)
				{
					owned_tank_input.remove_item(tank_selection);
					owned_tank_input.build();
					for (unsigned int i = 0; i < tank_templates.size(); i++)
					{
						if (tank_templates[i].get_name() == tank_selection)
						{
							std::string budget = fleet_cost_data.get_output();
							fleet_cost_data.set_output(std::to_string(stoi(budget) - tank_templates[i].get_cost()));
						}
					}
				}
				else if (key_stroke == ascii_io::v)
				{
					display_tank_view(tank_selection, "top");
					ascii_io::getchar();
					ascii_io::zoom_to_level(-1);
				}
				else if (key_stroke == ascii_io::s)
				{
					for (unsigned int i = 0; i < tank_templates.size(); i++)
					{
						if (tank_templates[i].get_name() == tank_selection)
						{
							display_tank_stats(tank_templates[i]);
							ascii_io::getchar();
							ascii_io::zoom_to_level(-1);
						}
					}
				}
			}
			else if (selection == finalize_fleet_setup)
			{
				valid_inputs = true;
			}

		} while (selection != finalize_fleet_setup);
	}

}

board_configuration display::build_damage_config(const std::string& name_id, const std::string& value, char ignore_character, const std::vector<format_tools::index_format>& colors)
{
	tile_configuration tile_config;
	tile_config.value = value;
	tile_config.ignore_character = ignore_character;
	tile_config.colors = colors;
	tile_config.column = -1;
	board_configuration board_config;
	board_config.name_id = name_id;
	for (unsigned int i = 0; i < 22; i++)
	{
		tile_config.row = i;
		board_config.tile_configurations.push_back(tile_config);
	}

	return board_config;
}

void display::create_tank_views()
{
	tank_view view;
	view.name = "Aeneas";
	file_manager::read_file("text_images/tank_images/Aeneas/Aeneas_top_view.txt", view.top_view);
	file_manager::read_file("text_images/tank_images/Aeneas/Aeneas_left_view.txt", view.left_view);
	file_manager::read_file("text_images/tank_images/Aeneas/Aeneas_right_view.txt", view.right_view);

	tank_views.push_back(view);

	view.name = "Horatius";
	file_manager::read_file("text_images/tank_images/Horatius/Horatius_top_view.txt", view.top_view);
	file_manager::read_file("text_images/tank_images/Horatius/Horatius_right_view.txt", view.right_view);
	view.left_view = "";
	tank_views.push_back(view);

	view.name = "Liberator";
	file_manager::read_file("text_images/tank_images/Liberator/Liberator_top_view.txt", view.top_view);
	file_manager::read_file("text_images/tank_images/Liberator/Liberator_left_view.txt", view.left_view);
	file_manager::read_file("text_images/tank_images/Liberator/Liberator_right_view.txt", view.right_view);
	tank_views.push_back(view);

	view.name = "Lupis";
	file_manager::read_file("text_images/tank_images/Lupis/Lupis_top_view.txt", view.top_view);
	file_manager::read_file("text_images/tank_images/Lupis/Lupis_left_view.txt", view.left_view);
	file_manager::read_file("text_images/tank_images/Lupis/Lupis_right_view.txt", view.right_view);
	tank_views.push_back(view);

	view.name = "Remus";
	file_manager::read_file("text_images/tank_images/Remus/Remus_top_view.txt", view.top_view);
	file_manager::read_file("text_images/tank_images/Remus/Remus_left_view.txt", view.left_view);
	file_manager::read_file("text_images/tank_images/Remus/Remus_right_view.txt", view.right_view);
	tank_views.push_back(view);

	view.name = "Romulus";
	file_manager::read_file("text_images/tank_images/Romulus/Romulus_top_view.txt", view.top_view);
	file_manager::read_file("text_images/tank_images/Romulus/Romulus_right_view.txt", view.right_view);
	view.left_view = "";
	tank_views.push_back(view);

	view.name = "Spartius";
	file_manager::read_file("text_images/tank_images/Spartius/Spartius_top_view.txt", view.top_view);
	file_manager::read_file("text_images/tank_images/Spartius/Spartius_left_view.txt", view.left_view);
	file_manager::read_file("text_images/tank_images/Spartius/Spartius_right_view.txt", view.right_view);
	tank_views.push_back(view);

	view.name = "Viper";
	file_manager::read_file("text_images/tank_images/Viper/Viper_top_view.txt", view.top_view);
	file_manager::read_file("text_images/tank_images/Viper/Viper_left_view.txt", view.left_view);
	file_manager::read_file("text_images/tank_images/Viper/Viper_right_view.txt", view.right_view);
	tank_views.push_back(view);

	view.name = "Wolverine";
	file_manager::read_file("text_images/tank_images/Wolverine/Wolverine_top_view.txt", view.top_view);
	file_manager::read_file("text_images/tank_images/Wolverine/Wolverine_left_view.txt", view.left_view);
	file_manager::read_file("text_images/tank_images/Wolverine/Wolverine_right_view.txt", view.right_view);
	tank_views.push_back(view);
}

void display::setup_tank_view()
{
	tank_image_one.set_alignment("center block");
	tank_image_one.enable_word_wrap(false);
	tank_image_two.set_alignment("center block");
	tank_image_two.enable_word_wrap(false);

	create_tank_views();
}

void display::setup_tank_stats()
{
	tank_damage_frame->enable_dec(true);
	tank_damage_frame->enable_color(true);
	tank_stats.set_alignment("center block");

	std::vector<format_tools::index_format> colors;
	format_tools::index_format color;
	color.index = 0;
	color.format.background_format = format_tools::red;
	colors.push_back(color);

	tank_stats.add_configuration(build_damage_config("damaged", "   ", '*', colors));
	color.format.background_format = format_tools::white;
	colors.clear();
	colors.push_back(color);
	tank_stats.add_configuration(build_damage_config("missing", "   ", '*', colors));
}

void display::setup_scenario_setup()
{
	player_number_prompt.set_spacing(1, 0, 10, 5);
	player_number_prompt.set_alignment("center");
	player_number_prompt.set_output("Enter number of players to play:");

	player_number_input.set_spacing(0, 0, 10, 5);
	player_number_input.add_border(true);
	player_number_input.append_item("2");
	player_number_input.append_item("3");
	player_number_input.append_item("4");
	player_number_input.build();

	budget_prompt.set_spacing(5, 0, 10, 5);
	budget_prompt.set_alignment("center");
	budget_prompt.set_output("Select budget:");

	budget_input.set_spacing(0, 0, 10, 5);
	budget_input.add_border(true);
	budget_input.set_alignment("center block");
	budget_input.append_item("500000");
	budget_input.append_item("1000000");
	budget_input.append_item("5000000");
	budget_input.append_item("10000000");
	budget_input.build();

	faction_mixing_prompt.set_spacing(5, 0, 10, 5);
	faction_mixing_prompt.set_alignment("center");
	faction_mixing_prompt.set_output("Mercenaries allowed:");

	faction_mixing_input.set_spacing(0, 0, 10, 5);
	faction_mixing_input.set_alignment("center block");
	faction_mixing_input.add_border(true);
	faction_mixing_input.append_item("Yes");
	faction_mixing_input.append_item("No");
	faction_mixing_input.build();

	finalize_scenario_setup.set_spacing(2, 0, 10, 5);
	finalize_scenario_setup.set_alignment("center");
	finalize_scenario_setup.set_output("Finalize");
	finalize_scenario_setup.add_border(true);
	finalize_scenario_setup.selectable();

	scenario_setup_decal.set_spacing(1, 0, 5, 10);
	scenario_setup_decal.enable_word_wrap(false);
	scenario_setup_decal.set_alignment("center block");
	std::string renegade_solider = "";
	file_manager::read_file("text_images/Renegade_Solider.txt", renegade_solider);
	scenario_setup_decal.set_output(renegade_solider);
}

void display::setup_tank_fleet_setup()
{
	player_name_prompt.set_alignment("center");
	player_name_prompt.set_spacing(1, 0, 5, 10);
	player_name_prompt.set_output("Enter your name:");

	player_name_input.set_spacing(0, 0, 5, 10);
	player_name_input.add_border(true);

	faction_prompt.set_spacing(2, 0, 5, 10);
	faction_prompt.set_alignment("center");
	faction_prompt.set_output("Choose a faction:");

	faction_input.set_spacing(0, 0, 5, 10);
	faction_input.add_border(true);

	tank_fleet_setup_decal.set_spacing(2, 0, 5, 10);
	tank_fleet_setup_decal.enable_word_wrap(false);
	tank_fleet_setup_decal.set_alignment("center block");

	tank_selection_prompt.set_spacing(1, 0, 5, 10);
	tank_selection_prompt.set_alignment("center");
	tank_selection_prompt.set_output("Choose tanks for your fleet:");

	tank_selection_input.set_spacing(0, 0, 5, 10);
	tank_selection_input.add_border(true);
	tank_selection_input.set_controls({ ascii_io::enter, ascii_io::v, ascii_io::s }, ascii_io::up, ascii_io::down, ascii_io::q);

	owned_tank_prompt.set_spacing(2, 0, 5, 10);
	owned_tank_prompt.set_alignment("center");
	owned_tank_prompt.set_output("Selected tanks:");

	owned_tank_input.set_spacing(0, 0, 5, 10);
	owned_tank_input.add_border(true);
	owned_tank_input.set_controls({ ascii_io::DEL, ascii_io::v, ascii_io::s }, ascii_io::up, ascii_io::down, ascii_io::q);

	budget_data.set_spacing(1, 0, 5, 10);

	fleet_cost_data.set_spacing(1, 0, 5, 10);
	fleet_cost_data.add_border(true);

	finalize_fleet_setup.set_spacing(0, 0, 5, 10);
	finalize_fleet_setup.add_border(true);
	finalize_fleet_setup.set_alignment("center");
	finalize_fleet_setup.set_output("Finalize");
	finalize_fleet_setup.selectable();
}

bool display::is_number(const std::string& number_string)
{
	bool number = true;
	if (number_string.length() == 0)
	{
		number = false;
	}
	else
	{
		for (unsigned int i = 0; i < number_string.length(); i++)
		{
			if (!isdigit(number_string[i]))
			{
				number = false;
				break;
			}
		}
	}

	return number;
}