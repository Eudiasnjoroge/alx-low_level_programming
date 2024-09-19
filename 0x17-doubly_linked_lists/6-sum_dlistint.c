#include "lists.h"

/**
 * sum_dlistint - returns the sum of all the data (n) of dlistint_t linked list
 *
 * @head: head of the list
 * Return: sum of all the data (n), otherwise return 0
 */
int sum_dlistint(dlistint_t *head)
{
	int i;

	i = 0;

	if (head != NULL)
	{
		while (head->prev != NULL)
			head = head->prev;

		while (head != NULL)
		{
			i += head->n;
			head = head->next;
		}
	}
	return (i);
}
