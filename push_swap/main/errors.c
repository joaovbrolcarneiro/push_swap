#include "../../inc/push_swap.h"

int	check_syntax(char *str) // Function to handle syntax errors and return 1 for error if certain conditions are met
{
    if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9'))) // Verify if the first character is a sign or digit
        return (1);
    if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9')) // If the first character is a sign but the second is not a digit
        return (1);
    while (*++str) // Increment pointer to the next character and continue checking until the string ends
    {
        if (!(*str >= '0' && *str <= '9')) // Ensure the next character is a digit
            return (1);
    }
    return (0);
}

int	check_duplicate(t_stack_node *stack, int value) // Function to check for duplicate numbers in stack
{
    if (!stack) // Return false if the stack is empty
        return (0);
    while (stack) // Iterate through the stack
    {
        if (stack->nbr == value) // If the current node's value matches `value`, a duplicate is found
            return (1);
        stack = stack->next; // Move to the next node
    }
    return (0);
}

void	free_stack_memory(t_stack_node **stack) // Function to free the stack when an error occurs
{
    t_stack_node *next_node; // Temporary pointer to store the next node before freeing
    t_stack_node *current_node;

    if (!stack) // Check if the stack is empty
        return ;
    current_node = *stack;
    while (current_node) // Loop through all nodes in the stack
    {
        next_node = current_node->next; // Save the pointer to the next node
        current_node->nbr = 0; // Reset the node's value to 0 (helpful for debugging potential issues)
        free(current_node); // Deallocate the memory occupied by the current node
        current_node = next_node; // Move to the next node
    }
    *stack = NULL; // Set the stack pointer to NULL after freeing all nodes
}

void	free_and_print_error(t_stack_node **stack) // Function to free the stack and print error message upon encountering an error
{
    free_stack_memory(stack); // Call the function to free the stack
    ft_printf("Error\n"); // Print error message
    exit(1); // Exit the program with an error code
}