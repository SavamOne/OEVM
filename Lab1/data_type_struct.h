#ifndef DATA_TYPE_STRUCT_H
#define DATA_TYPE_STRUCT_H

#include <string>

using namespace std;

struct data_type
{
	string data_type_name;
	void(*processing)();

	data_type(string data_type_name, void(*func)());
	data_type() = default;
};

#endif //DATA_TYPE_STRUCT_H