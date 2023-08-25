#include "monty.h"

/**
 * add_node_to_stack - Adds a new node to the head of the stack.
 * @head: Pointer to the head of the stack
 * @new_value: Value to be assigned to the new node
 */
void add_node_to_stack(stack_t **head, int new_value)
{
    stack_t *new_node, *aux;

    aux = *head;

    // Allocate memory for the new node
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Update the 'prev' pointer of the current head if it exists
    if (aux)
        aux->prev = new_node;

    // Initialize the values of the new node
    new_node->n = new_value;
    new_node->next = *head;
    new_node->prev = NULL;

    // Update the head to point to the new node
    *head = new_node;
}
