#include "monty.h"

/**
 * Stack - change mode to stack mode.
 *
 * @stack: a stack.
 * @number: line number.
 */
void Stack(__attribute__((unused)) stack_t **stack,
		__attribute__((unused)) unsigned int number)
{
	Input->Mode = STACK_MODE;
}

/**
 * Queue - change mode to queue mode
 *
 * @stack: a stack.
 * @number: line number.
 */
void Queue(__attribute__((unused)) stack_t **stack,
		__attribute__((unused)) unsigned int number)
{
	Input->Mode = QUEUE_MODE;
}

/**
 * Nop - does nothing
 *
 * @stack: a stack.
 * @number: line number.
 */
void Nop(__attribute__((unused)) stack_t **stack,
		__attribute__((unused)) unsigned int number)
{
}

/**
 * getTop - get the element at the top of stack.
 *
 * @stack: stack.
 * Return: the top element.
 */
int getTop(stack_t *stack)
{
	return (stack->n);
}
