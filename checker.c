#include "include/stack_utils.h"
#include "include/stack.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	// heads definitions
	t_node  *headA;
	t_node  *headB;
	t_node	*nodeCreationA;
	t_node	*nodeCreationB;
	int i;

	headA = NULL;
	headB = NULL;
	i = 1;
    //protection des arguments via main
    if(argc <= 1)
        return(-1);
	//creation de la liste
	while (i < argc)
	{       
		nodeCreationA = create_node(ft_atoi(argv[i]));
        nodeCreationB = create_node(ft_atoi(argv[i]));
		push_element(&headA, nodeCreationA);
		push_element(&headB, nodeCreationB);
		i++;
	}
	i = 1;
	//call test fuction
	rotate_all(&headA, &headB);
	while(headA)
	{
		printf("Element(A)[%i]->%i\n", i, headA->value);
		headA = headA->next;
		i++;
	}
	printf("\n");
	i = 1;
	while(headB)
	{
		printf("Element(B)[%i]->%i\n", i, headB->value);
		headB = headB->next;
		i++;
	}
	return (0);
}