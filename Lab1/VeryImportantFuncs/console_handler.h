#pragma once
#include <Windows.h>
#include <iostream>
#include "../Structures/color_struct.h"

using namespace std;

extern color text_color, bit1_color, bit2_color, bg_color;

namespace console_handler
{
	extern HANDLE handle;
	extern HDC hDC;

	void update_handle();

	void define_pen(color& c);
	void set_pen_in(int x, int y);
	void line_to(int x, int y);

	COORD get_cursor_position();
	void set_cursor_position(int x, int y);
	int get_console_width();

	void set_text_color(color& color);
	void set_bg_color(color& color);	
}

