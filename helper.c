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
