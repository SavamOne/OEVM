#include "config.h"

int main()
{
	init_dtf();
	init_colors();
	init_actions();

	set_bg_color(bg_color);

	while (true)
	{
		short action = readers::choose_action();
		actions[action].action_func();
		std::cout << "--------" << std::endl << "Press Enter to begin again" << std::endl;
		while (_getch() != 13) {};
	}
	return 0;
}
