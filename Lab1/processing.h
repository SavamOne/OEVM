#pragma once
//#include <iostream>

#include "pseudo_record_in_memory.h"
#include "cycling_shift.h"

#include "converter.h"
#include "readers.h"

template <class T>
void processing_shift(bool* bits, T a)
{
	short* params = choose_bits(bits, sizeof(T) * 8);
	bool dir = choose_direction();
	short step = choose_shift();
	step %= (params[1] - params[0] + 1);
	if (dir == 1)
	{
		step = params[1] - params[0] - step + 1;
	}
	system("cls");

	cout << "Old value:" << endl;
	draw_bits(bits, sizeof(T) * 8, params[0], params[1], 'o', step);
	cout << "Old number in decimal number system: " << fixed << a << endl;

	T new_a = cyclic_shift<T>(bits, params[0], params[1], step);

	cout << "New value:" << endl;
	draw_bits(bits, sizeof(T) * 8, params[0], params[1], 'n', step);
	cout << "New number in decimal number system: " << fixed << new_a << endl;

	delete[] params;
}

void processing_char();

template <class T, bool _signed>
void processing_number()
{
	unsigned short num_sys = 0;
	string number;

	num_sys = choose_number_system();
	number = read_value(num_sys, _signed);

	T a = convert2decimal<T>(number, num_sys);
	cout.precision(10);
	bool* bits = pseudo_record_in_memory(a);

	cout << "It is in decimal number system: " << a << endl;
	draw_bits(bits, sizeof(T)*8, -1, -1, 's');

	cout << "--------" << endl << "Press Enter to continue" << endl;
	while (_getch() != 13) {};

	processing_shift(bits, a);
	delete[] bits;
}