#include "include/stack_utils.h"
#include "include/stack.h"
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

void	push(t_node **src, t_node **dst)
{
	t_node	*firstElemDst;
	t_node	*nextElemSrc;

	if (src == NULL || *src == NULL)
		return ;
	firstElemDst = *dst;
	nextElemSrc = (*src)->next;
	*dst = *src;
	(*dst)->next = firstElemDst;
	*src = nextElemSrc;
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