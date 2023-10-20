#include "monty.h"


/**
 * ErrExit - prints error message and exit progrm
 * @stack: stack to be freed.
 * @format: pointer to message string.
 */
void ErrExit(stack_t *stack, const char *format, ...)
{
	va_list argList;

	va_start(argList, format);
	vfprintf(stderr, format, argList);

	if (stack)
		FreeStack(stack);
	if (Input.Bytecodes)
		FreeBytecodes();
	if (Input.buffer)
		free(Input.buffer);
	if (Input.fp)
		fclose(Input.fp);

	va_end(argList);
	exit(EXIT_FAILURE);
}
