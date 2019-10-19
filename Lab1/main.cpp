#include "data_types_config.h"
#include "colors_config.h"


using namespace std;

void main_acitivity()
{
	short dt_index = choose_data_type(dtf);
	dtf[dt_index].processing();
}

void choose_text_color()
{
	colors c = choose_color(cs, cs_count, bg_color);
	text_color = c;
	set_text_color(text_color);
}

void choose_bg_color()
{
	colors c = choose_color(cs, cs_count, bg_color);
	set_bg_color(c);
}

void choose_bit1_color()
{
	colors c = choose_color(cs, cs_count, bg_color);
	bit1_color = c;
}

void choose_bit2_color()
{
	colors c = choose_color(cs, cs_count, bg_color);
	bit2_color = c;
}


int main()
{
	dtf_init();
	set_bg_color(bg_color);

	while (true)
	{
		short action = choose_action();
		switch (action)
		{
			default:
				main_acitivity();
				break;

			case 1:
				choose_text_color();
				break;

			case 2:
				choose_bg_color();
				break;
		
			case 3:
				choose_bit1_color();
				break;

			case 4:
				choose_bit2_color();
				break;
		}
		cout << "--------" << endl << "Press Enter to begin again" << endl;
		while (_getch() != 13) {};
	}
	return 0;
}
