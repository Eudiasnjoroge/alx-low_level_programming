#include <stdio.h>
#include <stdlib.h>

/**
 * main -  multiplies 2 numbers provided as command line arguments
 * @argc: the number of command line arguments
 * @argv: An array of pointer to the command line arguments
 *
 * Return: 0 on success, 1 on error.
 */

int main(int argc, char *argv[])
{
	int n1, n2, result;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	n1 = atoi(argv[1]);
	n2 = atoi(argv[2]);
	result = n1 * n2;

	printf("%d\n", result);
	return (0);
}
