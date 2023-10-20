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

/**
 * Mul - performs multiplication operations
 *
 * @stack: a stack.
 * @number: line number.
 */
void Mul(stack_t **stack, unsigned int number)
{
	int product;

	if (stackLen(*stack) < 2)
		ErrExit(*stack, "L%d: can't mul, stack too short\n", number);

	product = fpop(stack) * fpop(stack);
	fpush(stack, product);
}

/**
 * Div - performs division operations
 *
 * @stack: a stack.
 * @number: line number.
 */
void Div(stack_t **stack, unsigned int number)
{
	int top;
	int quotient;

	if (stackLen(*stack) < 2)
		ErrExit(*stack, "L%d: can't div, stack too short\n", number);
	if (getTop(*stack) == 0)
		ErrExit(*stack, "L%d: division by zero\n", number);

	top = fpop(stack);
	quotient = fpop(stack) / top;
	fpush(stack, quotient);
}

/**
 * Mod - performs modulus operations
 *
 * @stack: a stack.
 * @number: line number.
 */
void Mod(stack_t **stack, unsigned int number)
{
	int top;
	int remainder;

	if (stackLen(*stack) < 2)
		ErrExit(*stack, "L%d: can't mod, stack too short\n", number);
	if (getTop(*stack) == 0)
		ErrExit(*stack, "L%d: division by zero\n", number);

	top = fpop(stack);
	remainder = fpop(stack) % top;
	fpush(stack, remainder);
}
