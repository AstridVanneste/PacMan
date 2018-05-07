/*
 * keys.h
 *
 *  Created on: Apr 2, 2018
 *      Author: Astrid
 */

#ifndef SETTINGS_KEYS_H_
#define SETTINGS_KEYS_H_

#include <string>
using namespace std;

namespace Settings
{
	// MAP PATH
	const string MAP_PATH = "map_path";

	// GOD MODE
	const string GOD_MODE = "god_mode";

	// POINTS
	const string DOT_VALUE = "dot_value";
	const string POWER_PELLET_VALUE = "power_pellet_value";
	const string GHOST_VALUE = "ghost_value";

	// SPEEDS
	const string GHOST_SPEED = "ghost_speed";
	const string PACMAN_SPEED = "pacman_speed";

	// MAX LIVES
	const string MAX_LIVES = "max_lives";

	// BACKGROUND COLOR
	const string B_R = "b_r";
	const string B_G = "b_g";
	const string B_B = "b_b";
	const string B_A = "b_a";

	// IMAGES
	const string GHOST_PATH = "ghost_path";
	const string PACMAN_PATH = "pacman_path";
	const string WALL_PATH = "wall_path";

	// FONTS
	const string FONT_PATH = "font_path";
	const string FONT_SIZE = "font_size";

	const string TEXT_OFFSET = "text_offset";
	const string TEXT_HEIGHT = "text_height";
	const string TEXT_WIDTH = "text_width";

	// MUSIC
	const string MUSIC_ENABLE = "music_enable";
	const string MUSIC_VOLUME = "music_volume";
	const string MUSIC_PATH = "music_path";

	// ENTITY SIZE
	const string ENTITY_HEIGHT = "entity_height";
	const string ENTITY_WIDTH = "entity_width";

	const string ARENA_OFFSET = "arena_offset";

	// GAME PHASES
	const string CHASE_TIME = "chase_time";
	const string SCATTER_TIME = "scatter_time";
	const string FLEE_TIME = "flee_time";
}



#endif /* SETTINGS_KEYS_H_ */
