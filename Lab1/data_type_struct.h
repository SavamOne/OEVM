#ifndef DATA_TYPE_STRUCT_H
#define DATA_TYPE_STRUCT_H

#include <string>

using namespace std;

struct data_types
{
    string data_type_name;
	void(*processing)();

	data_types(const string& data_type_name, void(*const func)());
};

#endif //DATA_TYPE_STRUCT_H