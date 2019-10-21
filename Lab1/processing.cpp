#include "processing.h"

void processing_char()
{
	cout << "Enter symbol" << endl;
	char symbol = _getch();
	cout << symbol << endl;

	bool* bits = main_processes::pseudo_record_in_memory(symbol);

	drawers::draw_bits(bits, 8);

	if (symbol != 0)
	{
		char res;
		cout << "--------" << endl << "Press Enter to continue or ESC to finish" << endl;
		res = _getch();
		while (res != 13 && res != 27) { res = _getch(); };

		if (res == 13)
			processing_shift(bits, symbol);
	}
	delete[] bits;
}