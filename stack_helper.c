#include "monty.h"

/**
 * fpush - push to the top of stack/
 *
 * @stack: stack.
 * @num: data.
 * Return: the address of the new element or NULL on failure.
 */
stack_t *fpush(stack_t **stack, int num)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	new->n = num;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;

	return (new);
}

/**
 * fpop - pop from stack.
 *
 * @stack: stack
 * Return: element popped.
 */
int fpop(stack_t **stack)
{
	stack_t *tmp;
	int element;

	tmp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	element = tmp->n;
	free(tmp);
	return (element);
}

/**
 * isEmpty - checks if stack is empty.
 *
 * @stack: stack.
 * Return: 1 if for empty stack, 0 for otherwise
 */
Boolean isEmpty(stack_t *stack)
{
	return ((stack == NULL) ? TRUE : FALSE);
}


/**
 * enqueue - Add element at the end of list.
 *
 * @stack: stack.
 * @num: stack element.
 * Return: the address of the new element, or NULL on failure.
 */
stack_t *enqueue(stack_t **stack, int num)
{
	stack_t *new, *tmp;

	if (stack == NULL)
		return (NULL);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = num;
	new->next = NULL;

	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		tmp = *stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		new->prev = tmp;
		tmp->next = new;
	}
	return (new);
}

/**
 * lpop - pops last element from stack.
 *
 * @stack: stack.
 * Return: the element popped.
 */
int lpop(stack_t **stack)
{
	stack_t *tmp;
	int element;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	element = tmp->n;
	if (tmp->prev != NULL)
		tmp->prev->next = NULL;
	free(tmp);
	return (element);
}
