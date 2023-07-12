#include "include/stack.h"
#include "include/stack_utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->value = value;
	node->next = NULL;
	return (node);
}

void	push_element(t_node **head, t_node *elem)
{
	t_node	*firstElem;

	firstElem = *head;
	*head = elem;
	elem->next = firstElem;
}

void	push_a(t_node **headA, t_node **headB)
{
	t_node	*firstElement;
	t_node	*nextElement;

	if (headA == NULL || *headA == NULL)
		return ;
	firstElement = *headB;
	nextElement = (*headA)->next;
	*headB = *headA;
	(*headB)->next = firstElement;
	*headA = nextElement;
}

void	push_b(t_node **headB, t_node **headA)
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
	if (headA == NULL || *headA == NULL || (*headA)->next == NULL)
		return ;
	if (headB == NULL || *headB == NULL || (*headB)->next == NULL)
		return ;
	swap_a(headA);
	swap_b(headB);
}