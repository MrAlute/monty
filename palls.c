#include "monty.h"

/**
 * f_pall - Prints all elements in the stack.
 * @head: Pointer to the stack head
 * @counter: Not used
 * Return: No return value
 */
void f_pall(stack_t **head, unsigned int counter)
{
    stack_t *current;
    (void)counter;

    current = *head;
    if (current == NULL)
        return;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
