#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>


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

extern stack_t *head;

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


/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */

typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;

extern bus_t bus;

void func_pint(stack_t **head, unsigned int counter);
void func_push(stack_t **head, unsigned int value);
void func_pall(stack_t **head, unsigned int counter);
void func_nop(stack_t **head, unsigned int counter);
void func_add(stack_t **head, unsigned int counter);
void func_swap(stack_t **head, unsigned int counter);
void func_pop(stack_t **head, unsigned int counter);
void func_div(stack_t **head, unsigned int counter);
void func_sub(stack_t **head, unsigned int counter);
void func_mul(stack_t **head, unsigned int counter);
void free_stack(stack_t *head);
void addqueue(stack_t **head, int n);
void func_queue(stack_t **head, unsigned int counter);
void func_pstr(stack_t **head, unsigned int counter);
void func_pchar(stack_t **head, unsigned int counter);
void func_mod(stack_t **head, unsigned int counter);
void func_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void func_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter);
void addnode(int n);
void func_stack(stack_t **head, unsigned int counter);
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file);
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);

#endif
