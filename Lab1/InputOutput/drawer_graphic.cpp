#include "drawer_graphic.h"

void drawers::draw_graphic(bool* bits, short size)
{
	COORD font_size = console_handler::get_font_size();
	float scale_parameter = console_handler::get_scaling_parameter();

	int font_size_Y = font_size.Y * scale_parameter;
	int font_size_X = font_size.X * scale_parameter;

	int x_start = 20;
	int y_start = (console_handler::get_cursor_position().Y + 1) * font_size_Y;

	int width = console_handler::get_console_width();
	int cell_size = (width * font_size_X - x_start*2) / size;

	for (int i = 0; i <= cell_size + font_size_Y; i += font_size_Y)
		cout << endl;

	console_handler::define_pen(graphic_color);
	console_handler::set_pen_in(x_start, bits[0] == 0 ? y_start + cell_size : y_start);
	for (int x = 0; x < size; x++)
	{
		for (int t = x * cell_size; t <= (x + 1) * cell_size; t += 2)
			console_handler::line_to(x_start + t, bits[x] == 0 ? y_start + cell_size : y_start);

		if (x < size - 1)
			console_handler::line_to(x_start + (x + 1) * cell_size, bits[x + 1] == 0 ? y_start + cell_size : y_start);
	}

	console_handler::clear_pen();
}