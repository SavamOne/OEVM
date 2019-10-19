#pragma once
#include<string>

using namespace std;

struct colors
{
	int color_id;
	string color_name;

	colors(const string& color_name, int color_id);

	colors() = default;
};