#include "include/stack.h"
#include "include/stack_utils.h"
#include <stdio.h>

void	push_a(t_node **headB, t_node **headA)
{
	t_node	*firstElement;
	t_node	*nextElement;

	if (headB == NULL || *headB == NULL || (*headB)->next == NULL)
		return ;
	firstElement = *headA;
	nextElement = (*headB)->next;
	*headA = *headB;
	(*headA)->next = firstElement;
	*headB = nextElement;
}

void	push_b(t_node **headA, t_node **headB)
{
	t_node	*firstElement;
	t_node	*nextElement;

	if (headA == NULL || *headA == NULL || (*headA)->next == NULL)
		return ;
	firstElement = *headB;
	nextElement = (*headA)->next;
	*headB = *headA;
	(*headB)->next = firstElement;
	*headA = nextElement;
}

void	swap_a(t_node **headA)
{
	t_node	*oldHead;

	if (headA == NULL || *headA == NULL || (*headA)->next == NULL)
		return ;
	oldHead = *headA;
	*headA = (*headA)->next;
	oldHead->next = (*headA)->next;
	(*headA)->next = oldHead;
}

void	swap_b(t_node **headB)
{
	t_node	*oldHead;

	if (headB == NULL || *headB == NULL || (*headB)->next == NULL)
		return;
	oldHead = *headB;
	*headB = (*headB)->next;
	oldHead->next = (*headB)->next;
	(*headB)->next = oldHead;
}

void	swap_all(t_node **headA, t_node **headB)
{
	if (headA != NULL || *headA != NULL || (*headA)->next != NULL)
		swap_a(headA);
	if (headB != NULL || *headB != NULL || (*headB)->next != NULL)
		swap_b(headB);
}