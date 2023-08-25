#include "monty.h"

/**
 * add_top_two_elements - Adds the top two elements of the stack.
 * @head: Pointer to the head of the stack
 * @line_number: Line number where the operation is performed
 */
void add_top_two_elements(stack_t **head, unsigned int line_number)
{
    stack_t *current = *head;
    int stack_length = 0, sum;

    // Calculate the length of the stack
    while (current)
    {
        current = current->next;
        stack_length++;
    }

    // Ensure there are at least 2 elements for addition
    if (stack_length < 2)
    {
	fprintf(stderr, "Error at line %u: Not enough elements to perform addition\n", line_number);
	fclose(bus.file);
	free(bus.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
    }

    current = *head;
    sum = current->n + current->next->n;
    current->next->n = sum;

    *head = current->next;
    free(current);
}
