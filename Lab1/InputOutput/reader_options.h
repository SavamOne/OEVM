#ifndef READERS_H
#define READERS_H

#include <string>
#include <iostream>
#include <conio.h>
#include <limits>

#include"../VeryImportantFuncs/symb2digit.h"

using namespace std;

namespace readers
{
	int choose_number_system();
	short choose_shift();
	bool choose_direction();
}


#endif //READERS_H