#pragma once

#include <string>

struct auth_method
{
	std::string method_name_name;
	void(*change_func)();

	auth_method(std::string method_name_name, void(*change_func)());
	auth_method() {};
};
