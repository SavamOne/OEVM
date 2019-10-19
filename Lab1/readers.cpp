#include "readers.h"

using namespace std;


short choose_data_type(data_types* dtf, short size){
	short index = 0;
	char move;
	draw_menu(index, dtf, size);
	do 
	{
		move = _getch();

		if (move == 80 && index < size - 1)
		{
			index++;
			draw_menu(index, dtf, size);
		}
		else if (move == 72 && index >0)
		{
			index--;
			draw_menu(index, dtf, size);
		}

	} while (move != 13);
    system("cls");

	cout << "You choosed: " << dtf[index].data_type_name << endl;

	return index;
}

int choose_number_system()
{
	cout << "Enter number system" << endl;
	cout << "Number system must be in [2;" << symb2digit('z') + 1 << "]" << endl;
	int number;
	cin >> number;
	while (!cin || number < 2 || number > symb2digit('z') + 1)
	{
		cout << "Number system must be in [2;" << symb2digit('z') + 1 << "]. Try again" << endl;
		cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cin >> number;
	}
    return number;
}

string read_value(const int& ns, bool _signed)
{
	cout << "Enter number" << endl << "You can use: .+-";
	for(short i = 0; i < ns; i++)
	{
		cout << digit2symb(i);
	}
	cout << endl;


	char digit_char;
	string number = "";

	bool dot_placed = false;
    digit_char = _getch();

	while (digit_char != 13)
	{
		int digit_int = symb2digit(digit_char);
		if (digit_int < ns && (digit_int != -1 || (digit_char == '-' && _signed && number.size()== 0) || (digit_char == '+' && _signed && number.size()== 0) || (digit_char == '.' && !dot_placed)))
		{
			if(digit_char == '.' && !dot_placed) dot_placed = true;
            cout << digit_char;
			number += digit_char;
		}
		else if(digit_char == 8 && number.size())
		{
			cout << '\b' << ' ' << '\b';
			if(number[number.size() -1] == '.') dot_placed = false;
			number.erase(number.end()-1);
		}
		digit_char = _getch();
	}
    cout << endl;
	return number;
}

short choose_shift()
{
	cout << "Enter how many bits to shift" << endl;
	short res;
	cin >> res;
	while (!cin || res < 0)
	{
		cout << "You entered wrong number. Try again" << endl;
		cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> res;
	}
	return res;
}

bool choose_direction()
{
	cout << "Choose shift direction. Press <- or ->" << endl;
	char dir = _getch();
	do
	{
		dir = _getch();
	} while (dir != 77 && dir != 75);
	return dir == 77 ? 1 : 0;
}

short* choose_bits(bool* bits, short size)
{
	short start = 0, end = 7;
	
	char move;
	draw_bits(bits, size, start, end, 'd');
	do
	{
		move = _getch();
		if (move == 77 && end < size - 1)
		{
			start++; end++;
			draw_bits(bits, size, start, end, 'd');
		}
		else if (move == 75 && start > 0)
		{
			start--; end--;
			draw_bits(bits, size, start, end, 'd');
		}
		else if (move == 72 && end < size -1)
		{
			end++;
			draw_bits(bits, size, start, end, 'd');
		}
		else if (move == 80 && end > start +1)
		{
			end--;
			draw_bits(bits, size, start, end, 'd');
		}

	} while (move != 13);

	short* params = new short[2];
	params[0] = start;
	params[1] = end;

	return params;
}

short choose_action()
{
	short index = 0;
	char move;
	draw_choose_menu(index);
	do
	{
		move = _getch();

		if (move == 80 && index < 5 - 1)
		{
			index++;
			draw_choose_menu(index);
		}
		else if (move == 72 && index > 0)
		{
			index--;
			draw_choose_menu(index);
		}

	} while (move != 13);
	system("cls");

	return index;
}

colors choose_color(colors* clrs, short size, colors& second_color)
{
	colors* clrs_n = new colors[size - 4];
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (clrs[i].color_id != text_color.color_id 
		 && clrs[i].color_id != bit1_color.color_id 
	     && clrs[i].color_id != bit2_color.color_id 
		 && clrs[i].color_id != bg_color.color_id)
		{
			clrs_n[count] = clrs[i];
			count++;
		}
	}

	short index = 0;
	//if (clrs[index].color_id == second_color.color_id) index++;
	char move;
	draw_colors(index, clrs_n, count, second_color);
	do
	{
		move = _getch();

		if (move == 80 && index < count - 1)
		{
			index++;
			//if (clrs[index].color_id == second_color.color_id) index++;
			draw_colors(index, clrs_n, count, second_color);
		}
		else if (move == 72 && index > 0)
		{
			index--;
			//if (clrs[index].color_id == second_color.color_id) index--;
			draw_colors(index, clrs_n, count, second_color);
		}

	} while (move != 13 && move != 27);
	system("cls");
	set_bg_color(bg_color);
	cout << "You choosed: " << clrs_n[index].color_name << endl;
	
	colors ret = clrs_n[index];
	delete[] clrs_n;
	return ret;
}