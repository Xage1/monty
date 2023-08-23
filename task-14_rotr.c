#include "monty.h"

/**
 * func_rotr - rotates the stack to the bottom.
 * @stack: pointer to stack
 * @counter: line_number
 */
void func_rotr(stack_t **stack, unsigned int counter)
{
	(void)counter;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	stack_t *last = *stack;
	stack_t *second_last = NULL;

	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}

	last->next = *stack;
	*stack = last;
	second_last->next = NULL;
}
