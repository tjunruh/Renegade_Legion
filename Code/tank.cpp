#include "tank.h"
#include "damage_code.h"
#include <ascii_engine/error_codes.h>
#include <algorithm>

void tank::set_id(int id)
{
	_id = id;
}

void tank::set_name(const std::string& name)
{
	_name = name;
}

int tank::set_player(int player)
{
	int status = INVALID_VALUE;
	if (player == 1 || player == 2)
	{
		_player = player;
		status = SUCCESS;
	}

	return status;
}

int tank::set_number(int number)
{
	int status = INVALID_VALUE;
	if (number > 0)
	{
		_number = number;
		status = SUCCESS;
	}

	return status;
}

int tank::set_row(int row)
{
	int status = INVALID_VALUE;
	if (row >= 0)
	{
		if (_row != -1)
		{
			last_row = _row;
		}
		else
		{
			last_row = row;
		}

		_row = row;
		_position_changed = true;
		status = SUCCESS;
	}

	return status;
}

int tank::set_column(int column)
{
	int status = INVALID_VALUE;
	if (column >= 0)
	{
		if (_column != -1)
		{
			last_column = _column;
		}
		else
		{
			last_column = column;
		}

		_column = column;
		_position_changed = true;
		status = SUCCESS;
	}

	return status;
}

int tank::set_smlm_missle_count(int count)
{
	int status = INVALID_VALUE;
	if (count >= 0 && count <= MAX_SMLM_MISSLE_COUNT)
	{
		smlm_missle_count = count;
		status = SUCCESS;
	}

	return status;
}

int tank::set_tvlg_missle_count(int count)
{
	int status = INVALID_VALUE;
	if (count >= 0 && count <= MAX_TVLG_MISSLE_COUNT)
	{
		tvlg_missle_count = count;
		status = SUCCESS;
	}

	return status;
}

int tank::set_stern_shield_factor(int shield_factor)
{
	int status = INVALID_VALUE;
	if (shield_factor >= 0 && shield_factor <= MAX_SHIELD_FACTOR)
	{
		stern_shield_factor = shield_factor;
		status = SUCCESS;
	}

	return status;
}

int tank::set_left_shield_factor(int shield_factor)
{
	int status = INVALID_VALUE;
	if (shield_factor >= 0 && shield_factor <= MAX_SHIELD_FACTOR)
	{
		left_shield_factor = shield_factor;
		status = SUCCESS;
	}

	return status;
}

int tank::set_front_shield_factor(int shield_factor)
{
	int status = INVALID_VALUE;
	if (shield_factor >= 0 && shield_factor <= MAX_SHIELD_FACTOR)
	{
		front_shield_factor = shield_factor;
		status = SUCCESS;
	}

	return status;
}

int tank::set_right_shield_factor(int shield_factor)
{
	int status = INVALID_VALUE;
	if (shield_factor >= 0 && shield_factor <= MAX_SHIELD_FACTOR)
	{
		right_shield_factor = shield_factor;
		status = SUCCESS;
	}

	return status;
}

int tank::set_bottom_shield_factor(int shield_factor)
{
	int status = INVALID_VALUE;
	if (shield_factor >= 0 && shield_factor <= MAX_SHIELD_FACTOR)
	{
		bottom_shield_factor = shield_factor;
		status = SUCCESS;
	}

	return status;
}

int tank::add_weapon(const std::string& name, const std::string& location, const std::string& damage, const std::string& range)
{
	int status = INVALID_LENGTH;
	if ((weapon_entries.size() + 1) <= MAX_WEAPONS)
	{
		weapon_entry weapon;
		weapon.name = name;
		weapon.location = location;
		weapon.damage = damage;
		weapon.range = range;
		weapon_entries.push_back(weapon);
		status = SUCCESS;
	}

	return status;
}

void tank::set_fire_modifiers(const std::string& fire_modifiers)
{
	_fire_modifiers = fire_modifiers;
}

int tank::set_digging_charge_count(int count)
{
	int status = INVALID_VALUE;
	if (count >= 0 && count <= MAX_DIGGING_CHARGE_COUNT)
	{
		digging_charge_count = count;
		status = SUCCESS;
	}

	return status;
}

