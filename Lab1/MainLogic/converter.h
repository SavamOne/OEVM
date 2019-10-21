#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>
#include <limits>

#include "../VeryImportantFuncs/symb2digit.h"

using namespace std;

namespace main_processes
{
	namespace
	{
		template <class T>
		T pow(T num, int ns)
		{
			T res = 1;
			for (int i = 0; i < ns; i++)
			{
				res *= num;
			}
			return res;
		}

		template <class T>
		T logic(const string& num, const unsigned short& ns, bool& exceed)
		{
			T res = 0;
			exceed = false;
			for (unsigned long long i = num.length(); i > 0; i--)
			{
				long double degree = 0;
				short digit = symb2digit(num[i - 1]);
				if (digit != 0)
					degree = pow<T>(ns, (num.length() - i));
				T res_old = res;
				res += degree * digit;
				if (!exceed && res < res_old)
				{
					exceed = true;
				}
			}
			return res;
		}

		template <class T>
		T logic_inverse(const string& num, const unsigned short& ns)
		{
			T res = 0;
			for (unsigned long long i = 1; i <= num.length(); i++)
			{
				T step = pow(ns, i);
				short digit = symb2digit(num[i - 1]);
				if (digit != 0)
					res += digit * (step ? 1.0 / step : 0.0);
			}
			return res;
		}
	}

	template <class T>
	T convert2decimal(const string& num, const unsigned short& ns, bool &exceed_max_value)
	{
		bool is_neg = (num[0] == '-');
		bool is_pos = (num[0] == '+');
		bool start_index = (is_neg || is_pos);
		short split_index = num.find('.');
		T res;

		if (split_index == -1)
			res = logic<T>(num.substr(start_index), ns, exceed_max_value);
		else
		{
			T int_value = logic<T>(num.substr(start_index, split_index - start_index), ns, exceed_max_value);
			T frac_value = logic_inverse<T>(num.substr(split_index + 1), ns);

			res = T(int_value) + frac_value;
		}
		return is_neg ? res * (-1) : res;
	}
}



#endif //CONVERTER_H