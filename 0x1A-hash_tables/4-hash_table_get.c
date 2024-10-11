#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key
 * @ht: hash table to be looked into
 * @key: key looked for
 *
 * Return: vallue associated with the element, NULL if key is not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *node;

	if (!ht || !key || strcmp(key, "") == 0)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);

	node = ht->array[index];
	while (node)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}
	return (NULL);
}