int tank::set_smoke_charge_count(int count)
{
	int status = INVALID_VALUE;
	if (count >= 0 && count <= MAX_SMOKE_CHARGE_COUNT)
	{
		smoke_charge_count = count;
		status = SUCCESS;
	}

	return status;
}

int tank::set_velocity_record(int velocity, int turn)
{
	int status = INVALID_VALUE;
	if ((velocity >= (_max_thrust * -1)) && (velocity <= _max_thrust) && (turn >= 0) && (turn <= MAX_TURNS))
	{
		bool element_already_exists = false;
		for (unsigned int i = 0; i < velocity_record.size(); i++)
		{
			if (velocity_record[i].turn == turn)
			{
				velocity_record[i].velocity = velocity;
				element_already_exists = true;
				break;
			}
		}

		if (!element_already_exists)
		{
			velocity_record_unit single_velocity_record;
			single_velocity_record.velocity = velocity;
			single_velocity_record.turn = turn;
			velocity_record.push_back(single_velocity_record);
		}

		status = SUCCESS;
	}

	return status;
}

int tank::set_max_thrust(int max_thrust)
{
	int status = INVALID_VALUE;
	if (max_thrust >= 0)
	{
		_max_thrust = max_thrust;
		status = SUCCESS;
	}

	return status;
}

int tank::set_turret_armor_thickness(int thickness)
{
	int status = INVALID_VALUE;
	if (thickness >= 0 && thickness <= MAX_ARMOR_THICKNESS)
	{
		turret_armor_thickness = thickness;
		status = SUCCESS;
	}

	return status;
}

int tank::set_stern_armor_thickness(int thickness)
{
	int status = INVALID_VALUE;
	if (thickness >= 0 && thickness <= MAX_ARMOR_THICKNESS)
	{
		stern_armor_thickness = thickness;
		status = SUCCESS;
	}

	return status;
}

int tank::set_left_armor_thickness(int thickness)
{
	int status = INVALID_VALUE;
	if (thickness >= 0 && thickness <= MAX_ARMOR_THICKNESS)
	{
		left_armor_thickness = thickness;
		status = SUCCESS;
	}

	return status;
}

int tank::set_front_armor_thickness(int thickness)
{
	int status = INVALID_VALUE;
	if (thickness >= 0 && thickness <= MAX_ARMOR_THICKNESS)
	{
		front_armor_thickness = thickness;
		status = SUCCESS;
	}

	return status;
}

int tank::set_right_armor_thickness(int thickness)
{
	int status = INVALID_VALUE;
	if (thickness >= 0 && thickness <= MAX_ARMOR_THICKNESS)
	{
		right_armor_thickness = thickness;
		status = SUCCESS;
	}

	return status;
}

int tank::set_bottom_armor_thickness(int thickness)
{
	int status = INVALID_VALUE;
	if (thickness >= 0 && thickness <= MAX_ARMOR_THICKNESS)
	{
		bottom_armor_thickness = thickness;
		status = SUCCESS;
	}

	return status;
}

void tank::set_faction(const std::string& faction)
{
	_faction = faction;
}

void tank::set_cost(float cost)
{
	_cost = cost;
}

int tank::set_turret_direction(int direction)
{
	int status = INVALID_VALUE;
	if (direction >= 1 && direction <= 6)
	{
		if (turret_direction != -1)
		{
			previous_turret_direction = turret_direction;
		}
		else
		{
			previous_turret_direction = direction;
		}

		turret_direction = direction;
		status = SUCCESS;
	}

	return status;
}

int tank::set_tank_direction(int direction)
{
	int status = INVALID_VALUE;
	if (direction >= 1 && direction <= 6)
	{
		if (tank_direction != -1)
		{
			previous_tank_direction = tank_direction;
		}
		else
		{
			previous_tank_direction = direction;
		}

		tank_direction = direction;
		status = SUCCESS;
	}

	return status;
}

