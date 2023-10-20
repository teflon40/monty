#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE		1
#define UNUSED(x)		((void) x)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct
{
	FILE *fp;
	char *buffer;
	size_t size;
	size_t bytes;
	size_t line_number;
} InputBuffer;

typedef enum { STACK_MODE, QUEUE_MODE } Mode_t;

typedef enum
{
	PREPARE_BYTECODE_SUCCESS,
	PREPARE_BYTECODE_FAILURE
} PrepareResult;

typedef enum { FALSE, TRUE } Boolean;

typedef struct readline
{
	InputBuffer Buffer;
	char **Bytecodes;
	Mode_t Mode;
} ReadLine;
extern ReadLine *Input;

ReadLine *InitializeInput(void);
InputBuffer MakeNewBuffer(void);
PrepareResult PrepareBytecode(void);
void ExecuteOpcode(stack_t **head, unsigned int line_number);
void FreeBytecodes(void);
void ErrExit(stack_t *stack, const char *format, ...);

int getTop(stack_t *stack);
void FreeStack(stack_t *stack);
size_t stackLen(const stack_t *stack);
Boolean isEmpty(stack_t *stack);
Boolean isNum(const char *s);
char **strtow(char *s);
size_t strchr_no(const char *s, int ch);
#endif /* monty.h */
