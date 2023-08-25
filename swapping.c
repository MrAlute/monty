#include "monty.h"

/**
 * f_swap - Swaps the top two elements of the stack.
 * @head: Pointer to the stack head
 * @counter: Line number
 * Return: No return value
 */
void f_swap(stack_t **head, unsigned int counter)
{
    stack_t *current;
    int num_nodes, temp;

    current = *head;

    for (num_nodes = 0; current != NULL; num_nodes++)
        current = current->next;

    if (num_nodes < 2)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    current = *head;
    temp = current->n;
    current->n = current->next->n;
    current->next->n = temp;
}
