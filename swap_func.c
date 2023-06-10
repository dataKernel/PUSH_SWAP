#include "stack.h"
#include <stdlib.h>

// function to create a node who returns a ptr on t_node with the given value
t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->value = value;
	node->next = NULL;
	return (node);
}

/* function to push a node at the top of the stack(head) and link all the others
nodes between them until null */
void	push(t_node **head, t_node *elem)
{
	t_node	*firstElem;

	firstElem = *head;
	*head = elem;
	elem->next = firstElem;
}

/* pa (push a) : Prend le premier élément au sommet de b et le met sur a.
Ne fait rien si b est vide. */
void	push_a(t_node **headA, t_node **headB, t_node *elem)
{
	return ;
}