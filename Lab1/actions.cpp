#include"actions.h"

void main_acitivity()
{
	short dt_index = readers::choose_data_type();
	dtf[dt_index].processing();
}

void choose_text_color()
{
	color* c = readers::choose_color();
	if (c)
	{
		text_color = c;
		console_handler::set_text_color(text_color);
	}
}

void choose_bg_color()
{
	color* c = readers::choose_color();
	if(c)
		console_handler::set_bg_color(c);
}

void choose_bit1_color()
{
	color* c = readers::choose_color();
	if (c)
		bit1_color = c;
}

void choose_bit2_color()
{
	color* c = readers::choose_color();
	if (c)
		bit2_color = c;
}

void choose_graphic_color()
{
	color* c = readers::choose_color();
	if (c)
		graphic_color = c;
}