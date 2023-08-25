#include "monty.h"

/**
 * f_push - Adds a node to the stack or queue.
 * @head: Pointer to the stack/queue head
 * @counter: Line number
 * Return: No return value
 */
void f_push(stack_t **head, unsigned int counter)
{
    int value, index = 0, is_negative = 0, has_non_digit = 0;

    if (bus.arg)
    {
        if (bus.arg[0] == '-')
            is_negative = 1;

        for (; bus.arg[index] != '\0'; index++)
        {
            if (bus.arg[index] > '9' || bus.arg[index] < '0')
            {
                has_non_digit = 1;
                break;
            }
        }

        if (has_non_digit)
        {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            fclose(bus.file);
            free(bus.content);
            free_stack(*head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    value = atoi(bus.arg);

    if (bus.lifo == 0)
        addnode(head, value);
    else
        addqueue(head, value);
}
