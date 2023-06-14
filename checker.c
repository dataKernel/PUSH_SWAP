#include "include/stack.h"
#include "include/stack_utils.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	// heads definitions
	t_node  *headA;
	t_node  *headB;
	t_node	*nodeCreation;
	int i;
	int	check;

	headA = NULL;
	headB = NULL;
	i = 1;
    //protection des arguments via main
    if(argc <= 1)
        return(-1);
	//creation de la liste
	while (i < argc)
	{       
		nodeCreation = create_node(ft_atoi(argv[i]));
        push_element(&headB, nodeCreation);
		i++;
	}
	//call test fuction
	swap(&headB, NULL);
	while(headA)
	{
		printf("Element(A)[%i]->%i\n", i, headA->value);
		headA = headA->next;
		i++;
	}
	i = 1;
	while(headB)
	{
		printf("Element(B)[%i]->%i\n", i, headB->value);
		headB = headB->next;
		i++;
	}
	return (0);
}