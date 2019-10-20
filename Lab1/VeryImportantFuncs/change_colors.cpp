#include"change_colors.h"


void set_text_color(color& color)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg_color.color_id << 4) | color.color_id));
}

void set_bg_color(color& color)
{
	bg_color = color;
	set_text_color(text_color);
}