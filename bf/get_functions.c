#include "monty.h"

/**
 * get_functions - selects the correct opcode to perform
 * @opcd: opcode passed
 * Return: pointer to the function that executes the opcode
 */

void (*get_functions(char *opcd))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", push_f},
		{"pall", pall_f},
		{"pint", pint_f},
		{"pop", pop_f},
		{"swap", swap_f},
		{"queue", queue_f},
		{"stack", stack_f},
		{"add", add_f},
		{"nop", nop_f},
		{"sub", sub_f},
		{"mul", mul_f},
		{"div", div_f},
		{"mod", mod_f},
		{"pchar", pchar_f},
		{"pstr", pstr_f},
		{"rotl", rotl_f},
		{"rotr", rotr_f},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (_strcmp(instruct[i].opcode, opcd) == 0)
			break;
	}

	return (instruct[i].f);
}
