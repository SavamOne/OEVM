#pragma once
template<class T>
class container
{
	T* arr;
	int arr_size;

	void reallocate(int how)
	{
		T* arr_new = new T[arr_size + how];
		for (int i = 0; i < arr_size; i++)
		{
			arr_new[i] = arr[i];
		}
		delete[] arr;
		arr = arr_new;
		arr_size += how;
	}

public:
	int size;

	container()
	{
		size = 0;
		arr = new T[8];
		arr_size = 8;
	}

	void append(T value)
	{
		if (arr_size == size)
			reallocate(5);

		arr[size] = value;
		size++;
	}

	T& operator[] (int index)
	{
		return arr[index];
	}

	~container()
	{
		delete[] arr;
		arr_size = size = 0;
	}
};