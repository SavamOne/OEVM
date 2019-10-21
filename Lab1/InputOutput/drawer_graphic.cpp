#include "drawer_graphic.h"

void drawers::draw_graphic(bool* bits, short size)
{
	const int line_height = 20;

	int width = console_handler::get_console_width();
	int cell_size = (width * 6 - 40) / size;
	int x_start = 20;
	int y_start = console_handler::get_cursor_position().Y*line_height + line_height;

	for (int i = 0; i <= cell_size + line_height; i += line_height)
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
}