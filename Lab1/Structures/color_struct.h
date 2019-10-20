#pragma once
#include<string>

struct color
{
	int color_id;
	std::string color_name;

	color(const std::string& color_name, int color_id);

	color() = default;
};