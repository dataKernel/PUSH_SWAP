#include "include/stack.h"
#include "include/stack_utils.h"
#include <stdio.h>

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
			swap(headA);
	}
	else
	{
		// A > B > C
		if ((*headA)->value > (*headA)->next->value
			&& (*headA)->next->value > (*headA)->next->next->value)
		{
			rotate(headA);
			swap(headA);
		}
		// A < B > C
		else if ((*headA)->value < (*headA)->next->value
			&& (*headA)->next->value > (*headA)->next->next->value)
		{
			reverse(headA);
			if (!check_list_is_ordered(*headA))
				swap(headA);
		}
		// A > B < C
		else if ((*headA)->value > (*headA)->next->value
			&& (*headA)->next->value < (*headA)->next->next->value)
		{
			swap(&copyTestHead);
			if (check_list_is_ordered(copyTestHead))
				swap(headA);
			else
				rotate(headA);
		}
	}
	free_list(copyTestHead);
}

void	insertion_into_headA(t_node **headA, t_node **headB)
{
	int 	actualIndex;
	int		insertIndex;

	actualIndex = 0;
	insertIndex = check_index_insert(*headA, (*headB)->value);
	check_best_operation(*headA, *headB, actualIndex, insertIndex);
	actualIndex = insertIndex;
	return ;
}