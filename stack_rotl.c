#include "monty.h"

/**
 * stack_rotl - rotates the stack to the top
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 */
void stack_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *end = *stack;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	return;

	while (end->next != NULL)
		end = end->next;

	end->next = *stack;
	(*stack)->prev = end;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
