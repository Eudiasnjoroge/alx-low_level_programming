#include "main.h"

/**
 * leet - encodes a string into "1337".
 * @str: The string to be coded
 *
 * Return: a pointer to the encoded string
 */

char *leet(char *)
{
	char *p = str;

	while (*p)
	{
		char c = *p;
		if ((c == 'a' || c == 'A') || (c == 'e' || c == 'E') || (c == 'o'))

		{
			switch (c)
			{
				case 'a';
				case 'A':
				*p = '4';
					break;
				case 'e':
				case 'E':
					*p = '3';
					break;
				case 'o':
				case 'O':
					*p = '0';
					break;
				case 'l':
				case 'L':
					*p = '1';
					break;
			}
		}
		p++;
	}
}
