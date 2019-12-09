#include "config.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	if (!login())
	{
		std::cout << "--------" << std::endl << "Press Enter to exit" << std::endl;
		while (_getch() != 13) {};
		return -1;
	}

	std::cout << "--------" << std::endl << "Press Enter to continue" << std::endl;
	while (_getch() != 13) {};

 	init_dtf();
	init_colors();
	init_main_menu();
	init_auth_methods();

	console_handler::set_bg_color(bg_color);

	__asm
	{
		main_process_cycle:
	}

	console_handler::clear_console();
	console_handler::clear_console_buffer();

	menu[readers::choose_action()].action_func();
	std::cout << "--------" << std::endl << "Press Enter to continue or Ctrl + Q to exit" << std::endl;
		

	bool already_pressed = true;

	__asm
	{
		continue_or_exit:
	}

	if ((GetAsyncKeyState(VK_CONTROL) & GetAsyncKeyState(0x51)) == -32768)
		__asm
		{
			jmp program_end
		}
	else if (GetAsyncKeyState(VK_RETURN) == -32768 && !already_pressed)
		__asm
		{
			jmp main_process_cycle;
		}
	else if ((GetAsyncKeyState(VK_RETURN) == 0))
		already_pressed = false;

	__asm
	{
		jmp continue_or_exit

		program_end :
	}
}