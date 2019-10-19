#ifndef DATA_TYPE_STRUCT_H
#define DATA_TYPE_STRUCT_H

#include <string>

using namespace std;

class data_types
{
	struct data_type
	{
		string data_type_name;
		void(*processing)();
	};

	data_type* arr;
	int arr_size;
	void reallocate(int how);

public:
	int size;
	data_types();
	void append(string data_type_name, void(* const func)());
	data_type& operator[] (int index);
	~data_types();
};
#endif //DATA_TYPE_STRUCT_H