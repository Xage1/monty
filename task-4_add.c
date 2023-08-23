#include "monty.h"

/**
 * func_add - adds the top two elements of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */

void func_add(stack_t **head, unsigned int counter)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next;
	temp->n += (*head)->n;

	*head = temp;
	temp->prev = NULL;

	free(*head);
}
