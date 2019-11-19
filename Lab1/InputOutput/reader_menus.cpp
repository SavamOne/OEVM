#include "reader_menus.h"


short readers::choose_data_type() {
	short index = 0;
	char move;
	drawers::draw_choose_data_type(index);
	do
	{
		move = _getch();

		if (move == 80)
		{
			index = ++index % dtf.size;
			drawers::draw_choose_data_type(index);
		}
		else if (move == 72)
		{
			index = (index > 0 ? --index : dtf.size - 1);
			drawers::draw_choose_data_type(index);
		}

	} while (move != 13);
	system("cls");

	cout << "You choosed: " << dtf[index].data_type_name << endl;

	return index;
}

short readers::choose_action()
{
	short index = 0;
	char move;
	drawers::draw_choose_action(index);
	do
	{
		move = _getch();

		if (move == 80)
		{
			index = ++index % menu.size;
			drawers::draw_choose_action(index);
		}
		else if (move == 72)// && index > 0)
		{
			index = (index > 0 ? --index : menu.size - 1);
			drawers::draw_choose_action(index);
		}

	} while (move != 13);
	system("cls");

	return index;
}

color* readers::choose_color()
{
	container<color*>* clrs_n = new container<color*>();
	for (int i = 0; i < cs.size; i++)
	{
		if (&cs[i] != text_color
			&& &cs[i] != bit1_color
			&& &cs[i] != bit2_color
			&& &cs[i] != graphic_color
			&& &cs[i] != bg_color)
		{
			clrs_n->append(&cs[i]);
		}
	}

	short index = 0;
	char move;
	drawers::draw_choose_color(index, clrs_n);
	do
	{
		move = _getch();

		if (move == 80)
		{
			index = ++index % clrs_n->size;
			drawers::draw_choose_color(index, clrs_n);
		}
		else if (move == 72)
		{
			index = (index > 0 ? --index : clrs_n->size - 1);
			drawers::draw_choose_color(index, clrs_n);
		}

	} while (move != 13 && move != 27);

	console_handler::set_text_color(text_color);
	system("cls");
	color* ret;
	if (move == 27)
		ret = nullptr;
	else
	{
		ret = (*clrs_n)[index];
		cout << "You choosed: " << ret->color_name << endl;
	}
	delete clrs_n;
	return ret;
}

short readers::choose_auth_method()
{
	short index = 0;
	char move;
	drawers::draw_auth_methods(index);
	do
	{
		move = _getch();

		if (move == 80)
		{
			index = ++index % auth_methods.size;
			drawers::draw_auth_methods(index);
		}
		else if (move == 72)
		{
			index = (index > 0 ? --index : auth_methods.size - 1);
			drawers::draw_auth_methods(index);
		}

	} while (move != 13);
	system("cls");

	cout << "You choosed: " << auth_methods[index].method_name_name << endl;

	return index;
}

short readers::choose_usb_storage(container<USB_Drive_struct>* drives)
{
	short index = 0;
	char move;
	drawers::draw_usb_storages(index, drives);
	do
	{
		move = _getch();

		if (move == 80)
		{
			index = ++index % drives->size;
			drawers::draw_usb_storages(index, drives);
			get_all_drives(drives);
		}
		else if (move == 72)
		{
			index = (index > 0 ? --index : drives->size - 1);
			drawers::draw_usb_storages(index, drives);
			get_all_drives(drives);
		}

	} while (move != 13);
	system("cls");

	cout << "You choosed: " << (*drives)[index] << endl;

	return index;

}
