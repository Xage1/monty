#include "monty.h"

/**
 * func_swap - swaps the top two elements of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */

void func_swap(stack_t **head, unsigned int counter)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next;
	(*head)->next = temp->next;

	if (temp->next != NULL)
		temp->next->prev = *head;

	temp->next = *head;
	temp->prev = NULL;

	*head = temp;
}
