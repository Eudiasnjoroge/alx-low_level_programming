#include "lists.h"
#include <stdio.h>
#include <stddef.h>

/**
 * print_list - prints all elements of a list_t list
 * @h: pointer to the head of the list_t list
 *
 * Return: number of nodes
 */

size_t print_list(const list_t *h)
{
	size_t nodes;

	nodes = 0;
	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
		h = h->next;
		nodes++;
	}
	return (nodes);
}
