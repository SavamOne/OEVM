#pragma once

#include "../Structures/byte_union.h"
#include "../VeryImportantFuncs/symb2digit.h"

namespace main_processes
{
	template <class T>
	T cyclic_shift(bool* bits, short start, short end, short step)
	{
		__asm
		{
			mov ax, step
			test ax, ax
			jle step_is_lower_than_zero
		}
		//if (step > 0)
		//{
			my_reverse(bits, start, start + step - 1);
			my_reverse(bits, start + step, end);
			my_reverse(bits, start, end);
		//}
		__asm
		{
			step_is_lower_than_zero:
		}

		bytes<T> st;
		st.value = 0;

		for (int i = 0; i < sizeof(T) * 8; i++)
		{
			short bytenum = sizeof(T) - (i / 8) - 1;
			char bit = bits[i];
			short shift = (7 - i % 8);

			st.byte[bytenum] |= (bit << shift);
		}

		return st.value;
	}
}