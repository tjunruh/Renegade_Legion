#pragma once

#include <vector>
#include <string>
#include "tank.h"

class logic
{
public:
	logic();
	std::vector<tank> get_tank_templates();
private:
	void create_aeneas_template();
	void create_horatius_template();
	void create_liberator_template();
	void create_lupis_template();
	void create_remus_template();
	void create_romulus_template();
	void create_spartius_template();
	void create_viper_template();
	void create_wolverine_template();
	std::vector<tank> tank_templates;
};