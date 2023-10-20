#include "monty.h"

/**
 * Add - performs addition operations
 *
 * @stack: a stack.
 * @number: line number.
 */
void Add(stack_t **stack, unsigned int number)
{
	int sum;

	if (stackLen(*stack) < 2)
		ErrExit(*stack, "L%d: can't add, stack too short\n", number);

	sum = fpop(stack) + fpop(stack);
	fpush(stack, sum);
}

/**
 * Sub - performs subtraction operations
 *
 * @stack: a stack.
 * @number: line number.
 */
void Sub(stack_t **stack, unsigned int number)
{
	int difference, tmp;

	if (stackLen(*stack) < 2)
		ErrExit(*stack, "L%d: can't sub, stack too short\n", number);

	tmp = fpop(stack);
	difference = fpop(stack) - tmp;
	fpush(stack, difference);
}
