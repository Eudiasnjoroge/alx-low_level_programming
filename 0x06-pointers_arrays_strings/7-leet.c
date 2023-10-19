#include "main.h"

/**
 * leet - Encodes a string into "1337".
 * @str: The string to be encoded.
 *
 * Return: A pointer to the encoded string.
 */
char *leet(char *str)
{
	char *p = str;

	while (*p)
	{
		if ((*p == 'a' || *p == 'A') ||
		(*p == 'e' || *p == 'E') ||
		(*p == 'o' || *p == 'O') ||
		(*p == 't' || *p == 'T') ||
		(*p == 'l' || *p == 'L'))

		{
			if (*p == 'a' || *p == 'A')
			{
				*p = '4';
			}
			else if (*p == 'e' || *p == 'E')
			{
				*p = '3';
			}
			else if (*p == 'o' || *p == '0')
			{
				*p = '0';
			}
			else if (*p == 't' || *p == 'T')
			{
				*p = '7';
			}
			else if (*p == 'l' || *p == 'L')
			{
				*p = '1';
			}
		}
		p++;
	}
	 return str;
}
