#include "main.h"

/**
 * check_prime - Check if number is prime
 * @n: the number to be checked
 * @i: the iteration times
 *
 * Return: 1 for prime or 0 composite
 */

int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	if (n % i == 0 && i > 1)
		return (0);
	if ((n / i) < i)
		return (1);
	return (check_prime(n, i + 1));
}
