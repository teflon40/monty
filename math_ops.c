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
