#include "monty.h"

/**
 * Pchar - prints the character equivalent of the top element of stack
 *
 * @stack: a stack.
 * @number: line number.
 */
void Pchar(stack_t **stack, unsigned int number)
{
	int top;

	if (isEmpty(*stack))
		ErrExit(*stack, "L%d: can't pchar, stack empty\n", number);

	top = getTop(*stack);
	if (top > 127 || top < 0)
		ErrExit(*stack, "L%d: can't pchar, value out of range\n", number);
	printf("%c\n", top);
}

/**
 * Pstr - prints stack as a string
 *
 * @stack: a stack.
 * @number: line number.
 */
void Pstr(stack_t **stack, unsigned int number)
{
	UNUSED(number);

	print_stack_str(*stack);
}

/**
 * Pall - prints stack
 *
 * @stack: a stack.
 * @number: line number.
 */
void Pall(stack_t **stack, unsigned int number)
{
	UNUSED(number);

	print_stack(*stack);
}

/**
 * Pint - prints top element.
 *
 * @stack: a stack.
 * @number: line number.
 */
void Pint(stack_t **stack, unsigned int number)
{
	if (isEmpty(*stack))
		ErrExit(*stack, "L%d: can't pint, stack empty\n", number);
	printf("%d\n", getTop(*stack));
}
