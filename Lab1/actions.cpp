#include"actions.h"

void main_acitivity()
{
	short dt_index = readers::choose_data_type();
	dtf[dt_index].processing();
}

void choose_text_color()
{
	text_color = readers::choose_color();
	console_handler::set_text_color(text_color);
}

void choose_bg_color()
{
	color c = readers::choose_color();
	console_handler::set_bg_color(c);
}

void choose_bit1_color()
{
	bit1_color = readers::choose_color();
}

void choose_bit2_color()
{
	bit2_color = readers::choose_color();
}