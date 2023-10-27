#include <stdio.h>
#include <stdlib.h>

/**
 * main -  multiplies 2 numbers
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 1 on error.
 */

int main(int argc, char *argv[])
{
	int n1 = atoi(argv[1]), n2 = atoi(argv[2]);
	int n3 = n1 * n2;

	if (argc == 3)
	{
		printf("%d\n", n3);
	}
	else
	{
		printf("Error\n");
		return (1);
	}

	return (0);
}
