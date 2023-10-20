#include "monty.h"

/**
 * fswap - swaps top two elements
 *
 * @stack: stack
 */
void fswap(stack_t **stack)
{
	int tmp;

	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

/**
 * print_stack_str - prints a stack in string form
 *
 * @stack: stack.
 */
void print_stack_str(const stack_t *stack)
{
	while (stack != NULL)
	{
		if (stack->n <= 0 || stack->n > 127)
			break;
		putchar(stack->n);
		stack = stack->next;
	}
	putchar('\n');
}

/**
 * print_stack - print stack
 *
 * @stack: stack
 */
void print_stack(const stack_t *stack)
{
	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}

/**
 * stackLen - length of stack.
 *
 * @stack: stack.
 * Return: length of stack.
 */
size_t stackLen(const stack_t *stack)
{
	size_t len;

	for (len = 0; stack != NULL; stack = stack->next)
		++len;
	return (len);
}
