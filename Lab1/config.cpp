#include"config.h"

container<color> cs;
container<data_type> dtf;
container<main_menu> menu;

color* text_color, *bit1_color, *bit2_color, *bg_color, *graphic_color;

void init_dtf()
{
	dtf.append(data_type("int", processing_number<int, true>));
	dtf.append(data_type("short int", processing_number<short, true>));
	dtf.append(data_type("long int", processing_number<long, true>));
	dtf.append(data_type("long long int", processing_number<long long, true>));
	dtf.append(data_type("unsigned int", processing_number<unsigned int, false>));
	dtf.append(data_type("unsigned short int", processing_number<unsigned short, false>));
	dtf.append(data_type("unsigned long int", processing_number<unsigned long, false>));
	dtf.append(data_type("unsigned long long int", processing_number<unsigned long long, false>));
	dtf.append(data_type("float", processing_number<float, true>));
	dtf.append(data_type("double", processing_number<double, true>));
	dtf.append(data_type("long double", processing_number<long double, true>));
	dtf.append(data_type("char", processing_char));
}

void init_colors()
{
	cs.append(color("Black", 0, 0, 0, 0));
	cs.append(color("Blue", 1, 0, 0, 128));
	cs.append(color("Green", 2, 0, 128, 0));
	cs.append(color("Cyan", 3, 0, 128, 128));
	cs.append(color("Red", 4, 128, 0, 0));
	cs.append(color("Magenta", 5, 128, 0, 128));
	cs.append(color("Brown", 6, 128, 128, 128));
	cs.append(color("LightGray", 7, 192, 192, 192));
	cs.append(color("DarkGray", 8, 128, 128, 128));
	cs.append(color("LightBlue", 9, 0, 0, 255));
	cs.append(color("LightGreen", 10, 0, 255, 0));
	cs.append(color("LightCyan", 11, 0, 255, 255));
	cs.append(color("LightRed", 12, 255, 0, 0));
	cs.append(color("LightMagenta", 13, 255, 0, 255));
	cs.append(color("Yellow", 14, 255, 255, 0));
	cs.append(color("White", 15, 255, 255, 255));

	text_color = &cs[7];
	bit1_color = &cs[9];
	bit2_color = &cs[5];
	bg_color = &cs[0];
	graphic_color = &cs[15];
}

void init_main_menu()
{
	menu.append(main_menu("Start the program",  main_acitivity));
	menu.append(main_menu("Choose text color",  choose_text_color));
	menu.append(main_menu("Choose background color", choose_bg_color));
	menu.append(main_menu("Choose bit first color", choose_bit1_color));
	menu.append(main_menu("Choose bit second color", choose_bit2_color));
	menu.append(main_menu("Choose graphic color", choose_graphic_color));
}