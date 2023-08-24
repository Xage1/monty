#include "monty.h"

/**
 * addnode - Add a new node to the stack.
 * @n: The integer value to store in the new node.
 */

void addnode(int n)
{
	stack_t *head = NULL;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = head;
	head = new_node;
}
