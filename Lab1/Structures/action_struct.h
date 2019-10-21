#pragma once
#include <string>

struct main_menu
{
	std::string action_name;
	void(*action_func)();

	main_menu(std::string action_name, void(*action_func)());
	main_menu() = default;
};

