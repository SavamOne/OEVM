#pragma once
#include <Windows.h>
#include <d2d1.h>
#include <iostream>
#include "../Structures/color_struct.h"

using namespace std;

extern color* text_color, *bit1_color, *bit2_color, *bg_color, *graphic_color;

namespace console_handler
{
	extern HANDLE handle;
	extern HDC hDC;
	extern HPEN Pen;
	extern HWND hWnd;

	void update_handle();

	void define_pen(color* c);
	void clear_pen();
	void set_pen_in(int x, int y);
	void line_to(int x, int y);

	COORD get_cursor_position();
	void set_cursor_position(int x, int y);
	int get_console_width();
	COORD get_font_size();
	float get_scaling_parameter();

	void set_text_color(color* color);
	void set_bg_color(color* color);	
}

