#include "main.h"

/**
 * print_triangle - prints triangles using '#' character
 * @size: size of the triangle
 * Return: void
 */

void print_triangle(int size)
{
	if (size <= 0)
		_putchar('\n');
	else
	{
		int i;
		int j;

		for (i = 1 ; i <= size; i++)
		{
			for (j = size - i ; j > 0 ; j--)
				_putchar(' ');
			_putchar('\n');
		}
	}
}
