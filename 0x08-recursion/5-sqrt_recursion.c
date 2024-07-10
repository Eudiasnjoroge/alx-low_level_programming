#include "main.h"
#include <stdio.h>

/**
 * _sqrt_helper - Helper function to find the natural square root
 * @n: The number to find the square root of
 * @guess: The current guess for the square root
 *
 * Return: The natural square root of n, or -1 if n does not have one
 */
int _sqrt_helper(int n, int guess)
{
	if (guess * guess > n)
		return (-1);
	if (guess * guess == n)
		return (guess);
	return (_sqrt_helper(n, guess + 1));
}

/**
 * _sqrt_recursion - calculates natural square root
 * @n: number to calculate the square root
 *
 * Return: the natural square root
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return  (-1);
	return (_sqrt_helper(n, 0));
}
