#pragma once

#include <vector>
#include <string>

class weapons
{
public:
	struct damage_coordinate
	{
		int row = -1;
		int column = -1;
	};

	std::vector<std::string> get_weapon_names();
	std::vector<damage_coordinate> get_damage_pattern(const std::string& name);
private:
	struct weapon_data
	{
		std::string name = "";
		std::vector<damage_coordinate> damage_pattern;
	};

	// shape:
	// #####
	//  ###
	const std::vector<damage_coordinate> MDC8_damage_pattern =
	{
		{0, -2}, {0,-1}, {0, 0}, {0, 1}, {0, 2},
		{1, -1}, {1, 0}, {1, 1}
	};

	const weapon_data MDC8 =
	{
		"MDC8",
		MDC8_damage_pattern
	};

	// shape:
	// #####
	//  ###
	//   #
	//   #
	const std::vector<damage_coordinate> MDC10_damage_pattern =
	{
		{0, -2}, {0, -1}, {0, 0}, {0, 1}, {0, 2},
		{1, -1}, {1, 0}, {1, 1},
		{2, 0},
		{3, 0}
	};

	const weapon_data MDC10 =
	{
		"MDC10",
		MDC10_damage_pattern
	};

	// shape:
	// #####
	//  ###
	//  ###
	//   #
	const std::vector<damage_coordinate> MDC12_damage_pattern =
	{
		{0, -2}, {0, -1}, {0, 0}, {0, 1}, {0, 2},
		{1, -1}, {1, 0}, {1, 1},
		{2, -1}, {2, 0}, {2, 1},
		{3, 0}
	};

	const weapon_data MDC12 =
	{
		"MDC12",
		MDC12_damage_pattern
	};

	// shape:
	//  #
	// ###
	//  #
	const std::vector<damage_coordinate> APDS_25mm_damage_pattern =
	{
		{0, 0},
		{1, -1}, {1, 0}, {1, 1},
		{2, 0}
	};

	const weapon_data APDS_25mm =
	{
		"APDS 25mm",
		APDS_25mm_damage_pattern
	};

	// shape:
	//  #
	// ###
	// ###
	const std::vector<damage_coordinate> APDS_50mm_damage_pattern =
	{
		{0, 0},
		{1, -1}, {1, 0}, {1, 1},
		{2, -1}, {2, 0}, {2, 1}
	};

	const weapon_data APDS_50mm =
	{
		"APDS 50mm",
		APDS_50mm_damage_pattern
	};

	// shape:
	//   #
	//  ###
	//  ###
	// #####
	const std::vector<damage_coordinate> APDS_100mm_damage_pattern =
	{
		{0, 0},
		{1, -1}, {1, 0}, {1, 1},
		{2, -1}, {2, 0}, {2, 1},
		{3, -2}, {3, -1}, {3, 0}, {3, 1}, {3, 2}
	};

	const weapon_data APDS_100mm =
	{
		"APDS 100mm",
		APDS_100mm_damage_pattern
	};

	// shape:
	//   #
	//  ###
	//  ###
	// #####
	//  ###
	const std::vector<damage_coordinate> APDS_150mm_damage_pattern =
	{
		{0, 0},
		{1, -1}, {1, 0}, {1, 1},
		{2, -1}, {2, 0}, {2, 1},
		{3, -2}, {3, -1}, {3, 0}, {3, 1}, {3, 2},
		{4, -1}, {4, 0}, {4, 1}
	};

	const weapon_data APDS_150mm =
	{
		"APDS 150mm",
		APDS_150mm_damage_pattern
	};

	// shape:
	//    #
	//   ###
	//  #####
	// #######
	//  #####
	//   ###
	const std::vector<damage_coordinate> APDS_200mm_damage_pattern =
	{
		{0, 0},
		{1, -1}, {1, 0}, {1, 1},
		{2, -2}, {2, -1}, {2, 0}, {2, 1}, {2, 2},
		{3, -3}, {3, -2}, {3, -1}, {3, 0}, {3, 1}, {3, 2}, {3, 3},
		{4, -2}, {4, -1}, {4, 0}, {4, 1}, {4, 2},
		{5, -1}, {5, 0}, {5, 1}
	};

	const weapon_data APDS_200mm =
	{
		"APDS 200mm",
		APDS_200mm_damage_pattern
	};

	// shape:
	//  #
	//  #
	// ###
	const std::vector<damage_coordinate> hammer_head_25mm_damage_pattern =
	{
		{0, 0},
		{1, 0},
		{2, -1}, {2, 0}, {2, 1}
	};

	const weapon_data hammer_head_25mm =
	{
		"hammer head 25mm",
		hammer_head_25mm_damage_pattern
	};

	// shape:
	//  #
	//  #
	//  #
	// ###
	const std::vector<damage_coordinate> hammer_head_50mm_damage_pattern =
	{
		{0, 0},
		{1, 0},
		{2, 0},
		{3, -1}, {3, 0}, {3, 1}
	};

