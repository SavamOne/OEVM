#ifndef PSEUDO_RECORD_H
#define PSEUDO_RECORD_H
#include "../Structures/byte_union.h"

namespace main_processes
{
	template <class T>
	bool* pseudo_record_in_memory(T value)
	{
		bytes<T> st;
		st.value = value;

		bool* bits = new bool[sizeof(T) * 8];

		for (int i = sizeof(T) - 1; i >= 0; i--)
		{
			for (int j = 7; j >= 0; j--)
			{
				bool bit = ((st.byte[i] >> j) & 1);
				bits[(sizeof(T) - i - 1) * 8 + (8 - j - 1)] = bit;
			}
		}
		return bits;
	}
}
#endif //PSEUDO_RECORD_H