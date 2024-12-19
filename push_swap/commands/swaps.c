#include "../../inc/push_swap.h"

static void swap(t_stack_node **head)
{
    t_stack_node *first;
    t_stack_node *second;

    if (!*head || !(*head)->next) // No swap needed if there are fewer than two nodes
        return;

    first = *head;            // The first node (old head)
    second = (*head)->next;   // The second node

    *head = second;           // Move the head to the second node

    // Swap the next and previous pointers of the first and second nodes
    first->next = second->next;  // The old head's next should point to the node after the second node
    if (first->next)             // If there is a node after the old head, update its previous pointer
        first->next->previous = first;

    second->previous = NULL;    // The new head's previous should be NULL
    second->next = first;       // The new head's next should point to the old head

    first->previous = second;   // The old head's previous should point to the new head
}

void sa(t_stack_node **a, bool print) // Swap the first two nodes of stack `a` and print the instruction
{
    swap(a);
    if (!print)
        ft_printf("sa\n");
}

void sb(t_stack_node **b, bool print) // Swap the first two nodes of stack `b` and print the instruction
{
    swap(b);
    if (!print)
        ft_printf("sb\n");
}

void ss(t_stack_node **a, t_stack_node **b, bool print) // Simultaneously swap the first two nodes of the stacks and print the instruction
{
    swap(a);
    swap(b);
    if (!print)
        ft_printf("ss\n");
}