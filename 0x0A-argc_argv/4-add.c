#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * check_num - check sring
 * @str: array str
 *
 * Return: ALways 0 (success)
 */
int check_num(char *str)
{
	unsigned int count;

	count = 0;
	while (count < strlen(str))
	{
		if (isdigit(str[count]))
		{
			return (0);
		}
		count++;
	}
	return (1);
}

/**
 * main - Adds positive numbers provided as command line arguments
 * @argc: The number of command line arguments
 * @argv: An array of pointers to the command line arguments
 *
 * Return: 0 if the program runs successfully,1 if otherwise
 */
int main(int argc, char *argv[])
{
	int count;
	int str_to_int;
	int sum = 0;

	count = 1;
	while (count < argc)
	{
		if (check_num(argv[count]))
		{
			str_to_int = atoi(argv[count]);
			sum += str_to_int;
		}
		else
		{
			printf("Error\n");
			return (1);
		}
		count++;
	}

	printf("%d\n", sum);
	return (0);
}

