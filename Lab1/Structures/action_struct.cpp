#include "action_struct.h"

action::action(std::string action_name, void(*action_func)())
{
	this->action_name = action_name;
	this->action_func = action_func;
}
