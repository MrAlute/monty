#include "monty.h"

/**
 * f_pop - Removes the top element from the stack.
 * @head: Pointer to the stack head
 * @line_number: Line number for error reporting
 * Return: No return value
 */
void f_pop(stack_t **head, unsigned int line_number)
{
	stack_t *top_node;

    if (*head == NULL)
    {
	fprintf(stderr, "Error at line %u: Cannot pop from an empty stack\n", line_number);
	fclose(bus.file);
	free(bus.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
    }

    top_node = *head;
    *head = top_node->next;
    free(top_node);
}
