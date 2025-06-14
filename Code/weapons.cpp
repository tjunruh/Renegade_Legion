#include "weapons.h"

std::vector<std::string> weapons::get_weapon_names()
{
	std::vector<std::string> weapon_names;
	for (unsigned int i = 0; i < all_weapon_data.size(); i++)
	{
		weapon_names.push_back(all_weapon_data[i].name);
	}

	return weapon_names;
}

std::vector<weapons::damage_coordinate> weapons::get_damage_pattern(const std::string& name)
{
	std::vector<damage_coordinate> damage_pattern;
	for (unsigned int i = 0; i < all_weapon_data.size(); i++)
	{
		if (all_weapon_data[i].name == name)
		{
			damage_pattern = all_weapon_data[i].damage_pattern;
			break;
		}
	}

	return damage_pattern;
}