#include"actions.h"

void main_acitivity()
{
	short dt_index = readers::choose_data_type();
	dtf[dt_index].processing();
}

void choose_text_color()
{
	colors c = readers::choose_color();
	text_color = c;
	set_text_color(text_color);
}

void choose_bg_color()
{
	colors c = readers::choose_color();
	set_bg_color(c);
}

void choose_bit1_color()
{
	colors c = readers::choose_color();
	bit1_color = c;
}

void choose_bit2_color()
{
	colors c = readers::choose_color();
	bit2_color = c;
}