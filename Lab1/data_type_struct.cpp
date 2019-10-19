#include "data_type_struct.h"

using namespace std;


data_types::data_types(const string& data_type_name, void(*const func)())
{
    this->data_type_name = data_type_name;
    this->processing = func;
}