int tank::apply_damage(const std::string& side, int column, const std::vector<weapons::damage_coordinate>& damage)
{
	int status = INVALID_VALUE;
	if (std::count(valid_side_names.begin(), valid_side_names.end(), side) != 0 && column >= 0 && column <= ARMOR_COLUMNS_PER_SIDE)
	{
		status = SUCCESS;
		if (side == "turret")
		{
			apply_turret_damage(column, damage);
		}
		else if (side == "stern")
		{
			apply_stern_damage(column, damage);
		}
		else if (side == "left")
		{
			apply_left_damage(column, damage);
		}
		else if (side == "front")
		{
			apply_front_damage(column, damage);
		}
		else if (side == "right")
		{
			apply_right_damage(column, damage);
		}
		else if (side == "bottom")
		{
			apply_bottom_damage(column, damage);
		}
		else
		{
			status = INVALID_VALUE;
		}
	}

	return status;
}

void tank::acknowledge_position_changed()
{
	_position_changed = false;
}

int tank::get_id()
{
	return _id;
}

std::string tank::get_name()
{
	return _name;
}

int tank::get_player()
{
	return _player;
}

int tank::get_number()
{
	return _number;
}

int tank::get_row()
{
	return _row;
}

int tank::get_column()
{
	return _column;
}

int tank::get_previous_row()
{
	return last_row;
}

int tank::get_previous_column()
{
	return last_column;
}

int tank::get_smlm_missle_count()
{
	return smlm_missle_count;
}

int tank::get_tvlg_missle_count()
{
	return tvlg_missle_count;
}

int tank::get_stern_shield_factor()
{
	return stern_shield_factor;
}

int tank::get_left_shield_factor()
{
	return left_shield_factor;
}

int tank::get_front_shield_factor()
{
	return front_shield_factor;
}

int tank::get_right_shield_factor()
{
	return right_shield_factor;
}

int tank::get_bottom_shield_factor()
{
	return bottom_shield_factor;
}

std::vector<tank::weapon_entry> tank::get_weapons()
{
	return weapon_entries;
}

std::string tank::get_fire_modifiers()
{
	return _fire_modifiers;
}

int tank::get_digging_charge_count()
{
	return digging_charge_count;
}

int tank::get_smoke_charge_count()
{
	return smoke_charge_count;
}

int tank::get_max_thrust()
{
	return _max_thrust;
}

int tank::get_turret_armor_thickness()
{
	return turret_armor_thickness;
}

int tank::get_stern_armor_thickness()
{
	return stern_armor_thickness;
}

int tank::get_left_armor_thickness()
{
	return left_armor_thickness;
}

int tank::get_front_armor_thickness()
{
	return front_armor_thickness;
}

int tank::get_right_armor_thickness()
{
	return right_armor_thickness;
}

int tank::get_bottom_armor_thickness()
{
	return bottom_armor_thickness;
}

int tank::get_turret_direction()
{
	return turret_direction;
}

int tank::get_tank_direction()
{
	return tank_direction;
}

int tank::get_previous_turret_direction()
{
	return previous_turret_direction;
}

int tank::get_previous_tank_direction()
{
	return previous_tank_direction;
}

std::string tank::get_faction()
{
	return _faction;
}

float tank::get_cost()
{
	return _cost;
}

tank::damage_record tank::get_damage_record()
{
	return total_damage;
}

std::vector<tank::velocity_record_unit> tank::get_velocity_record()
{
	return velocity_record;
}

bool tank::position_changed()
{
	return _position_changed;
}

void tank::apply_turret_damage(int column, const std::vector<weapons::damage_coordinate>& damage)
{
	int row = -1;
	for (unsigned int i = 0; i < ARMOR_ROWS_PER_SIDE; i++)
	{
		if (total_damage.turret_armor[i][column] == undamaged)
		{
			row = i;
			break;
		}
	}

	if (row == -1)
	{
		for (unsigned int i = 0; i < ROWS_IN_INTERNALS; i++)
		{
			if (total_damage.internal[i][column] == undamaged)
			{
				row = i + ARMOR_ROWS_PER_SIDE;
				break;
			}
		}
	}

	if (row != -1)
	{
		int damage_row = 0;
		int damage_column = 0;
		for (unsigned int i = 0; i < damage.size(); i++)
		{
			damage_row = row + damage[i].row;
			damage_column = column + damage[i].column;
			if (damage_column >= 0 && damage_column < ARMOR_COLUMNS_PER_SIDE)
			{
				if (damage_row < ARMOR_ROWS_PER_SIDE)
				{
					if (damage_column >= 0 && damage_column < ARMOR_COLUMNS_PER_SIDE)
					{
						total_damage.turret_armor[i][column] = damaged;
					}
				}
				else if ((damage_row - ARMOR_ROWS_PER_SIDE) < ROWS_IN_INTERNALS)
				{
					total_damage.internal[damage_row - ARMOR_ROWS_PER_SIDE][column] = damaged;
				}
			}
		}
	}
}

