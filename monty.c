#include "monty.h"


/**
 * main - Opens a Monty bytecode file and executes it.
 * @argc: Number of arguments, should be 2.
 * @argv: Array of command line arguments, should contain path to monty script.
 * Return: Success(0), Error(EXIT_FAILURE).
 */

allocated_t mem;

int main(int argc, char const *argv[])
{
	allocated_t mem;

	mem.mode = STACK;

	/* Checks for file arguments */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	/* defaults format mode to stack */
	mem.mode = STACK;

	/* Attempts to open the file */
	mem.pScript = fopen(argv[1], "r");
	if (mem.pScript == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	/* Executes the monty bytecode script */
	execute_script(&mem);
	fclose(mem.pScript);
	return (0);
}
