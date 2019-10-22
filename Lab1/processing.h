#pragma once

#include "MainLogic/pseudo_record_in_memory.h"
#include "MainLogic/converter.h"

#include "InputOutput/reader_options.h"
#include "InputOutput/reader_value.h"

#include "InputOutput/drawer_graphic.h"
#include "InputOutput/drawer_bits.h"

#include "shift_processing.h"

void processing_char();

template <class T, bool _signed>
void processing_number()
{
	cout.precision(10);

	unsigned short num_sys = readers::choose_number_system();
	string number =			 readers::read_value(num_sys, _signed);

	bool exceed_max_value;
	T a = main_processes::convert2decimal<T>(number, num_sys, exceed_max_value);
	bool* bits = main_processes::pseudo_record_in_memory(a);

	if(exceed_max_value) cout << "WARNING! Exceeding the maximum data type value, loss of accuracy" << endl;
	cout << "It is in decimal number system: " << a << endl;

	drawers::draw_bits_ticker(bits, sizeof(T)*8);

	if (a != 0)
	{
		char res;
		cout << "--------" << endl << "Press Enter to continue or ESC to finish" << endl;
		res = _getch();
		while (res != 13 && res != 27) { res = _getch(); };

		if (res == 13)
			shift_processing(bits, a);
	}
	delete[] bits;
}