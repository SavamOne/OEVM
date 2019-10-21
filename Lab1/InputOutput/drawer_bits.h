#pragma once

#include "../VeryImportantFuncs/console_handler.h"

namespace drawers
{
	void draw_bit(bool bit, short i, char mode, short start, short end, short step);

	void draw_bits(bool* bits, short size, char mode = 's', short start = -1, short end = -1, short step = 0);
	void draw_bits_ticker(bool* bits, short size, char mode = 's', short start = -1, short end = -1, short step = 0);
}