#include "data_type_struct.h"

data_type::data_type(string data_type_name, void(*func)())
{
	this->data_type_name = data_type_name;
	this->processing = func;
}