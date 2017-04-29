#include "editor.h"

static cmd_t normal_mode_cmds[] = {
	{ 'i', NULL, INSERT },				//"i" - insert mode

	{CTRL('s'), write_file, NORMAL},	//ctrl+s - save
	{CTRL('o'), read_file, NORMAL},		//ctrl+o - open

	{CTRL('n'), new_buffer, NORMAL},	//ctrl+n - new buffer
	{CTRL('w'), del_buffer, NORMAL},
	{ CTRL('t'), next_buffer, NORMAL },
	{ CTRL('T'), prev_buffer, NORMAL },
	{ 'g', beg_of_buffer, NORMAL },
	{ 'G', end_of_buffer, NORMAL },

	{KEY_LEFT, prev_char, NORMAL },
	{KEY_DOWN, next_line, NORMAL },
	{KEY_UP, prev_line, NORMAL },
	{KEY_RIGHT, next_char, NORMAL },
	{'w', next_word, NORMAL },
	{'b', prev_word, NORMAL },
	{'x', del_char, NORMAL },
	
	{':', command, NORMAL },
	{'\0', NULL, NORMAL }
};

