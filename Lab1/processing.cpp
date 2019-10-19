#include "processing.h"

void processing_char()
{
	cout << "Enter symbol" << endl;
	char symbol = _getch();
	cout << symbol << endl;

	bool* bits = pseudo_record_in_memory(symbol);

	draw_bits(bits, 8, -1, -1, 's');

	cout << "--------" << endl << "Press Enter to continue" << endl;
	while (_getch() != 13) {};

	processing_shift(bits, symbol);
	delete[] bits;
}