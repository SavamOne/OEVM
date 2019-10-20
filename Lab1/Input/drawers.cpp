#include "drawers.h"

void drawers::draw_bit(bool bit, short i, short start, short end, char mode, short step)
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

void drawers::draw_bits(bool* bits, short size, short start, short end, char mode, short step)
{
	if (mode == 'd')
	{
		system("cls");
		cout << "Choose bits, that you want to cycle shift" << endl;
	}


	if (mode == 'o' || mode == 'n')
	{			
		int width = console_handler::get_console_width();
		COORD coord = console_handler::get_cursor_position();
		for (int x = width; x >= 0; x--)
		{
			console_handler::set_cursor_position(x, coord.Y);
			for (int i = 0; i < width - x -2 - (size / 8 -1) && i < size; i++)
				draw_bit(bits[i], i, start, end, mode, step);
			cout << " ";
			Sleep(20);
		}
	}
	else
	{
		for (int i = 0; i < size; i++)
			draw_bit(bits[i], i, start, end, mode, step);
	}
	cout << endl;
	console_handler::set_text_color(text_color);
	if (mode == 'd')
		cout << "To move press <- or ->, to change size press ^ or v" << endl;
}

void drawers::draw_graphic(bool* bits, short size, int cell_size, int x_start, int y_start)
{
	console_handler::define_pen(text_color);
	cout << endl << endl << endl;
	
	console_handler::set_pen_in(x_start, bits[0] == 0 ? y_start + cell_size : y_start);
	for (int x = 0; x < size; x++)
	{
		for (int t = x * cell_size; t <= (x + 1) * cell_size; t += 2)
			console_handler::line_to(x_start + t, bits[x] == 0 ? y_start + cell_size : y_start);

		if (x < size - 1)
			console_handler::line_to(x_start + (x + 1) * cell_size, bits[x + 1] == 0 ? y_start + cell_size : y_start);
	}
}

void drawers::draw_menu(short index)
{
	system("cls");
	cout << "Please, choose data type, which you want to use:" << endl;
	for (int i = 0; i < dtf.size; i++)
		cout << (i == index ? "-> " : "   ") << dtf[i].data_type_name << endl;
}

void drawers::draw_choose_menu(short index)
{
	system("cls");
	cout << "Please, choose what you want to do" << endl;
	for (int i = 0; i < actions.size; i++)
		cout << (i == index ? "-> " : "   ") << actions[i].action_name << endl;
}

void drawers::draw_colors(short index, container<color>& clrs)
{
	system("cls");
	console_handler::set_text_color(text_color);
	cout << "Please, choose new color, which you want to use:" << endl;
	for (int i = 0; i < clrs.size; i++)
	{
		console_handler::set_text_color(clrs[i]);
		cout << (i == index ? "-> " : "   ") << clrs[i].color_name << endl;
	}
}
