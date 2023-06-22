#include "include/stack_utils.h"
#include "include/stack.h"
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
	show_results(&headA, &headB);
	return (0);
}