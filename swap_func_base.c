#include "include/stack.h"
#include "include/stack_utils.h"
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

	if(headA == NULL || *headA == NULL)
		return ;
	firstElement = *headB;
	nextElement = (*headA)->next;
	*headB = *headA;
	(*headB)->next = firstElement;
	*headA = nextElement;
}


void	swap(t_node **head)
{
	t_node	*oldHead;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return ;
	oldHead = *head;
	*head = (*head)->next;
	oldHead->next = (*head)->next;
	(*head)->next = oldHead;
}

void	swap_all(t_node **headA, t_node **headB)
{
	swap(headA);
	swap(headB);
}