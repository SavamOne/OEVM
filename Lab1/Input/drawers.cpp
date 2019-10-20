#include "drawers.h"

void drawers::draw_bits(bool* bits, short size, short start, short end, char mode, short step)
{
	if (mode == 'd')
	{
		system("cls");
		cout << "Choose bits, that you want to cycle shift" << endl;
	}
	for (int i = 0; i < size; i++)
	{
		if (i >= start && i <= end)
			set_text_color(bit1_color);
		else
			set_text_color(text_color);

		if (mode == 'o' && i >= start && i <= start + step - 1)
			set_text_color(bit2_color);
		else if (mode == 'n' && i >= end + 1 - step  && i <= end)
			set_text_color(bit2_color);

		if (i % 8 == 0 && i > 0) 
			cout << " ";

		cout << bits[i];
	}
	cout << endl;
	set_text_color(text_color);
	if (mode == 'd')
		cout << "To move press <- or ->, to change size press ^ or v" << endl;
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
	set_text_color(text_color);
	cout << "Please, choose new color, which you want to use:" << endl;
	for (int i = 0; i < clrs.size; i++)
	{
		set_text_color(clrs[i]);
		cout << (i == index ? "-> " : "   ") << clrs[i].color_name << endl;
	}
}
