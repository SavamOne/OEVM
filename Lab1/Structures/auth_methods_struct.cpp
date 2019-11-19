#pragma once
#include "auth_methods_struct.h"

auth_method::auth_method(std::string method_name_name, void(*change_func)())
{
	this->method_name_name = method_name_name;
	this->change_func = change_func;
}