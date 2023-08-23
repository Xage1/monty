#include "monty.h"

/**
 * func_pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: pointer to stack
 * @counter: line_number
 */
void func_pchar(stack_t **stack, unsigned int counter)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127) // Check if value is out of ascii range
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	putchar((*stack)->n);
	putchar('\n');
}
