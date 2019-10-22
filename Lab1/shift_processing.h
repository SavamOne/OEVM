#pragma once

#include "InputOutput/drawer_graphic.h"
#include "InputOutput/reader_bits.h"
#include "MainLogic/cycling_shift.h"

template<class T>
void show_bits_and_graphic(bool* bits, T a, const char* desctiption, short start, short end, short step)
{
	cout << desctiption << " value:" << endl;
	drawers::draw_bits_ticker(bits, sizeof(T) * 8, desctiption[0], start, end, step);
	cout << desctiption << " number in decimal number system: " << fixed << a << endl;
	drawers::draw_graphic(bits, sizeof(T) * 8);
}

template <class T>
void shift_processing(bool* bits, T a)
{
	short* params = readers::choose_bits(bits, sizeof(T) * 8);
	bool dir = readers::choose_direction();
	short step = readers::choose_shift();

	step %= (params[1] - params[0] + 1);
	if (dir == 1)
		step = params[1] - params[0] - step + 1;

	system("cls");

	show_bits_and_graphic(bits, a, "Old", params[0], params[1], step);

	T new_a = main_processes::cyclic_shift<T>(bits, params[0], params[1], step);

	show_bits_and_graphic(bits, new_a, "New", params[0], params[1], step);

	delete[] params;
}

