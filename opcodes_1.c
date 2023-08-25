#include "monty.h"

/**
 * push - This pushes a node to the top of stack
 * @stack: A pointer to the head node pointer of the stack
 * @nline: The line number
 *
 * Return: Nothing.
 **/

void push(stack_t **stack, unsigned int nline)
{
	stack_t *new;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", nline);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	new->next = *stack;
	new->prev = NULL;
	new->n = arg.arg;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - It prints the data of all nodes in stack
 * @stack: A pointer to the head node pointer of stack
 * @nline: The line number
 *
 * Return: Nothing.
 **/

void pall(stack_t **stack, unsigned int nline)
{
	stack_t *temp;
	(void)nline;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * free_stack - It frees all nodes in a stack
 * @stack: A pointer to the head node pointer of stack
 *
 * Return: Nothing.
 **/

void free_stack(stack_t **stack)
{
	stack_t *temp = NULL;

	if (stack == NULL || *stack == NULL)
		return;
	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

/**
 * nop - It does nothing
 * @stack: A pointer to the head node pointer of stack
 * @nline: The line number
 *
 * Return: Nothing.
 **/

void nop(stack_t **stack, unsigned int nline)
{
	(void)stack;
	(void)nline;
}

/**
 * _isalpha - It checks if int is in alphabet
 * @c: An int
 *
 * Return: 1 if yes, 0 if no
 **/

int _isalpha(int c)
{
	if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
		return (1);
	else
		return (0);
}

