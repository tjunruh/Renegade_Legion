#include "logic.h"

logic::logic()
{
	tank aeneas;
	aeneas.set_name("Aeneas");
	aeneas.set_stern_shield_factor(6);
	aeneas.set_front_shield_factor(6);
	aeneas.set_left_shield_factor(5);
	aeneas.set_right_shield_factor(5);
	aeneas.set_bottom_shield_factor(4);

	aeneas.set_turret_armor_thickness(6);
	aeneas.set_stern_armor_thickness(5);
	aeneas.set_left_armor_thickness(5);
	aeneas.set_right_armor_thickness(5);
	aeneas.set_front_armor_thickness(6);
	aeneas.set_bottom_armor_thickness(2);

	aeneas.set_max_thrust(8);

	aeneas.add_weapon("1.5/4", "Turret", "", "");
	aeneas.add_weapon("100mm", "Turret", "", "");
	aeneas.add_weapon("TVLG-4", "Turret", "", "");
	tank_templates.push_back(aeneas);

	tank horatius;
	horatius.set_name("Horatius");
	tank_templates.push_back(horatius);

	tank liberator;
	liberator.set_name("Liberator");
	tank_templates.push_back(liberator);

	tank lupis;
	lupis.set_name("Lupis");
	tank_templates.push_back(lupis);

	tank remus;
	remus.set_name("Remus");
	tank_templates.push_back(remus);

	tank romulus;
	romulus.set_name("Romulus");
	tank_templates.push_back(romulus);

	tank spartius;
	spartius.set_name("Spartius");
	tank_templates.push_back(spartius);

	tank viper;
	viper.set_name("Viper");
	tank_templates.push_back(viper);

	tank wolverine;
	wolverine.set_name("Wolverine");
	tank_templates.push_back(wolverine);
}

std::vector<tank> logic::get_tank_templates()
{
	return tank_templates;
}