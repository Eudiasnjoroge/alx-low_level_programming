#include "main.h"
#include <stdio.h>
/**
 * times_table - prints the 9 times table, starting wih 0
 * Return: void
 */
void times_table(void)
{
	int i, j, product;

	for (i = 0 ; i <= 9 ; i++)
	{
		for (j = 0 ; j <= 9 ; j++)
		{
			product = i * j;
			if (j != 0)
			{
				_putchar(',');
				_putchar(' ');
				if (product < 10)
					_putchar(' ');
			}
			_putchar(product < 10 ? product + '0' : (product / 10) + '0');

			if (product >= 10)
				_putchar((product % 10) + '0');
		}
		_putchar('\n');
	}
}
