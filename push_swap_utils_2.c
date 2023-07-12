#include "include/stack.h"
#include "include/stack_utils.h"
#include <stdio.h>
#include <stdlib.h>

t_node	*copy_head(t_node *head)
{
	t_node	*copyHead;
	t_node	*firstElem;
	t_node	*node;

	copyHead = create_node(head->value);
	firstElem = copyHead;
	head = head->next;
	while (head)
	{
		node = create_node(head->value);
		copyHead->next = node;
		copyHead = copyHead->next;
		head = head->next;
	}
	copyHead->next = NULL;
	copyHead = firstElem;
	return (copyHead);
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
		// A > B > C
		if ((*headA)->value > (*headA)->next->value
			&& (*headA)->next->value > (*headA)->next->next->value)
		{
			rotate(headA);
			swap_a(headA);
		}
		// A < B > C
		else if ((*headA)->value < (*headA)->next->value
			&& (*headA)->next->value > (*headA)->next->next->value)
		{
			reverse(headA);
			if (!check_list_is_ordered(*headA))
				swap_a(headA);
		}
		// A > B < C
		else if ((*headA)->value > (*headA)->next->value
			&& (*headA)->next->value < (*headA)->next->next->value)
		{
			swap_a(&copyTestHead);
			if (check_list_is_ordered(copyTestHead))
				swap_a(headA);
			else
				rotate(headA);
		}
	}
	free_list(copyTestHead);
}

int	min(int a, int b)
{
	return ((a > b) ? b : a);
}

int	max(int a, int b)
{
	return ((a > b) ? a : b);
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