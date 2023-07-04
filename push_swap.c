#include "include/stack.h"
#include "include/stack_utils.h"
#include <stdlib.h>
#include <stdio.h>

t_node	*copy_head(t_node *head)
{
	t_node	*copyHead;
	t_node	*firstElem;
	t_node	*node;

	copyHead = create_node(head->value);
	firstElem = copyHead;
	head = head->next; 
	while(head)
	{
		node = create_node(head->value);
		copyHead->next = node;
		copyHead = copyHead->next;
		head = head->next;
	}
	copyHead->next = NULL;
	copyHead = firstElem;
	return(copyHead);
}

void	free_head(t_node *head)
{
	while(head)
	{
		free(head);
		head = head->next;
	}
}

void	split_headA_and_headB(t_node **headA, t_node **headB)
{
	while(size_list(*headA) > 3)
	{
		push(headA, headB);
	}
	ordering_three_elem(headA);
}


void	ordering_three_elem(t_node **headA)
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
			if(check_list_is_ordered(copyTestHead))
				swap(headA);
			else 
				rotate(headA);
		}
	}
	free_head(copyTestHead);
}

void	insertion_into_headA(t_node **headA, t_node **headB)
{	
}