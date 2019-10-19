#include "drawers.h"

void draw_bits(bool* bits, short size, short start, short end, char mode, short step)
{
	if (mode == 'd')
	{
		system("cls");
		cout << "Choose bits, that you want to cycle shift" << endl;
	}
	for (int i = 0; i < size; i++)
	{
		if (i >= start && i <= end)
		{
			set_text_color(bit1_color);
		}
		else
		{
			set_text_color(text_color);
		}

		if (mode == 'o' && i >= start && i <= start + step - 1)
		{
			set_text_color(bit2_color);
		}
		if (mode == 'n' && i >= end + 1 - step  && i <= end)
		{
			set_text_color(bit2_color);
		}

		if (i % 8 == 0 && i > 0) cout << " ";
		cout << bits[i];
	}
	cout << endl;
	set_text_color(text_color);
	if (mode == 'd')
	{
		cout << "To move press <- or ->, to change size press ^ or v" << endl;
	}
}

void draw_menu(short index, data_types* dtf, short size)
{
	system("cls");
	cout << "Please, choose data type, which you want to use:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << (i == index ? "-> " : "   ") << dtf[i].data_type_name << endl;
	}
}

void draw_choose_menu(short index)
{
	system("cls");
	string arr[] = { "Start the program", "Choose text color", "Choose background color", "Choose bit first color", "Choose bit second color" };
	for (int i = 0; i < 5; i++)
	{
		cout << (i == index ? "-> " : "   ") << arr[i] << endl;
	}
}

void draw_colors(short index, colors* clrs, short size, colors& bg_color)
{
	system("cls");
	set_text_color(text_color);
	cout << "Please, choose new color, which you want to use:" << endl;
	for (int i = 0; i < size; i++)
	{
		//if (clrs[i].color_id != bg_color.color_id)
		//{
			set_text_color(clrs[i]);
			cout << (i == index ? "-> " : "   ") << clrs[i].color_name << endl;
		//}
	}
}
