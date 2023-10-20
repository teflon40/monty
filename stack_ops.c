#include "monty.h"

/**
 * Push - pushes to stack;
 *
 * @stack: stack
 * @number: line_number
 */
void Push(stack_t **stack, unsigned int number)
{
	int value;

	if (Input->Bytecodes[1] == NULL || isNum(Input->Bytecodes[1]) == FALSE)
		ErrExit(*stack, "L%d: usage: push integer\n", number);

	value = atoi(Input->Bytecodes[1]);
	switch (Input->Mode)
	{
		case STACK_MODE:			/* Operate in stack mode */
			if (fpush(stack, value) == NULL)
				ErrExit(*stack, "Error: malloc failed\n");
			break;
		case QUEUE_MODE:			/* Operate in queue mode */
			if (enqueue(stack, value) == NULL)
				ErrExit(*stack, "Error: malloc failed\n");
			break;
	}
}

/**
 * Pop - pops from stack.
 *
 * @stack: a stack.
 * @number: line number.
 */
void Pop(stack_t **stack, unsigned int number)
{
	if (isEmpty(*stack))
		ErrExit(*stack, "L%d: can't pop an empty stack\n", number);
	fpop(stack);
}
