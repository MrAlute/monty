#include "monty.h"

/**
 * f_mul - Multiplies the top two elements of the stack.
 * @head: Pointer to the stack head
 * @counter: Line number for error reporting
 * Return: No return value
 */
void f_mul(stack_t **head, unsigned int counter)
{
    stack_t *current;
    int stack_length = 0, result;

    current = *head;
    {
        current = current->next;
        stack_length++;
    }

    if (stack_length < 2)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    current = *head;

    result = current->next->n * current->n;
    current->next->n = result;

    *head = current->next;
    free(current);
}
