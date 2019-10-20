#pragma once

#include <iostream>
#include "data_type_struct.h"
#include "action_struct.h"
#include "container.h"
#include "change_colors.h"

extern container<data_type> dtf;
extern container<colors> cs;
extern container<action> actions;

using namespace std;

namespace drawers
{
	void draw_menu(short index);
	void draw_bits(bool* bits, short size, short start, short end, char mode, short step = 0);

	void draw_choose_menu(short index);
	void draw_colors(short index, container<colors>& clrs);
}