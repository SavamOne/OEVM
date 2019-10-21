#include "reader_options.h"

int readers::choose_number_system()
{
	cout << "Enter number system" << endl;
	cout << "Number system must be in [2;" << symb2digit('z') + 1 << "]" << endl;
	int number;
	cin >> number;
	while (!cin || number < 2 || number > symb2digit('z') + 1)
	{
		cout << "Number system must be in [2;" << symb2digit('z') + 1 << "]. Try again" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> number;
	}
    return number;
}

short readers::choose_shift()
{
	cout << "Enter how many bits to shift" << endl;
	short res;
	cin >> res;
	while (!cin || res < 0)
	{
		cout << "You entered wrong number. Try again" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> res;
	}
	return res;
}

bool readers::choose_direction()
{
	cout << "Choose shift direction. Press <- or ->" << endl;
	char dir = _getch();
	do
	{
		dir = _getch();
	} while (dir != 77 && dir != 75);
	return dir == 77 ? 1 : 0;
}