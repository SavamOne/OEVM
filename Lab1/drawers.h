#pragma once

#include <iostream>
#include "data_type_struct.h"
#include "colors_config.h"

using namespace std;

void draw_menu(short index, data_types* dtf, short size);
void draw_bits(bool* bits, short size, short start, short end, char mode, short step = 0);

void draw_choose_menu(short index);
void draw_colors(short index, colors* clrs, short size, colors& bg_color);
