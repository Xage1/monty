#include "monty.h"

/**
 * func_mod - computes the remainder of division of the second top element
 *            of the stack by the top element
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */

void func_mod(stack_t **head, unsigned int counter)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next;

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp->n %= (*head)->n;

	*head = temp;
	temp->prev = NULL;

	free(*head);
}
