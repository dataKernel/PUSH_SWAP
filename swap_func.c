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

void	swap(t_node **headSimple, t_node **headDouble)
{
	int		firstElemSimple;
	int		firstElemDouble;
	
	firstElemSimple = 0;
	firstElemDouble = 0;
	if(headDouble == NULL)
	{
		if(headSimple == NULL)
		{
			printf("Error headSimple is NULL");
			return ;
		}
		firstElemSimple = (*headSimple)->value;
		(*headSimple)->value = (*headSimple)->next->value;
		(*headSimple)->next->value = firstElemSimple;
	}
	else
		printf("head pas null");
		//faire le ss== sa + sb
	return ;
}