#include "main.h"

/**
 * _puts - function that prints a string
 * @str: string to be printe
 * Return: void
 */

void _puts(char *str)
{
	int i;

	for (i = 0 ; str[i] != '\0' ; i++)
		_putchar(str[i]);
	_putchar('\n');
}
