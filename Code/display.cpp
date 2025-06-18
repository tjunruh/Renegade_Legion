#include "display.h"
#include <ascii_engine/ascii_io.h>
#include <ascii_engine/file_manager.h>
#include "damage_code.h"
#include <time.h>
#include <thread>
#include <chrono>

display::display(frame* tank_view_display, frame* tank_damage_display) :
	tank_image_one(tank_view_display),
	tank_image_two(tank_view_display),
	tank_stats(tank_damage_display, "board_configs/damage_record_template_config.txt", "default")
{
	tank_view_frame = tank_view_display;
	tank_damage_frame = tank_damage_display;
	
	tank_image_one.set_alignment("center block");
	tank_image_one.enable_word_wrap(false);
	tank_image_two.set_alignment("center block");
	tank_image_two.enable_word_wrap(false);

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

	create_tank_views();
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
	for (unsigned int i = 0; i < weapons.size(); i = i + 4)
	{
		tank_stats.set_tile(27, i, weapons[i].name);
		tank_stats.set_tile(27, i + 1, weapons[i].location);
		tank_stats.set_tile(27, i + 2, weapons[i].damage);
		tank_stats.set_tile(27, i + 3, weapons[i].range);
	}

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