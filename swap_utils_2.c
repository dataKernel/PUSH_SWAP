#include "include/stack.h"
#include "include/stack_utils.h"

// inclusions pour read()
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	size_list(t_node **head)
{
	t_node	*tempHead;
	int		size;

	if (*head == NULL)
		return (0);
	size = 0;
	while (*head)
	{
		*head = (*head)->next;
		size++;
	}
	return (size);
}

void	func_choice_base(t_node **headA, t_node **headB, char *str)
{
	/*
	if(!ft_strncmp(str, "sa", 3))
		swap(headA);
	else if(!ft_strncmp(str, "sb", 3))
		swap(headB);
	else if(!ft_strncmp(str, "ss", 3))
		swap_all(headA, headB);
	else if(!ft_strncmp(str, "pa", 3))
		push(headB, headA);
	else if(!ft_strncmp(str, "pb", 3))
		push(headA, headB);
	else
		func_choice_advanced(headA, headB, str);
	*/
}

void	func_choice_advanced(t_node **headA, t_node **headB, char *str)
{
	if(!ft_strncmp(str, "ra", 3))
		rotate(headA);
	else if(!ft_strncmp(str, "rb", 3))
		rotate(headB);
	else if(!ft_strncmp(str, "rr", 3))
		rotate_all(headA, headB);
	else if(!ft_strncmp(str, "rra", 3))
		reverse(headA);
	else if(!ft_strncmp(str, "rrb", 3))
		reverse(headB);
	else if(!ft_strncmp(str, "rrr", 3))
		reverse_all(headA, headB);
	else
	{
		printf("Error\n");
		exit(1);
	}
}

void	exec_swap_func(t_node **headA, t_node **headB)
{
	char	choice[4];
	char	buffer;
	int		i;

	i = 0;
	printf("__choice__:\n");
	while (buffer != END_OF_FILE)
	{
		read(0, &buffer, 1);
		if (buffer != END_OF_LINE && buffer != END_OF_FILE && i < 4)
		{
			choice[i] = buffer;
			i++;
		}
		else
		{
			choice[i] = '\0';
			func_choice_base(headA, headB, choice);
			i = 0;
		}
	}
}

bool	check_list_is_ordered(t_node *head)
{
	while(head->next)
	{
		if(head->value < head->next->value)
			return(false);
		head = head->next;
	}
	return(true);
}