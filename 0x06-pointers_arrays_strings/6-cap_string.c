#include "main.h"

/**
 * cap_string - capitalises all words of a string.
 * @str: The string to be capitalised
 * Return: A pointer to the changed string.
 */

char *cap_string(char *)
{
	int index = 0;

	while (i[index])
	{
		while (!(i[index] >= 'a' && i[index] <= 'z'))
			index++;
		if (i[index - 1] == ' ' ||
		i[index - 1] == '\t' ||
		i[index - 1] == '\n' ||
		i[index - 1] == ',' ||
		i[index - 1] == ';' ||
		i[index - 1] == '.' ||
		i[index - 1] == '!' ||
		i[index - 1] == '?' ||
		i[index - 1] == '-' ||
		i[index - 1] == '(' ||
		i[index - 1] == ')' ||
		i[index - 1] == '{' ||
		i[index - 1] == '}' ||
		index == 0)
			i[index] -= 32;
		index++;
	}
}

