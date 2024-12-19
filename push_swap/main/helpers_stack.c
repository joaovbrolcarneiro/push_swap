#include "../../inc/push_swap.h"

int	stack_len(t_stack_node *stack) //Calculate and return the number of nodes in the stack
{
	int	total_nodes; //Counter for stack elements

	if (!stack) 
		return (0);
	total_nodes = 0;
	while (stack) //Iterate through the stack nodes
	{
		stack = stack->next; //Advance to the next node
		total_nodes++;
	}
	return (total_nodes);
}

t_stack_node	*find_last(t_stack_node *stack) //Get a pointer to the last node in the stack
{
	if (!stack)
		return (NULL);
	while (stack->next) //Keep traversing until reaching the last node
		stack = stack->next;
	return (stack);
}

bool	stack_sorted(t_stack_node *stack) //Check if the stack elements are in ascending order
{
	if (!stack)
		return (true);
	while (stack->next) //Traverse the stack nodes
	{
		if (stack->nbr > stack->next->nbr) //If a current value is greater than the next, the stack isn't sorted
			return (false);
		stack = stack->next; //Continue to the next node
	}
	return (true);
}

t_stack_node	*find_min(t_stack_node *stack) //Locate the node with the smallest value in the stack
{
	long			min_value; //Store the smallest value encountered
	t_stack_node	*smallest_node; //Pointer to the node with the smallest value

	if (!stack)
		return (NULL);
	min_value = LONG_MAX; //Initialize with the maximum possible long value
	while (stack) //Loop through all nodes in the stack
	{
		if (stack->nbr < min_value) //Update if a smaller value is found
		{
			min_value = stack->nbr; //Set the new smallest value
			smallest_node = stack; //Set pointer to the node with the smallest value
		}
		stack = stack->next; //Proceed to the next node
	}
	return (smallest_node); 
}

t_stack_node	*find_max(t_stack_node *stack) //Locate the node with the largest value in the stack
{
	long			max_value; //Store the largest value encountered
	t_stack_node	*largest_node; //Pointer to the node with the largest value

	if (!stack)
		return (NULL);
	max_value = LONG_MIN; //Initialize with the minimum possible long value
	while (stack) //Loop through all nodes in the stack
	{
		if (stack->nbr > max_value) //Update if a larger value is found
		{
			max_value = stack->nbr; //Set the new largest value
			largest_node = stack; //Set pointer to the node with the largest value
		}
		stack = stack->next; //Proceed to the next node
	}
	return (largest_node);
}