#include "monty.h"

/**
 * func_pop - removes the top element of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */

void func_pop(stack_t **head, unsigned int counter)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	*head = temp->next;
	free(temp);
}
