#include "include/stack.h"
#include "include/stack_utils.h"
#include <stdio.h>
#include <stdlib.h>

t_node	*copy_head(t_node *head)
{
	t_node	*copy_head;
	t_node	*first_elem;
	t_node	*node;

	copy_head = create_node(head->value);
	first_elem = copy_head;
	head = head->next;
	while (head)
	{
		node = create_node(head->value);
		copy_head->next = node;
		copy_head = copy_head->next;
		head = head->next;
	}
	copy_head->next = NULL;
	copy_head = first_elem;
	return (copy_head);
}

void	sort_three_elem(t_node **headA)
{
	t_node	*copyTestHead;
	t_node	*oldHead;

	copyTestHead = copy_head(*headA);
	if (size_list(*headA) == 2)
	{
		if ((*headA)->value > (*headA)->next->value)
		{
			swap_a(headA);
		}
	}
	else
	{
		if ((*headA)->value > (*headA)->next->value
			&& (*headA)->next->value > (*headA)->next->next->value)
		{
			rotate_a(headA);
			swap_a(headA);
		}
		else if ((*headA)->value < (*headA)->next->value
			&& (*headA)->next->value > (*headA)->next->next->value)
		{
			reverse_a(headA);
			if (!check_list_is_ordered(*headA))
				swap_a(headA);
		}
		else if ((*headA)->value > (*headA)->next->value
			&& (*headA)->next->value < (*headA)->next->next->value)
		{
			swap_a(&copyTestHead);
			if (check_list_is_ordered(copyTestHead))
				swap_a(headA);
			else
				rotate_a(headA);
		}
	}
	free_list(copyTestHead);
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}


void	free_list(t_node *head)
{
	t_node *next;

	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
}