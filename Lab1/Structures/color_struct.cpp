#include "color_struct.h"

color::color(const std::string& color_name, int color_id, short R, short G, short B)
{
	this->color_id = color_id;
	this->color_name = color_name;
	this->R = R;
	this->G = G;
	this->B = B;
}

