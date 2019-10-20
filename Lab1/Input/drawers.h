#pragma once

#include <iostream>

#include "../Structures/data_type_struct.h"
#include "../Structures/action_struct.h"
#include "../Structures/container.h"

#include "../VeryImportantFuncs/change_colors.h"

extern container<data_type> dtf;
extern container<action> actions;

using namespace std;

namespace drawers
{
	void draw_menu(short index);
	void draw_bits(bool* bits, short size, short start, short end, char mode, short step = 0);

	void draw_choose_menu(short index);
	void draw_colors(short index, container<color>& clrs);
}