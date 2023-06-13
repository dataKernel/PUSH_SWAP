#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

/* create_node(value): to create a node who returns 
a ptr on t_node with the given value */
t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->value = value;
	node->next = NULL;
	return (node);
}

/* push_element(head, elem): push a node at the top of the stack(head) and 
link all the others nodes between them until null (used to init the list) */
void	push_element(t_node **head, t_node *elem)
{
	t_node	*firstElem;

	firstElem = *head;
	*head = elem;
	elem->next = firstElem;
}

/* push(src, dst): Take the first element of the list(src) and push it to
 an other list on the top of it(dst). Don't do anything if src is empty. */
void	push(t_node **src, t_node **dst)
{
	t_node	*firstElemDst;
	t_node	*nextElementSrc;

	if(*src == NULL)
	{
		printf("ERROR src is NULL");
		return ;
	}
	firstElemDst = *dst;
	nextElementSrc = (*src)->next;
	*dst = *src;
	(*dst)->next = firstElemDst;
	*src = nextElementSrc;
}

/* pop(src): Take out the first element of the list(src), 
and return it, while pointing the elem to NULL.*/
t_node	*pop(t_node **head)
{
	t_node	*firstElem;

	if(*head == NULL)
	{
		printf("ERROR the head is NULL");
		return ;
	}
	firstElem = *head;
	firstElem->next = NULL;
	*head = (*head)->next;
	return(firstElem);
}