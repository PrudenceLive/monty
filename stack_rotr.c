#include "monty.h"

/**
 * stack_rotr - rotates the stack to the bottom
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 */
void stack_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *end = *stack;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (end->next != NULL)
	end = end->next;
	end->next = *stack;
	(*stack)->prev = end;
	end->prev->next = NULL;
	end->prev = NULL;
	*stack = end;
}
