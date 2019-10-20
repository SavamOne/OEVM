#include "console_handler.h"

HANDLE console_handler::handle;
HDC console_handler::hDC;

void console_handler::update_handle()
{
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
}

void console_handler::define_pen(color& c)
{
	update_handle();
	hDC = GetDC(GetConsoleWindow());
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(123, 23, 222));
	SelectObject(hDC, Pen);
}

void console_handler::set_pen_in(int x, int y)
{
	MoveToEx(hDC, x, y, NULL);
}

void console_handler::line_to(int x, int y)
{
	LineTo(hDC, x, y);
	Sleep(10);
}

COORD console_handler::get_cursor_position()
{
	update_handle();
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	return info.dwCursorPosition;
}

void console_handler::set_cursor_position(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(handle, coord);
}

int console_handler::get_console_width()
{
	update_handle();
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	if (GetConsoleScreenBufferInfo(handle, &consoleInfo))
		return consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
	else
		return -1;
}

void console_handler::set_text_color(color& color)
{
	update_handle();
	SetConsoleTextAttribute(handle, (WORD)((bg_color.color_id << 4) | color.color_id));
}

void console_handler::set_bg_color(color& color)
{
	bg_color = color;
	set_text_color(text_color);
}