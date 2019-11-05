#pragma once

#include "get_all_drives.h"
#include <iostream>
#include <conio.h>

using namespace std;

short choose_auth_method();

void draw_auth_methods(short index);

short choose_usb_storage(container<USB_Drive_struct>* drives);

void draw_usb_storages(short index, container<USB_Drive_struct>* drives);