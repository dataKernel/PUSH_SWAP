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

t_node	*pop(t_node **head)
{
	t_node *firstElem;

	if (head == NULL)
	{
		printf("ERROR the head is NULL");
		return (NULL);
	}
	firstElem = *head;
	*head = (*head)->next;
	firstElem->next = NULL;
	return (firstElem);
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

	if (src == NULL)
	{
		printf("ERROR src is NULL");
		return ;
	}
	firstElemDst = *dst;
	nextElemSrc = (*src)->next;
	*dst = *src;
	(*dst)->next = firstElemDst;
	*src = nextElemSrc;
}

void	swap(t_node **head)
{
	int		firstElem;
	
	firstElem = 0;
	firstElem = (*head)->value;
	(*head)->value = (*head)->next->value;
	(*head)->next->value = firstElem;
}