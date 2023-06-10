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

//pa (push a) : Prend le premier élément au sommet de b et le met sur a.
//Ne fait rien si b est vide.
void	push_a(t_node **head, t_node *node)
{
	t_node	*firstElem;

	firstElem = *head;
	*head = node;
	node->next = firstElem;
}