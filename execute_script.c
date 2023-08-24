#include "monty.h"

/**
 * execute_script - Executes the Monty bytecode script based on the given mode.
 * @mem: Pointer to an 'allocated_t' structure representing the memory state.
 *
 * This function executes the Monty bytecode script based on the mode stored
 * in the 'mem' structure. If the mode is STACK, it prints a message indicating
 * stack mode execution. If the mode is QUEUE, it prints a message indicating
 * queue mode execution.
 */
void execute_script(allocated_t *mem)
{
	char line[1024];
	int i;
	unsigned int line_number = 0;
	instruction_t ops[] = {
		{"push", stack_push}, {"pall", stack_pall}, {"pint", stack_pint},
		{"pop", stack_pop}, {"swap", stack_swap}, {"add", stack_add},
		{"nop", stack_nop}, {"sub", stack_sub}, {"div", stack_div},
		{"mul", stack_mul}, {"mod", stack_mod}, {"pchar", stack_pchar},
		{"pstr", stack_pstr}, {"rotl", stack_rotl}, {"rotr", stack_rotr},
		{"stack", op_stack}, {"queue", op_queue},
		{NULL, NULL}
		};
		stack_t *stack = NULL;

		while (fgets(line, sizeof(line), mem->pScript) != NULL)
		{
			line_number++;

		/* Finds opcode in ops[] */
		mem->token = strtok(line, " \n");
		if (mem->token == NULL || mem->token[0] == '#')
		continue;

		for (i = 0; ops[i].opcode != NULL; i++)
		{
			if (strcmp(ops[i].opcode, mem->token) == 0)
			{
				mem->n = strtok(NULL, " \n");
				ops[i].f(&stack, line_number);
				break;
			}
		}
		if (ops[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, mem->token);
			free_all(stack);
			exit(EXIT_FAILURE);
		}
	}
	free_all(stack);
}
