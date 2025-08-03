#include "logic.h"

logic::logic()
{
	create_aeneas_template();
	create_horatius_template();
	create_liberator_template();
	create_lupis_template();
	create_remus_template();
	create_romulus_template();
	create_spartius_template();
	create_viper_template();
	create_wolverine_template();
}

std::vector<tank> logic::get_tank_templates()
{
	return tank_templates;
}

void logic::create_aeneas_template()
{
	tank aeneas;
	aeneas.set_name("Aeneas");
	aeneas.set_faction("TOG");
	aeneas.set_cost(861550);
	aeneas.set_stern_shield_factor(6);
	aeneas.set_left_shield_factor(5);
	aeneas.set_front_shield_factor(6);
	aeneas.set_right_shield_factor(5);
	aeneas.set_bottom_shield_factor(4);

	aeneas.set_turret_armor_thickness(6);
	aeneas.set_left_armor_thickness(5);
	aeneas.set_stern_armor_thickness(5);
	aeneas.set_right_armor_thickness(5);
	aeneas.set_front_armor_thickness(6);
	aeneas.set_bottom_armor_thickness(2);

	aeneas.set_max_thrust(8);

	aeneas.add_weapon("100 mm", "Turret", "5", "20");
	aeneas.add_weapon("1.5/4 Laser", "Turret", "T", "10");
	aeneas.add_weapon("TVLG (4)", "Turret", "T", "6");

	aeneas.set_tvlg_missle_count(4);

	tank_templates.push_back(aeneas);
}

void logic::create_horatius_template()
{
	tank horatius;
	horatius.set_name("Horatius");
	horatius.set_faction("TOG");
	horatius.set_cost(1617700);
	horatius.set_stern_shield_factor(7);
	horatius.set_left_shield_factor(6);
	horatius.set_front_shield_factor(7);
	horatius.set_right_shield_factor(6);
	horatius.set_bottom_shield_factor(4);

	horatius.set_turret_armor_thickness(8);
	horatius.set_left_armor_thickness(6);
	horatius.set_stern_armor_thickness(6);
	horatius.set_front_armor_thickness(8);
	horatius.set_right_armor_thickness(6);
	horatius.set_bottom_armor_thickness(4);

	horatius.set_max_thrust(6);

	horatius.add_weapon("3/6 Laser", "Turret", "8", "20");
	horatius.add_weapon("SMLM (2)", "Turret", "T", "10");
	horatius.add_weapon("50 mm", "Turret", "T", "6");
	horatius.add_weapon("Vulcan 2", "Turret", "S", "NA");
	horatius.add_weapon("150 mm", "Hull 1", "T", "15");

	horatius.set_smlm_missle_count(2);

	tank_templates.push_back(horatius);
}

void logic::create_liberator_template()
{
	tank liberator;
	liberator.set_name("Liberator");
	liberator.set_faction("Renegade");
	liberator.set_cost(1636350);
	liberator.set_stern_shield_factor(6);
	liberator.set_left_shield_factor(5);
	liberator.set_front_shield_factor(6);
	liberator.set_right_shield_factor(5);
	liberator.set_bottom_shield_factor(5);

	liberator.set_turret_armor_thickness(6);
	liberator.set_left_armor_thickness(7);
	liberator.set_stern_armor_thickness(7);
	liberator.set_right_armor_thickness(7);
	liberator.set_front_armor_thickness(8);
	liberator.set_bottom_armor_thickness(4);

	liberator.set_max_thrust(6);

	liberator.add_weapon("5/6 Laser", "Turret", "9", "20");
	liberator.add_weapon("150 mm", "Turret", "T", "15");
	liberator.add_weapon("50 mm", "Turret", "T", "6");
	liberator.add_weapon("Vulcan 3", "Turret", "S", "NA");
	liberator.add_weapon("TVLG (4)", "Hull 1", "T", "6");
	liberator.add_weapon("TVLG (4)", "Hull 2", "T", "6");

	liberator.set_tvlg_missle_count(8);

	tank_templates.push_back(liberator);
}

void logic::create_lupis_template()
{
	tank lupis;
	lupis.set_name("Lupis");
	lupis.set_faction("TOG");
	lupis.set_cost(454900);
	lupis.set_stern_shield_factor(5);
	lupis.set_left_shield_factor(4);
	lupis.set_front_shield_factor(5);
	lupis.set_right_shield_factor(4);
	lupis.set_bottom_shield_factor(4);

	lupis.set_turret_armor_thickness(6);
	lupis.set_stern_armor_thickness(5);
	lupis.set_left_armor_thickness(5);
	lupis.set_front_armor_thickness(6);
	lupis.set_right_armor_thickness(5);
	lupis.set_bottom_armor_thickness(3);

	lupis.set_max_thrust(8);

	lupis.add_weapon("25 mm", "Turret", "T", "6");
	lupis.add_weapon("SMLM (2)", "Turret", "T", "10");

	lupis.set_smlm_missle_count(2);
	tank_templates.push_back(lupis);
}

void logic::create_remus_template()
{
	tank remus;
	remus.set_name("Remus");
	remus.set_faction("TOG");
	remus.set_cost(984600);
	remus.set_stern_shield_factor(8);
	remus.set_left_shield_factor(7);
	remus.set_front_shield_factor(8);
	remus.set_right_shield_factor(7);
	remus.set_bottom_shield_factor(5);

	remus.set_turret_armor_thickness(9);
	remus.set_stern_armor_thickness(8);
	remus.set_left_armor_thickness(8);
	remus.set_front_armor_thickness(9);
	remus.set_right_armor_thickness(8);
	remus.set_bottom_armor_thickness(4);

	remus.set_max_thrust(6);

	remus.add_weapon("1.5/4 Laser", "Turret", "4", "20");
	remus.add_weapon("SMLM (2)", "Turret", "T", "10");
	remus.add_weapon("TVLG (4)", "Turret", "T", "6");
	remus.add_weapon("TVLG (4)", "Turret", "T", "6");
	remus.add_weapon("AP Laser", "Turret", "S", "3");

	remus.set_smlm_missle_count(2);
	remus.set_tvlg_missle_count(8);

	tank_templates.push_back(remus);
}