	const weapon_data hammer_head_50mm =
	{
		"hammer head 50mm",
		hammer_head_50mm_damage_pattern
	};

	// shape
	//   #
	//   #
	//   #
	//   #
	// #####
	const std::vector<damage_coordinate> hammer_head_100mm_damage_pattern =
	{
		{0, 0},
		{1, 0},
		{2, 0},
		{3, 0},
		{4, -2}, {4, -1}, {4, 0}, {4, 1}, {4, 2}
	};

	const weapon_data hammer_head_100mm =
	{
		"hammer head 100mm",
		hammer_head_100mm_damage_pattern
	};

	// shape:
	// #
	// #
	// #
	const std::vector<damage_coordinate> HEAP_25mm_damage_pattern =
	{
		{0, 0},
		{1, 0},
		{2, 0}
	};

	const weapon_data HEAP_25mm =
	{
		"HEAP 25mm",
		HEAP_25mm_damage_pattern
	};

	// shape:
	// ###
	//  #
	//  #
	//  #
	const std::vector<damage_coordinate> HEAP_50mm_damage_pattern =
	{
		{0, -1}, {0, 0}, {0, 1},
		{1, 0},
		{2, 0},
		{3, 0}
	};

	const weapon_data HEAP_50mm =
	{
		"HEAP 50mm",
		HEAP_50mm_damage_pattern
	};

	// shape:
	// ###
	// ###
	//  #
	//  #
	//  #
	const std::vector<damage_coordinate> HEAP_100mm_damage_pattern =
	{
		{0, -1}, {0, 0}, {0, 1},
		{1, -1}, {1, 0}, {1, 1},
		{2, 0},
		{3, 0},
		{4, 0}
	};

	const weapon_data HEAP_100mm =
	{
		"HEAP 100mm",
		HEAP_100mm_damage_pattern
	};

	// shape:
	// #####
	//  ###
	//  ###
	//   #
	//   #
	//   #
	//   #
	const std::vector<damage_coordinate> HEAP_150mm_damage_pattern =
	{
		{0, -2}, {0, -1}, {0, 0}, {0, 1}, {0, 2},
		{1, -1}, {1, 0}, {1, 1},
		{2, -1}, {2, 0}, {2, 1},
		{3, 0},
		{4, 0},
		{5, 0},
		{6, 0}
	};

	const weapon_data HEAP_150mm =
	{
		"HEAP 150mm",
		HEAP_150mm_damage_pattern
	};

	// shape:
	// #####
	// #####
	//  ###
	//  ###
	//   #
	//   #
	//   #
	//   #
	const std::vector<damage_coordinate> HEAP_200mm_damage_pattern =
	{
		{0, -2}, {0, -1}, {0, 0}, {0, 1}, {0, 2},
		{1, -2}, {1, -1}, {1, 0}, {1, 1}, {1, 2},
		{2, -1}, {2, 0}, {2, 1},
		{3, -1}, {3, 0}, {3, 1},
		{4, 0},
		{5, 0},
		{6, 0},
		{7, 0}
	};

	const weapon_data HEAP_200mm =
	{
		"HEAP 200mm",
		HEAP_200mm_damage_pattern
	};

	// shape:
	//   #
	//   #
	//   #
	// #####
	// #####
	const std::vector<damage_coordinate> TVLG_missle_damage_pattern =
	{
		{0, 0},
		{1, 0},
		{2, 0},
		{3, -2}, {3, -1}, {3, 0}, {3, 1}, {3, 2},
		{4, -2}, {4, -1}, {4, 0}, {4, 1}, {4, 2}
	};

	const weapon_data TVLG_missle =
	{
		"TVLG missle",
		TVLG_missle_damage_pattern
	};

	// shape:
	// #########
	// # # # # #
	//   # # #
	//     #
	const std::vector<damage_coordinate> SMLM_missle_damage_pattern =
	{
		{0, -4}, {0, -3 }, {0, -2}, {0, -1}, {0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4},
		{1, -4}, {1, -2}, {1, 0}, {1, 2}, {1, 4},
		{2, -2}, {2, 0}, {2, 2},
		{3, 0}
	};

	const weapon_data SMLM_missle =
	{
		"SMLM missle",
		SMLM_missle_damage_pattern
	};

	std::vector<weapon_data> all_weapon_data =
	{
		MDC8,
		MDC10,
		MDC12,
		APDS_25mm,
		APDS_50mm,
		APDS_100mm,
		APDS_150mm,
		APDS_200mm,
		hammer_head_25mm,
		hammer_head_50mm,
		hammer_head_100mm,
		HEAP_25mm,
		HEAP_50mm,
		HEAP_100mm,
		HEAP_150mm,
		HEAP_200mm,
		TVLG_missle,
		SMLM_missle
	};
};