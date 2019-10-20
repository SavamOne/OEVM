#include"config.h"

container<colors> cs;
container<data_type> dtf;
colors text_color, bit1_color, bit2_color, bg_color;

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
	cs.append(colors("Black", 0));
	cs.append(colors("Blue", 1));
	cs.append(colors("Green", 2));
	cs.append(colors("Cyan", 3));
	cs.append(colors("Red", 4));
	cs.append(colors("Magenta", 5));
	cs.append(colors("Brown", 6));
	cs.append(colors("LightGray", 7));
	cs.append(colors("DarkGray", 8));
	cs.append(colors("LightBlue", 9));
	cs.append(colors("LightGreen", 10));
	cs.append(colors("LightCyan", 11));
	cs.append(colors("LightRed", 12));
	cs.append(colors("LightMagenta", 13));
	cs.append(colors("Yellow", 14));
	cs.append(colors("White", 15));

	text_color = cs[7];
	bit1_color = cs[9];
	bit2_color = cs[5];
	bg_color = cs[0];
}