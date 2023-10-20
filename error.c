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
	for (; *format; format++)
	{
		if (*format == '%')
		{
			if (*++format == 's')
				fprintf(stderr, "%s", va_arg(argList, char *));
			else
				fprintf(stderr, "%d", va_arg(argList, int));
		}
		else
			write(STDERR_FILENO, &(*format), 1);
	}
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

	va_end(argList);
	exit(EXIT_FAILURE);
}
