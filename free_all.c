#include "monty.h"

/**
 * free_all - frees all allocated memory
 * @stack: pointer to linked list
 */
void free_all(stack_t *stack)
{
stack_t *delete = stack;

	while (stack)
	{
		stack = stack->next;
		free(delete);
		delete = stack;
	}

	free(mem.token);
	fclose(mem.pScript);
}
