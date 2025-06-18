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
	std::vector<tank> tank_templates;
};