#include "monty.h"

/**
 * op_queue - set to queue mode
 * @stack: unused
 * @line_number: unused
 */
void op_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	mem.mode = QUEUE;
}
