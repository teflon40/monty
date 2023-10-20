#include "monty.h"

/**
 * FreeBytecodes - frees bytecodes
 */
void FreeBytecodes(void)
{
	size_t i;

	for (i = 0; Input->Bytecodes[i]; i++)
		free(Input->Bytecodes[i]);
	free(Input->Bytecodes);
}

/**
 * FreeStack - frees stack.
 *
 * @stack: stack.
 */
void FreeStack(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
