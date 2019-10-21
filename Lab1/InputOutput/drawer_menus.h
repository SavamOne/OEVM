#pragma once

#include <iostream>

#include "../Structures/data_type_struct.h"
#include "../Structures/action_struct.h"
#include "../Structures/container.h"

#include "../VeryImportantFuncs/console_handler.h"

extern container<data_type> dtf;
extern container<main_menu> menu;

using namespace std;

namespace drawers
{
	void draw_choose_data_type(short index);
	void draw_choose_action(short index);
	void draw_choose_color(short index, container<color*>* clrs);
}