#pragma once

template <class T>
union bytes
{
	T value;
	char byte[sizeof(T)];
};