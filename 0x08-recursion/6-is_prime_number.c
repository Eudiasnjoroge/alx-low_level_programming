#include "main.h"
#include <stdio.h>

/**
 * _is_prime_helper - Helper function to check if a number is prime
 * @n: The number to check
 * @divisor: The current divisor to test
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int _is_prime_helper(int n, int divisor)
{
	if (n <= 1)
		return (0);
	if (divisor == 1)
		return (1);
	if (n % divisor == 0)
		return (0);
	return (_is_prime_helper(n, divisor - 1));
}

/**
 * is_prime_number - Returns 1 if the input integer is a prime number
 * @n: the number to be checked
 *
 * Return: 1 for prime or 0 otherwise
 */

int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (_is_prime_helper(n, n / 2));
}
