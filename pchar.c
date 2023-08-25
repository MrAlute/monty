#include "monty.h"

/**
 * f_pchar - Prints the character at the top of the stack,
 *          followed by a new line.
 * @head: Pointer to the stack head
 * @line_number: Line number for error reporting
 * Return: No return value
 */
void f_pchar(stack_t **head, unsigned int line_number)
{
    stack_t *current;

    current = *head;

    if (!current)
    {
        fprintf(stderr, "Error at line %u: Can't pchar, stack empty\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    if (current->n > 127 || current->n < 0)
    {
        fprintf(stderr, "Error at line %u: Can't pchar, value out of range\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", current->n);
}
