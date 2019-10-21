#include "drawer_menus.h"

void drawers::draw_choose_data_type(short index)
{
	system("cls");
	cout << "Please, choose data type, which you want to use:" << endl;
	for (int i = 0; i < dtf.size; i++)
		cout << (i == index ? "-> " : "   ") << dtf[i].data_type_name << endl;
}

void drawers::draw_choose_action(short index)
{
	system("cls");
	cout << "Please, choose what you want to do" << endl;
	for (int i = 0; i < menu.size; i++)
		cout << (i == index ? "-> " : "   ") << menu[i].action_name << endl;
}

void drawers::draw_choose_color(short index, container<color*>* clrs)
{
	system("cls");
	console_handler::set_text_color(text_color);
	cout << "Please, choose new color, which you want to use:" << endl;
	for (int i = 0; i < clrs->size; i++)
	{
		console_handler::set_text_color((*clrs)[i]);
		cout << (i == index ? "-> " : "   ") << (*clrs)[i]->color_name << endl;
	}
}
