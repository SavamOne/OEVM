#ifndef READERS_H
#define READERS_H

#include <string>
#include <iostream>
#include <conio.h>
#include <limits>

#include "symb2digit.h"
#include "drawers.h"

using namespace std;


short choose_data_type(data_types* dtf, short size);
int choose_number_system();
string read_value(const int& ns, bool _signed);


short choose_shift();
bool choose_direction();
short* choose_bits(bool* bits, short size);

short choose_action();
colors choose_color(colors* clrs, short size, colors& bg_color);

#endif //READERS_H