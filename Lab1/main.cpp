#include "config.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	if (!login())
	{
		system("pause");
		return -1;
	}

	system("pause");
	system("cls");

 	init_dtf();
	init_colors();
	init_main_menu();
	init_auth_methods();

	console_handler::set_bg_color(bg_color);

	while (true)
	{
		menu[readers::choose_action()].action_func();
		std::cout << "--------" << std::endl << "Press Enter to begin again" << std::endl;
		while (_getch() != 13) {};
		system("cls");
	}
}
