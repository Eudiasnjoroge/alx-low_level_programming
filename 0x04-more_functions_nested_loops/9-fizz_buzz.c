#include <stdio.h>

/**
 * main - main function
 * Return: 0;
 */

int main(void)
{
	int i;

	for (i = 1 ; i <= 100 ; i++)
	{
		if (i % 15 == 0)
		{
			printf("%s", "Fizzbuzz");
			if (i != 100)
			{
				printf(" ");
			}
		}
		else if (i % 3 == 0)
		{
			printf("%s", "Fizz");
			if (i != 100)
			{
				printf(" ");
			}
		}
		else if (i % 5 == 0)
		{
			printf("%s", "Buzz");
			if (i != 100)
			{
				printf(" ");
			}
		}
		else
		{
			printf("%d", i);
			if (i !=100)
			{
				printf(" ");
			}
		}

	}
	printf("\n");
		return (0);
}
