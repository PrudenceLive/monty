#include "monty.h"

/**
 * op_stack - set to stack mode
 * @stack: unused
 * @line_number: unused
 */
void op_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	mem.mode = STACK;
}
