#include "monty.h"

/**
 * stack_sub - subtracts the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 */
void stack_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *delete = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	(*stack)->next->prev = NULL;
	*stack = (*stack)->next;
	free(delete);
}
