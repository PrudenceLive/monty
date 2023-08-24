#include "monty.h"

/**
 * stack_pstr - prints a string starting at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 */
void stack_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	(void)line_number;
	while (curr != NULL && curr->n >= 32 && curr->n <= 127)
	{
		printf("%c", curr->n);
		curr = curr->next;
	}
	putchar('\n');
}
