#include "reader_bits.h"

short* readers::choose_bits(bool* bits, short size)
{
	short start = 0, end = 7;

	char move;
	drawers::draw_bits(bits, size, 'd', start, end);
	do
	{
		move = _getch();
		if (move == 77 && end < size - 1)
		{
			start++; end++;
			drawers::draw_bits(bits, size, 'd', start, end);
		}
		else if (move == 75 && start > 0)
		{
			start--; end--;
			drawers::draw_bits(bits, size, 'd', start, end);
		}
		else if (move == 72 && end < size - 1)
		{
			end++;
			drawers::draw_bits(bits, size, 'd', start, end);
		}
		else if (move == 80 && end > start + 1)
		{
			end--;
			drawers::draw_bits(bits, size, 'd', start, end);
		}

	} while (move != 13);

	short* params = new short[2];
	params[0] = start;
	params[1] = end;

	return params;
}