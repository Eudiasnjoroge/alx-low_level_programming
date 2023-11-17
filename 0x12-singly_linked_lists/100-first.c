#include <stdio.h>

void first(void) __attribute__ ((constructor));

/**
 * first -  prints a sentencebefore the main
 * funtion is executed
 */

void first(void)
{
	printf("You're beat! and yet, you mustallow,\n");
	printf("I bore my house upon my back!\n");
}
