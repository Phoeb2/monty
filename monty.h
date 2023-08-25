#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * struct stack_s - The doubly linked list representation of a stack (or queue)
 * @n: An integer
 * @prev: It points to the previous element of the stack (or queue)
 * @next: It points to the next element of the stack (or queue)
 **/

typedef struct arg_s
{
	int arg;
	int flag;
} arg_t;

extern arg_t arg;

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - The opcode and its function
 * @opcode: The opcode
 * @f: The function to handle the opcode
 **/

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct line - The contents of line and corresponding number
 * @contents: The array of tokens read from the line
 * @number: The line number
 **/

typedef struct line
{
	unsigned int number;
	char **content;
} line_t;

/**
 * struct stack_s - The doubly linked list representation of a stack (or queue)
 * @n: An integer
 * @prev: It points to the previous element of the stack (or queue)
 * @next: It points to the next element of the stack (or queue)
 **/
typedef struct meta_s
{
	char *buf;
	stack_t *stack;
	FILE *file;
} meta_t;

/* Important functions */
void (*get_op_func(line_t line, meta_t *meta))(stack_t **, unsigned int);
int _isalpha(int c);

/* Parse functions */
void parsefile(FILE *file);
void parseline(line_t *line, char *buffer);

/* Verification functions */
bool comment_check(line_t line);
void push_check(line_t line, meta_t *meta, char *opcode);

/* Stack manipulation functions */
void push(stack_t **stack, unsigned int nline);
void pall(stack_t **stack, unsigned int nline);
void pint(stack_t **stack, unsigned int nline);
void pop(stack_t **stack, unsigned int nline);
void swap(stack_t **stack, unsigned int nline);
void nop(stack_t **stack, unsigned int nline);
void rotl(stack_t **stack, unsigned int nline);
void rotlop(stack_t **stack, unsigned int nline);
void rotrop(stack_t **stack, unsigned int nline);
void pchar(stack_t **stack, unsigned int nline);
void pstr(stack_t **stack, unsigned int nline);
void free_stack(stack_t **stack);
void nop(stack_t **stack, unsigned int nline);
void qpush(stack_t **stack, unsigned int nline);
void addqu(stack_t **stack, unsigned int nline);
void addst(stack_t **stack, unsigned int nline);

/* Math functions */
void subop(stack_t **stack, unsigned int nline);
void addop(stack_t **stack, unsigned int nline);
void divop(stack_t **stack, unsigned int nline);
void mulop(stack_t **stack, unsigned int nline);
void modop(stack_t **stack, unsigned int nline);

#endif /* MONTY_H */
