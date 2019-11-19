#pragma once

#include <iostream>

#include "../Structures/data_type_struct.h"
#include "../Structures/action_struct.h"
#include "../Structures/container.h"
#include "../Structures/USB_data_struct.h"
#include "../Structures/auth_methods_struct.h"

#include "../VeryImportantFuncs/console_handler.h"

#include "../Authorization/get_all_drives.h"

extern container<data_type> dtf;
extern container<main_menu> menu;
extern container<auth_method> auth_methods;


using namespace std;

namespace drawers
{
	void draw_choose_data_type(short index);
	void draw_choose_action(short index);
	void draw_choose_color(short index, container<color*>* clrs);
	void draw_usb_storages(short index, container<USB_Drive_struct>* drives);
	void draw_auth_methods(short index);

}