#pragma once
#include<string>

struct color
{
	int color_id;
	std::string color_name;
	short R, G, B;

	color(const std::string& color_name, int color_id, short R, short G, short B);

	color() = default;
};