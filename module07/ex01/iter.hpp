#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>

void iter(T *array, size_t length, void (*func)(T &))
{
	if (!array)
		return;
	for (size_t i = 0; i < length; i++)
	{
		func(array[i]);
	}
}


template <typename T>

void iter(const T *array, size_t length, void (*func)(const T &))
{
	if (!array)
		return;
	for (size_t i = 0; i < length; i++)
	{
		func(array[i]);
	}
}

#endif