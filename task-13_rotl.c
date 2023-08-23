#include "monty.h"

/**
 * func_rotl - rotates the stack to the top.
 * @stack: pointer to stack
 * @counter: line_number
 */
void func_rotl(stack_t **stack, unsigned int counter)
{
	(void)counter; // Unused parameter

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
