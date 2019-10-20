#include"config.h"

container<color> cs;
container<data_type> dtf;
container<action> actions;

color text_color, bit1_color, bit2_color, bg_color;

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
	cs.append(color("Black", 0));
	cs.append(color("Blue", 1));
	cs.append(color("Green", 2));
	cs.append(color("Cyan", 3));
	cs.append(color("Red", 4));
	cs.append(color("Magenta", 5));
	cs.append(color("Brown", 6));
	cs.append(color("LightGray", 7));
	cs.append(color("DarkGray", 8));
	cs.append(color("LightBlue", 9));
	cs.append(color("LightGreen", 10));
	cs.append(color("LightCyan", 11));
	cs.append(color("LightRed", 12));
	cs.append(color("LightMagenta", 13));
	cs.append(color("Yellow", 14));
	cs.append(color("White", 15));

	text_color = cs[7];
	bit1_color = cs[9];
	bit2_color = cs[5];
	bg_color = cs[0];
}

void init_actions()
{
	actions.append(action("Start the program",  main_acitivity));
	actions.append(action("Choose text color",  choose_text_color));
	actions.append(action("Choose background color", choose_bg_color));
	actions.append(action("Choose bit first color", choose_bit1_color));
	actions.append(action("Choose bit second color", choose_bit2_color));
}