void tank::apply_stern_damage(int column, const std::vector<weapons::damage_coordinate>& damage)
{
	int row = -1;
	for (unsigned int i = 0; i < ARMOR_ROWS_PER_SIDE; i++)
	{
		if (total_damage.stern_armor[i][column] == undamaged)
		{
			row = i;
			break;
		}
	}

	if (row == -1)
	{
		for (unsigned int i = 0; i < ROWS_IN_INTERNALS; i++)
		{
			if (total_damage.internal[i][column + STERN_INTERNAL_COLUMN_OFFSET] == undamaged)
			{
				row = i + ARMOR_ROWS_PER_SIDE;
				break;
			}
		}
	}

	if (row != -1)
	{
		int damage_row = 0;
		int damage_column = 0;
		for (unsigned int i = 0; i < damage.size(); i++)
		{
			damage_row = row + damage[i].row;
			damage_column = column + damage[i].column;
			if (damage_row < ARMOR_ROWS_PER_SIDE)
			{
				if (damage_column >= 0 && damage_column < ARMOR_ROWS_PER_SIDE)
				{
					total_damage.stern_armor[damage_row][damage_column] = damaged;
				}
			}
			else if ((damage_row - ARMOR_ROWS_PER_SIDE) < ROWS_IN_INTERNALS)
			{
				damage_column = damage_column + STERN_INTERNAL_COLUMN_OFFSET;
				if (damage_column >= STERN_INTERNAL_COLUMN_OFFSET)
				{
					total_damage.internal[damage_row - ARMOR_ROWS_PER_SIDE][damage_column] = damaged;
				}
			}
		}
	}
}

void tank::apply_left_damage(int column, const std::vector<weapons::damage_coordinate>& damage)
{
	int row = -1;
	for (unsigned int i = 0; i < ARMOR_ROWS_PER_SIDE; i++)
	{
		if (total_damage.left_armor[i][column] == undamaged)
		{
			row = i;
			break;
		}
	}

	if (row == -1)
	{
		for (unsigned int i = 0; i < ROWS_IN_INTERNALS; i++)
		{
			if (total_damage.internal[i][column + LEFT_INTERNAL_COLUMN_OFFSET] == undamaged)
			{
				row = i + ARMOR_ROWS_PER_SIDE;
				break;
			}
		}
	}

	if (row != -1)
	{
		int damage_row = 0;
		int damage_column = 0;
		for (unsigned int i = 0; i < damage.size(); i++)
		{
			damage_row = row + damage[i].row;
			damage_column = column + damage[i].column;
			if (damage_row < ARMOR_ROWS_PER_SIDE)
			{
				if (damage_column >= 0 && damage_column < ARMOR_ROWS_PER_SIDE)
				{
					total_damage.left_armor[damage_row][damage_column] = damaged;
				}
			}
			else if ((damage_row - ARMOR_ROWS_PER_SIDE) < ROWS_IN_INTERNALS)
			{
				total_damage.internal[damage_row - ARMOR_ROWS_PER_SIDE][damage_column + LEFT_INTERNAL_COLUMN_OFFSET] = damaged;
			}
		}
	}
}

