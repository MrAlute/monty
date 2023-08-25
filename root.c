#include "monty.h"

/**
 * f_rotl - Rotates the stack to the top.
 * @head: Pointer to the stack head
 * @counter: Line number (unused)
 * Return: No return value
 */
void f_rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
    stack_t *current = *head, *new_head;

    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }

    new_head = (*head)->next;
    new_head->prev = NULL;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = *head;
    (*head)->next = NULL;
    (*head)->prev = current;
    (*head) = new_head;
}
