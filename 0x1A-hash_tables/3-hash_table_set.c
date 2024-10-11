#include "hash_tables.h"

/**
 * hash_table_set - adds an element to hash table
 * @key: key
 * @ht: hash table to be added
 * @value: value associated with the key
 *
 * Return: 1 if succeeded, 0 if otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node;
	unsigned long int index;
	char *value_copy;

	if (!ht || !key || strcmp(key, "") == 0)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	value_copy = strdup(value);
	if (!value_copy)
		return (0);

	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
	{
		free(value_copy);
		return (0);
	}

	new_node->key = strdup(key);
	if (!new_node->key)
	{
		free(new_node);
		free(value_copy);
		return (0);
	}
	new_node->value = value_copy;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
