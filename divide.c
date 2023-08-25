#include "monty.h"

/**
 * divide_top_two_elements - Divides the second element by the first element of the stack.
 * @head: Pointer to the head of the stack
 * @line_number: Line number where the operation is performed
 */
void divide_top_two_elements(stack_t **head, unsigned int line_number)
{
    stack_t *current;
    int stack_length = 0, result;

    current = *head;

    while (current)
    {
        current = current->next;
        stack_length++;
    }

    if (stack_length < 2)
    {
        fprintf(stderr, "Error at line %u: Not enough elements for division\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    current = *head;

    if (current->n == 0)
    {
        fprintf(stderr, "Error at line %u: Division by zero\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    result = current->next->n / current->n;
    current->next->n = result;

    *head = current->next;
    free(current);
}
