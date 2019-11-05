#pragma once

#pragma comment(lib,"Setupapi.lib")

#include <windows.h>
#include <SetupAPI.h>

#include "../Structures/container.h"
#include "USB_data_struct.h"


void get_all_drives(container<USB_Drive_struct>* drives);