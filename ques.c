#include "monty.h"

/**
 * f_queue - Sets the queue mode for adding nodes.
 * @head: Pointer to the stack head
 * @counter: Line number (not used)
 * Return: No return value
 */
void f_queue(stack_t **head, unsigned int counter)
{
    (void)head;
    (void)counter;
    bus.lifo = 1;
}

/**
 * addqueue - Adds a node to the tail of the stack.
 * @head: Pointer to the head of the stack
 * @n: New value to add
 * Return: No return value
 */
void addqueue(stack_t **head, int n)
{
    stack_t *new_node, *current;

    current = *head;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        printf("Error\n");
    }

    new_node->n = n;
    new_node->next = NULL;

    if (current)
    {
        while (current->next)
            current = current->next;
    }

    if (!current)
    {
        *head = new_node;
        new_node->prev = NULL;
    }
    else
    {
        current->next = new_node;
        new_node->prev = current;
    }
}
