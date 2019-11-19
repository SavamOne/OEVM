#pragma once

#include <string>
#include <iostream>
#include <conio.h>

#include "drawer_menus.h"

extern container<main_menu> menu;
extern container<data_type> dtf;
extern container<color> cs;

namespace readers
{
	short choose_data_type();
	short choose_action();
	color* choose_color();
	short choose_auth_method();
	short choose_usb_storage(container<USB_Drive_struct>* drives);
}