void logic::create_romulus_template()
{
	tank romulus;
	romulus.set_name("Romulus");
	romulus.set_faction("TOG");
	romulus.set_cost(1027900);
	romulus.set_stern_shield_factor(8);
	romulus.set_left_shield_factor(7);
	romulus.set_front_shield_factor(8);
	romulus.set_right_shield_factor(7);
	romulus.set_bottom_shield_factor(5);

	romulus.set_turret_armor_thickness(9);
	romulus.set_stern_armor_thickness(8);
	romulus.set_left_armor_thickness(8);
	romulus.set_front_armor_thickness(9);
	romulus.set_right_armor_thickness(8);
	romulus.set_bottom_armor_thickness(4);

	romulus.set_max_thrust(6);

	romulus.add_weapon("5/6 Laser", "Turret", "9", "20");
	romulus.add_weapon("SMLM (2)", "Turret", "T", "10");
	romulus.add_weapon("TVLG (4)", "Turret", "T", "6");
	romulus.add_weapon("TVLG (4)", "Turret", "T", "6");
	romulus.add_weapon("Vulcan 3", "Turret", "S", "NA");
	romulus.add_weapon("AP Laser", "Turret", "S", "3");

	romulus.set_smlm_missle_count(2);
	romulus.set_tvlg_missle_count(8);

	tank_templates.push_back(romulus);
}

void logic::create_spartius_template()
{
	tank spartius;
	spartius.set_name("Spartius");
	spartius.set_faction("Renegade");
	spartius.set_cost(1219850);
	spartius.set_stern_shield_factor(7);
	spartius.set_left_shield_factor(6);
	spartius.set_front_shield_factor(7);
	spartius.set_right_shield_factor(6);
	spartius.set_bottom_shield_factor(6);

	spartius.set_turret_armor_thickness(8);
	spartius.set_stern_armor_thickness(7);
	spartius.set_left_armor_thickness(7);
	spartius.set_front_armor_thickness(8);
	spartius.set_right_armor_thickness(7);
	spartius.set_bottom_armor_thickness(4);

	spartius.set_max_thrust(6);

	spartius.add_weapon("5/6 Laser", "Turret", "9", "20");
	spartius.add_weapon("5/6 Laser", "Turret", "9", "20");
	spartius.add_weapon("SMLM (2)", "Turret", "T", "10");
	spartius.add_weapon("TVLG (6)", "Turret", "T", "6");
	spartius.add_weapon("Vulcan 3", "Turret", "S", "NA");
	spartius.add_weapon("TVLG (4)", "Hull 1", "T", "6");
	spartius.add_weapon("TVLG (4)", "Hull 2", "T", "6");

	spartius.set_smlm_missle_count(2);
	spartius.set_tvlg_missle_count(14);

	tank_templates.push_back(spartius);
}

void logic::create_viper_template()
{
	tank viper;
	viper.set_name("Viper");
	viper.set_faction("Renegade");
	viper.set_cost(474600);
	viper.set_stern_shield_factor(5);
	viper.set_left_shield_factor(4);
	viper.set_front_shield_factor(5);
	viper.set_right_shield_factor(4);
	viper.set_bottom_shield_factor(4);

	viper.set_turret_armor_thickness(5);
	viper.set_stern_armor_thickness(4);
	viper.set_left_armor_thickness(4);
	viper.set_front_armor_thickness(5);
	viper.set_right_armor_thickness(4);
	viper.set_bottom_armor_thickness(2);

	viper.set_max_thrust(8);

	viper.add_weapon("25 mm", "Turret", "T", "6");
	viper.add_weapon("SMLM (2)", "Turret", "T", "10");
	viper.add_weapon("TVLG (2)", "Hull 1", "T", "6");
	viper.add_weapon("TVLG (2)", "Hull 2", "T", "6");

	viper.set_smlm_missle_count(2);
	viper.set_tvlg_missle_count(4);

	tank_templates.push_back(viper);
}

void logic::create_wolverine_template()
{
	tank wolverine;
	wolverine.set_name("Wolverine");
	wolverine.set_faction("Renegade");
	wolverine.set_cost(824300);
	wolverine.set_stern_shield_factor(5);
	wolverine.set_left_shield_factor(4);
	wolverine.set_front_shield_factor(6);
	wolverine.set_right_shield_factor(4);
	wolverine.set_bottom_shield_factor(3);

	wolverine.set_turret_armor_thickness(6);
	wolverine.set_stern_armor_thickness(5);
	wolverine.set_left_armor_thickness(4);
	wolverine.set_front_armor_thickness(6);
	wolverine.set_right_armor_thickness(4);
	wolverine.set_bottom_armor_thickness(2);

	wolverine.set_max_thrust(8);

	wolverine.add_weapon("100 mm", "Turret", "T", "10");
	wolverine.add_weapon("AP Laser", "Turret", "S", "3");
	wolverine.add_weapon("TVLG (4)", "Turret", "T", "6");
	wolverine.add_weapon("TVLG (2)", "Hull 1", "T", "6");
	wolverine.add_weapon("TVLG (2)", "Hull 2", "T", "6");

	wolverine.set_tvlg_missle_count(8);

	tank_templates.push_back(wolverine);
}