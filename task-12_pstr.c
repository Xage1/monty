#include "monty.h"

/**
 * func_pstr - prints the string starting at the top of the stack, followed by a new line.
 * @stack: pointer to stack
 * @counter: line_number
 */

void func_pstr(stack_t **stack, unsigned int counter)
{
	stack_t *current = *stack;

	while (current != NULL && current->n != 0 && current->n >= 0 && current->n <= 127)
	{
		if (isascii(current->n))
			putchar(current->n);
		else
			break;
		current = current->next;
	}
	putchar('\n');
	(void)counter;
}

