#pragma once

#include <string>
#include <vector>
#include <ascii_engine/frame.h>
#include <ascii_engine/label.h>
#include <ascii_engine/ascii_board.h>
#include <ascii_engine/format_tools.h>
#include "tank.h"

class display
{
public:
	display(frame* tank_view_display, frame* tank_damage_display);
	void display_tank_view(const std::string& tank_one_name, const std::string& tank_one_side, const std::string& tank_two_name, const std::string& tank_two_side);
	void display_tank_stats(tank& tank_data);

private:
	board_configuration build_damage_config(const std::string& name_id, const std::string& value, char ignore_character, const std::vector<format_tools::index_format>& colors);
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

	std::vector<tank_view> tank_views;
};