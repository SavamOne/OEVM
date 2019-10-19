#include "data_type_struct.h"

using namespace std;

void data_types::reallocate(int how)
{
	data_type* arr_new = new data_type[arr_size + how];
	for (int i = 0; i < arr_size; i++)
	{
		arr_new[i] = arr[i];
	}
	delete[] arr;
	arr = arr_new;
	arr_size += how;
}

data_types::data_types()
{
	size = 0;
	arr = new data_type[8];
	arr_size = 8;
}

data_types::~data_types()
{
	delete[] arr;
	arr_size = size = 0;
}

void data_types::append(string data_type_name, void(* const func)())
{
	if (arr_size == size)
		reallocate(5);

	arr[size].data_type_name = data_type_name;
	arr[size].processing = func;
	size++;
}

data_types::data_type& data_types::operator[] (int index)
{
	return arr[index];
}



