#include "auth_reader.h"



short choose_auth_method()
{
	char* methods[] = { "Без защиты", "USB-накопитель + пароль" };

	short index = 0;
	char move;
	draw_auth_methods(index);
	do
	{
		move = _getch();

		if (move == 80)
		{
			index = ++index % 2;
			draw_auth_methods(index);
		}
		else if (move == 72)
		{
			index = (index > 0 ? --index : 2);
			draw_auth_methods(index);
		}

	} while (move != 13);
	system("cls");

	cout << "You choosed: " << methods[index] << endl;

	return index;
}

void draw_auth_methods(short index)
{
	system("cls");
	char* methods[] = { "Без защиты", "USB-накопитель + пароль" };

	cout << "Please, choose unlock method, which you want to use:" << endl;
	for (int i = 0; i < 2; i++)
		cout << (i == index ? "-> " : "   ") << methods[i] << endl;
}


void get_all_drives(container<USB_Drive_struct>* drives);

short choose_usb_storage(container<USB_Drive_struct>* drives)
{
	short index = 0;
	char move;
	draw_usb_storages(index, drives);
	do
	{
		drives->~container();
		get_all_drives(drives);

		move = _getch();

		if (move == 80)
		{
			index = ++index % drives->size;
			draw_usb_storages(index, drives);
		}
		else if (move == 72)
		{
			index = (index > 0 ? --index : drives->size);
			draw_usb_storages(index, drives);
		}

	} while (move != 13);
	system("cls");

	cout << "You choosed: " << (*drives)[index] << endl;

	return index;

}

void draw_usb_storages(short index, container<USB_Drive_struct>* drives)
{
	system("cls");
	cout << "Please, choose USB-drive, which you want to use:" << endl;
	for (int i = 0; i < drives->size; i++)
		cout << (i == index ? "-> " : "   ") << (*drives)[i] << endl;
}