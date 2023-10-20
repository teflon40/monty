#include "monty.h"

ReadLine *Input = NULL;

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

	Input = InitializeInput();
	if (ac != 2)
		ErrExit(NULL, "USAGE: monty file\n");

	Input->Buffer.fp = fopen(av[1], "r");
	if (Input->Buffer.fp == NULL)
		ErrExit(NULL, "Error: Can't open file %s\n", av[1]);

	while (getline(&(Input->Buffer.buffer),
		&(Input->Buffer.size), Input->Buffer.fp) != -1)
	{
		Input->Buffer.line_number++;
		if (PrepareBytecode() == PREPARE_BYTECODE_FAILURE)
			continue;
		ExecuteOpcode(&head, Input->Buffer.line_number);
		FreeBytecodes();
	}
	fclose(Input->Buffer.fp);
	FreeStack(head);
	free(Input->Buffer.buffer);
	free(Input);
	exit(EXIT_SUCCESS);
}
