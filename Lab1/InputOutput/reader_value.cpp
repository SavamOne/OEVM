#include "reader_value.h"

string readers::read_value(const int& ns, bool _signed)
{
	cout << "Enter number" << endl << "You can use: .+-";
	for (short i = 0; i < ns; i++)
	{
		cout << digit2symb(i);
	}
	cout << endl;

	char digit_char;
	string number = "";

	bool dot_placed = false;
	digit_char = _getch();

	while (digit_char != 13)
	{
		int digit_int = symb2digit(digit_char);
		if (digit_int < ns &&
			(
				digit_int != -1 ||
				(digit_char == '-' && _signed && number.size() == 0) ||
				(digit_char == '+' && _signed && number.size() == 0) ||
				(digit_char == '.' && !dot_placed)
				))
		{
			if (digit_char == '.' && !dot_placed) dot_placed = true;
			cout << digit_char;
			number += digit_char;
		}
		else if (digit_char == 8 && number.size())
		{
			cout << '\b' << ' ' << '\b';
			if (number[number.size() - 1] == '.') dot_placed = false;
			number.erase(number.end() - 1);
		}
		digit_char = _getch();
	}
	cout << endl;
	return number;
}