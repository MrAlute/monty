#include "monty.h"

/**
 * free_stack - Frees a doubly linked list.
 * @head: Pointer to the head of the stack
 */
void free_stack(stack_t *head)
{
    stack_t *current, *aux;

    current = head;

    while (current)
    {
        aux = current->next;
        free(current);
        current = aux;
    }
}
