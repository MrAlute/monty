#include "monty.h"

/**
 * f_rotr - Rotates the stack to the bottom.
 * @head: Pointer to the stack head
 * @counter: Line number (unused)
 * Return: No return value
 */
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
    stack_t *current, *last_node;

    current = *head;

    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }

    while (current->next)
    {
        current = current->next;
    }

    last_node = current;

    last_node->next = *head;
    last_node->prev->next = NULL;
    last_node->prev = NULL;
    (*head)->prev = last_node;
    (*head) = last_node;
}
