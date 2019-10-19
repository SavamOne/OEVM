#include "symb2digit.h"

short symb2digit(char symb)
{
	if (symb >= '0' && symb <= '9')
		return symb - '0';
	else if (symb >= 'A' && symb <= 'Z')
		return symb - '0' - 7;
	else if (symb >= 'a' && symb <= 'z')
		return symb - '0' - 7 - 6;
	return -1;
}

char digit2symb(short digit)
{
	if(digit >= 0 && digit <= 9)
	{
		return (char)digit + '0';
	}
	if(digit >= symb2digit('a') && digit <= symb2digit('z'))
	{
		return (char)digit + 6 + 7 + '0';
	}
		if(digit >= symb2digit('A') && digit <= symb2digit('Z'))
	{
		return (char)digit + 7 + '0';
	}
	return '\0';
}

void my_reverse(bool* arr, short start, short end)
{
	for (int i = 0; i <= (end - start) / 2; i++)
	{
		std::swap(arr[start + i], arr[end - i]);
	}
}