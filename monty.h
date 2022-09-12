#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct globals - global structure to use in the functions
 * @lifo: is stack or queue
 * @cont: current line
 * @arg: second parameter inside the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct globals
{
	int lifo;
	unsigned int cont;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern global_t vglo;

/* opcode_instructuions*/
void push_f(stack_t **stack, unsigned int line_number);
void pall_f(stack_t **stack, unsigned int line_number);
void pint_f(stack_t **doubly, unsigned int cline);
void pop_f(stack_t **doubly, unsigned int cline);
void swap_f(stack_t **doubly, unsigned int cline);
void queue_f(stack_t **doubly, unsigned int cline);
void stack_f(stack_t **doubly, unsigned int cline);
void add_f(stack_t **doubly, unsigned int cline);
void nop_f(stack_t **doubly, unsigned int cline);
void sub_f(stack_t **doubly, unsigned int cline);
void div_f(stack_t **doubly, unsigned int cline);
void mul_f(stack_t **doubly, unsigned int cline);
void mod_f(stack_t **doubly, unsigned int cline);
void pchar_f(stack_t **doubly, unsigned int cline);
void pstr_f(stack_t **doubly, unsigned int cline);
void rotl_f(stack_t **doubly, unsigned int cline);
void rotr_f(stack_t **doubly, unsigned int cline);

/*get function*/
void (*get_functions(char *opcd))(stack_t **stack, unsigned int line_number);

/*imported functions*/
int _sch(char *s, char c);
char *_strtoky(char *s, char *d);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int nmemb, unsigned int size);
int _strcmp(char *s1, char *s2);

/* doubly linked list functions */
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);

/* main */
void free_vglo(void);

#endif
