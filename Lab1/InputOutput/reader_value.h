#pragma once

#include <string>
#include <iostream>
#include <conio.h>
#include <limits>

#include "../VeryImportantFuncs/symb2digit.h"

using namespace std;

namespace readers
{
	string read_value(const int& ns, bool _signed);
}