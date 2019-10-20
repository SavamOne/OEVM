#ifndef READERS_H
#define READERS_H

#include <string>
#include <iostream>
#include <conio.h>
#include <limits>

#include "symb2digit.h"
#include "drawers.h"

using namespace std;

extern container<data_type> dtf;

namespace readers
{
	short choose_data_type();
	int choose_number_system();
	string read_value(const int& ns, bool _signed);


	short choose_shift();
	bool choose_direction();
	short* choose_bits(bool* bits, short size);

	short choose_action();
	colors choose_color();
}


#endif //READERS_H