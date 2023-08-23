#include "monty.h"

/**
 * func_mul - multiplies the second top element of the stack with the top one
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */

void func_mul(stack_t **head, unsigned int counter)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next;
	temp->n *= (*head)->n;

	*head = temp;
	temp->prev = NULL;

	free(*head);
}
