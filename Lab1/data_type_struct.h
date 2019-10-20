#ifndef DATA_TYPE_STRUCT_H
#define DATA_TYPE_STRUCT_H

#include <string>

struct data_type
{
	std::string data_type_name;
	void(*processing)();

	data_type(std::string data_type_name, void(*func)());
	data_type() = default;
};

#endif //DATA_TYPE_STRUCT_H