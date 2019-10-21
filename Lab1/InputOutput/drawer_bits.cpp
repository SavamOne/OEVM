#include "drawer_bits.h"

void drawers::draw_bit(bool bit, short i, char mode ,short start, short end, short step)
{
	if (i >= start && i <= end)
		console_handler::set_text_color(bit1_color);
	else
		console_handler::set_text_color(text_color);

	if (mode == 'o' && i >= start && i <= start + step - 1)
		console_handler::set_text_color(bit2_color);
	else if (mode == 'n' && i >= end + 1 - step && i <= end)
		console_handler::set_text_color(bit2_color);

	if (i % 8 == 0 && i > 0)
		cout << " ";

	cout << bit;
}

void drawers::draw_bits_ticker(bool* bits, short size, char mode, short start, short end, short step)
{
	int width = console_handler::get_console_width();
	if (width != -1)
	{
		COORD coord = console_handler::get_cursor_position();
		for (int x = width; x >= 0; x--)
		{
			console_handler::set_cursor_position(x, coord.Y);
			for (int i = 0; i < width - x - 2 - (size / 8 - 1) && i < size; i++)
				draw_bit(bits[i], i, mode, start, end, step);
			cout << " ";
			Sleep(20);
		}

		cout << endl;
		console_handler::set_text_color(text_color);
	}
	else
	{
		draw_bits(bits, size, mode, start, end, step);
	}
}

void drawers::draw_bits(bool* bits, short size, char mode, short start, short end, short step)
{
	if (mode == 'd')
	{
		system("cls");
		cout << "Choose bits, that you want to cycle shift" << endl;
	}

	for (int i = 0; i < size; i++)
		draw_bit(bits[i], i, mode, start, end, step);

	cout << endl;
	console_handler::set_text_color(text_color);

	if (mode == 'd')
		cout << "To move press <- or ->, to change size press ^ or v" << endl;
}