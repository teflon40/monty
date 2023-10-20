#include "monty.h"


/**
 * ErrExit - prints error message and exit progrm
 * @stack: stack to be freed.
 * @format: pointer to message string.
 */
void ErrExit(stack_t *stack, const char *format, ...)
{
	va_list argList;

	fflush(stdout);		/* Flush any pending output */

	va_start(argList, format);
	vfprintf(stderr, format, argList);
	va_end(argList);

	if (stack)
		FreeStack(stack);
	if (Input->Bytecodes)
		FreeBytecodes();
	if (Input->Buffer.buffer)
		free(Input->Buffer.buffer);
	if (Input->Buffer.fp)
		fclose(Input->Buffer.fp);
	if (Input)
		free(Input);
	exit(EXIT_FAILURE);
}
