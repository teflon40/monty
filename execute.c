#include "monty.h"

/**
 * ExecuteOpcode - Handles opcode execution
 *
 * @stack: stack
 * @line_number: current line number.
 */
void ExecuteOpcode(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t cmd[] = {
		{"push", Push},
		{"pall", Pall},
		{"add", Add},
		{"pop", Pop},
		{"pint", Pint},
		{"nop", nop},
		{"swap", Swap},
		{"sub", Sub},
		{"div", Div},
		{"mul", Mul},
		{"mod", Mod},
		{"stack", Stack},
		{"queue", Queue},
		{"rotr", Rotr},
		{"rotl", Rotl},
		{"pstr", Pstr},
		{"pchar", Pchar},
		{NULL, NULL}};

	i = 0;
	while (cmd[i].opcode != NULL)
	{
		if (strcmp(cmd[i].opcode, Input.Bytecodes[0]) == 0)
		{
			cmd[i].f(stack, line_number);
			return;
		}
		i++;
	}
	ErrExit(*stack, "L%d: unknown instruction %s\n",
			line_number, Input.Bytecodes[0]);
}
