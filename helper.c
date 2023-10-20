#include "monty.h"

/**
 * InitializeMonty - Initialize input
 * Return: pointer to input
 */
ReadLine *InitializeInput(void)
{
	ReadLine *input = (ReadLine *) malloc(sizeof(ReadLine));

	if (input == NULL)
		return (NULL);

	input->Buffer = MakeNewBuffer();
	input->Bytecodes = NULL;
	input->Mode = STACK_MODE;

	return (input);
}

/**
 * PrepareBytecode - Prepares bytecodes for execution.
 *
 * Return: Success or failure
 */
PrepareResult PrepareBytecode(void)
{
	size_t len, comment_position;

	len = strlen(Input->Buffer.buffer);
	Input->Buffer.buffer[len - 1] = '\0';

	comment_position = strchr_no(Input->Buffer.buffer, '#');
	if (comment_position < len)
		Input->Buffer.buffer[comment_position] = '\0';

	Input->Bytecodes = strtow(Input->Buffer.buffer);
	if (Input->Bytecodes == NULL)
		return (PREPARE_BYTECODE_FAILURE);

	return (PREPARE_BYTECODE_SUCCESS);
}

/**
 * MakeNewBuffer - Creates an empty buffer.
 * Return: a buffer.
 */
InputBuffer MakeNewBuffer(void)
{
	InputBuffer new_buffer = {NULL, NULL, 0, 0, 0};

	return (new_buffer);
}

/**
 * isNum - checks if string argument represents a number.
 *
 * @s: points to string argument.
 * Return: TRUE if s is a number, otherwise FALSE.
 */
Boolean isNum(const char *s)
{
	int i = 0;

	i += strspn(s, "+-");
	while (s[i] != '\0')
	{
		if (isdigit(s[i]) == 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
