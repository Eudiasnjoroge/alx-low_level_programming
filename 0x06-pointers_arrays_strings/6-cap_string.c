#include <stdio.h>

/**
 * is_lower - Checks if a character is a lowercase letter
 * @c: The character to check
 *
 * Return: 1 if the character is lowercase, 0 otherwise
 */
int is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

/**
 * to_upper - Converts a lowercase letter to uppercase
 * @c: The character to convert
 *
 * Return: The uppercase equivalent if c is lowercase, otherwise c
 */
char to_upper(char c)
{
	if (is_lower(c))
	{
		return c - 'a' + 'A';
	}

	return c;
}

#include "main.h"

/**
 * cap_string - capitalises all words of a string.
 * @str: The string to be capitalised
 * Return: A pointer to the changed string.
 */

char *cap_string(char *str)
{
	int i = 0;

	if (str[i] != '\0' && is_lower(str[i]))
	{
		str[i] = to_upper(str[i]);
	}

	while (str[i] != '\0')
	{
		if (str[i] == ' ' ||
		str[i] == '\t' ||
		str[i] == '\n' ||
		str[i] == ',' ||
		str[i] == ';' ||
		str[i] == '.' ||
		str[i] == '!' ||
		str[i] == '?' ||
		str[i] == '"' ||
		str[i] == '(' ||
		str[i] == ')' ||
		str[i] == '{' ||
		str[i] == '}')
		{
			if (str[i + 1] != '\0' && is_lower(str[i + 1]))
			{
				str[i + 1] = to_upper(str[i + 1]);
			}
		}
		i++;
	}

	return (str);
}

