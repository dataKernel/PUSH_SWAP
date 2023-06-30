#include "include/stack.h"
#include "include/stack_utils.h"
#include <stdio.h>

t_node	*copy_head(t_node *head)
{
	t_node	*copy_head;
	t_node	*node;

	copy_head = NULL;
	while(head->next)
	{
		node = create_node(head->value);
		push_element(&copy_head, node);
		head = head->next;
	}
}

void	ordering_three_elem(t_node **headA, t_node **headB)
{
	t_node	*copyTestHead;
	t_node	*oldHead;

	copyTestHead = *headA;
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
			if(check_list_is_ordered(copyTestHead))
				*headA = copyTestHead;
			else
			//...
		}
	}
}