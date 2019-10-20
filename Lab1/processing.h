#pragma once

#include "pseudo_record_in_memory.h"
#include "cycling_shift.h"

#include "converter.h"
#include "readers.h"

template <class T>
void processing_shift(bool* bits, T a)
{
	short* params = readers::choose_bits(bits, sizeof(T) * 8);
	bool dir =		readers::choose_direction();
	short step =	readers::choose_shift();
	step %= (params[1] - params[0] + 1);
	if (dir == 1)
		step = params[1] - params[0] - step + 1;
	system("cls");

	cout << "Old value:" << endl;
	drawers::draw_bits(bits, sizeof(T) * 8, params[0], params[1], 'o', step);
	cout << "Old number in decimal number system: " << fixed << a << endl;

	T new_a = cyclic_shift<T>(bits, params[0], params[1], step);

	cout << "New value:" << endl;
	drawers::draw_bits(bits, sizeof(T) * 8, params[0], params[1], 'n', step);
	cout << "New number in decimal number system: " << fixed << new_a << endl;

	delete[] params;
}

void processing_char();

template <class T, bool _signed>
void processing_number()
{
	cout.precision(10);

	unsigned short num_sys = readers::choose_number_system();
	string number =			 readers::read_value(num_sys, _signed);

	bool exceed_max_value;
	T a = converter::convert2decimal<T>(number, num_sys, exceed_max_value);
	bool* bits = pseudo_record_in_memory(a);

	if(exceed_max_value) cout << "WARNING! Exceeding the maximum data type value, loss of accuracy" << endl;
	cout << "It is in decimal number system: " << a << endl;

	drawers::draw_bits(bits, sizeof(T)*8, -1, -1, 's');

	if (a != 0)
	{
		char res;
		cout << "--------" << endl << "Press Enter to continue or ESC to finish" << endl;
		res = _getch();
		while (res != 13 && res != 27) { res = _getch(); };

		if (res == 13)
			processing_shift(bits, a);
	}
	delete[] bits;
}