#include "colors_config.h"

colors cs[] = { colors("Black", 0),
					  colors("Blue", 1),
					  colors("Green", 2),
					  colors("Cyan", 3),
					  colors("Red", 4),
					  colors("Magenta", 5),
					  colors("Brown", 6),
					  colors("LightGray", 7),
					  colors("DarkGray", 8),
					  colors("LightBlue", 9),
					  colors("LightGreen", 10),
					  colors("LightCyan", 11),
					  colors("LightRed", 12),
					  colors("LightMagenta", 13),
					  colors("Yellow", 14),
					  colors("White", 15)
};

int cs_count = 16;

colors text_color = cs[7], bit1_color = cs[9], bit2_color = cs[5], bg_color = cs[0];

void set_text_color(colors& color)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg_color.color_id << 4) | color.color_id));
}

void set_bg_color(colors& color)
{
	bg_color = color;
	set_text_color(text_color);
}