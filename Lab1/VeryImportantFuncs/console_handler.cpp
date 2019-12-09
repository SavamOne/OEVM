#include "console_handler.h"

HANDLE console_handler::handle;
HWND console_handler::hWnd;
HDC console_handler::hDC;
HPEN console_handler::Pen;

void console_handler::update_handle()
{
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
}

void console_handler::define_pen(color* c)
{
	update_handle();
	hWnd = GetConsoleWindow();
	hDC = GetDC(hWnd);
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(c->R, c->G, c->B));
	SelectObject(hDC, Pen);
}

void console_handler::clear_pen()
{
	ReleaseDC(hWnd, hDC);
	DeleteObject(Pen);
}

void console_handler::clear_console_buffer()
{
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
}

void console_handler::clear_console()
{
	update_handle();

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD count;
	DWORD cellCount;
	COORD startCoord = { 0, 0 };

	GetConsoleScreenBufferInfo(handle, &csbi);
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	FillConsoleOutputCharacter(handle, (TCHAR)' ', cellCount, startCoord, &count);
	SetConsoleCursorPosition(handle, startCoord);
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
	GetConsoleScreenBufferInfo(handle, &consoleInfo);
	return consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
}

float console_handler::get_scaling_parameter()
{
	hWnd = GetConsoleWindow();
	HDC hDCScreen = GetDC(hWnd);
	float a = (float)GetDeviceCaps(hDCScreen, DESKTOPVERTRES) / (float)GetDeviceCaps(hDCScreen, VERTRES);
	ReleaseDC(hWnd, hDCScreen);
	return a;
}

COORD console_handler::get_font_size()
{
	update_handle();
	CONSOLE_FONT_INFO font_num;
	GetCurrentConsoleFont(handle, false, &font_num);
	return font_num.dwFontSize; //font_num.dwFontSize
}

void console_handler::set_text_color(color* color)
{
	update_handle();
	SetConsoleTextAttribute(handle, (WORD)((bg_color->color_id << 4) | color->color_id));
}

void console_handler::set_bg_color(color* color)
{
	bg_color = color;
	set_text_color(text_color);
}