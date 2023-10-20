#include "monty.h"

InputBuffer Input = {NULL, NULL, NULL, 0, STACK_MODE, 0};

/**
 * main - program starts from here
 *
 * @ac: number of arguments passed to the program
 * @av: argument vector
 * Return: always EXIT_SUCCESS
 */
int main(int ac, char *av[])
{
	stack_t *head = NULL;

	if (ac != 2)
		ErrExit(NULL, "USAGE: monty file\n");

	Input.fp = fopen(av[1], "r");
	if (Input.fp == NULL)
		ErrExit(NULL, "Error: Can't open file %s\n", av[1]);

	while (getline(&(Input.buffer), &(Input.size), Input.fp) != -1)
	{
		Input.line_number++;
		if (PrepareBytecode() == PREPARE_BYTECODE_FAILURE)
			continue;
		ExecuteOpcode(&head, Input.line_number);
		FreeBytecodes();
	}
	fclose(Input.fp);
	FreeStack(head);
	free(Input.buffer);
	return (EXIT_SUCCESS);
}
