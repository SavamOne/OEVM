#include "USB_data_struct.h"

USB_Drive_struct::USB_Drive_struct()
{
	memset(name, 0, sizeof(name));
	memset(data, 0, sizeof(data));
}

std::ostream& operator<< (std::ostream& out, const USB_Drive_struct& drive)
{
	out << drive.name;
	return out;
}