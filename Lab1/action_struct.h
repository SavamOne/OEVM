#pragma once
#include <string>

struct action
{
	std::string action_name;
	void(*action_func)();

	action(std::string action_name, void(*action_func)());
	action() = default;
};

