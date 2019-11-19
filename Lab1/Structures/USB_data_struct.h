#pragma once

#include <windows.h>
#include <fstream>

struct USB_Drive_struct
{
	char name[256];
	char data[256];

	USB_Drive_struct();

	friend std::ostream& operator<< (std::ostream&, const USB_Drive_struct&);
};

std::ostream& operator<< (std::ostream& out, const USB_Drive_struct& drive);