void tank::apply_front_damage(int column, const std::vector<weapons::damage_coordinate>& damage)
{
	int row = -1;
	for (unsigned int i = 0; i < ARMOR_ROWS_PER_SIDE; i++)
	{
		if (total_damage.front_armor[i][column] == undamaged)
		{
			row = i;
			break;
		}
	}

	if (row == -1)
	{
		for (unsigned int i = 0; i < ROWS_IN_INTERNALS; i++)
		{
			if (total_damage.internal[i][column + FRONT_INTERNAL_COLUMN_OFFSET] == undamaged)
			{
				row = i + ARMOR_ROWS_PER_SIDE;
				break;
			}
		}
	}

	if (row != -1)
	{
		int damage_row = 0;
		int damage_column = 0;
		for (unsigned int i = 0; i < damage.size(); i++)
		{
			damage_row = row + damage[i].row;
			damage_column = column + damage[i].column;
			if (damage_row < ARMOR_ROWS_PER_SIDE)
			{
				if (damage_column >= 0 && damage_column < ARMOR_ROWS_PER_SIDE)
				{
					total_damage.front_armor[damage_row][damage_column] = damaged;
				}
			}
			else if ((damage_row - ARMOR_ROWS_PER_SIDE) < ROWS_IN_INTERNALS)
			{
				total_damage.internal[damage_row - ARMOR_ROWS_PER_SIDE][damage_column + FRONT_INTERNAL_COLUMN_OFFSET] = damaged;
			}
		}
	}
}

void tank::apply_right_damage(int column, const std::vector<weapons::damage_coordinate>& damage)
{
	int row = -1;
	for (unsigned int i = 0; i < ARMOR_ROWS_PER_SIDE; i++)
	{
		if (total_damage.right_armor[i][column] == undamaged)
		{
			row = i;
			break;
		}
	}

	if (row == -1)
	{
		for (unsigned int i = 0; i < ROWS_IN_INTERNALS; i++)
		{
			if (total_damage.internal[i][column + RIGHT_INTERNAL_COLUMN_OFFSET] == undamaged)
			{
				row = i + ARMOR_ROWS_PER_SIDE;
				break;
			}
		}
	}

	if (row != -1)
	{
		int damage_row = 0;
		int damage_column = 0;
		for (unsigned int i = 0; i < damage.size(); i++)
		{
			damage_row = row + damage[i].row;
			damage_column = column + damage[i].column;
			if (damage_row < ARMOR_ROWS_PER_SIDE)
			{
				if (damage_column >= 0 && damage_column < ARMOR_ROWS_PER_SIDE)
				{
					total_damage.right_armor[damage_row][damage_column] = damaged;
				}
			}
			else if ((damage_row - ARMOR_ROWS_PER_SIDE) < ROWS_IN_INTERNALS)
			{
				damage_column = damage_column + RIGHT_INTERNAL_COLUMN_OFFSET;
				if (damage_column < BOTTOM_INTERNAL_COLUMN_OFFSET)
				{
					total_damage.internal[damage_row - ARMOR_ROWS_PER_SIDE][damage_column] = damaged;
				}
			}
		}
	}
}

void tank::apply_bottom_damage(int column, const std::vector<weapons::damage_coordinate>& damage)
{
	int row = -1;
	for (unsigned int i = 0; i < ARMOR_ROWS_PER_SIDE; i++)
	{
		if (total_damage.bottom_armor[i][column] == undamaged)
		{
			row = i;
			break;
		}
	}

	if (row == -1)
	{
		for (unsigned int i = 0; i < ROWS_IN_INTERNALS; i++)
		{
			if (total_damage.internal[i][column + BOTTOM_INTERNAL_COLUMN_OFFSET] == undamaged)
			{
				row = i + ARMOR_ROWS_PER_SIDE;
				break;
			}
		}
	}

	if (row != -1)
	{
		int damage_row = 0;
		int damage_column = 0;
		for (unsigned int i = 0; i < damage.size(); i++)
		{
			damage_row = row + damage[i].row;
			damage_column = column + damage[i].column;
			if (damage_row < ARMOR_ROWS_PER_SIDE)
			{
				if (damage_column >= 0 && damage_column < ARMOR_ROWS_PER_SIDE)
				{
					total_damage.bottom_armor[damage_row][damage_column] = damaged;
				}
			}
			else if ((damage_row - ARMOR_ROWS_PER_SIDE) < ROWS_IN_INTERNALS)
			{
				damage_column = damage_column + BOTTOM_INTERNAL_COLUMN_OFFSET;
				if (damage_column >= BOTTOM_INTERNAL_COLUMN_OFFSET && damage_column < COLUMNS_IN_INTERNALS)
				{
					total_damage.internal[damage_row - ARMOR_ROWS_PER_SIDE][damage_column] = damaged;
				}
			}
		}
	}
}