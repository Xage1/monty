#include "monty.h"

/**
 * func_push - pushes an element to the stack
 * @head: stack head
 * @value: value to push
 * Return: no return
 */

void func_push(stack_t **head, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head != NULL)
		(*head)->prev = new_node;

	*head = new_node;
}

/**
 * func_pall - prints all values on the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */

void func_pall(stack_t **head, unsigned int counter)
{
	stack_t *temp = *head;

	(void)counter;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
