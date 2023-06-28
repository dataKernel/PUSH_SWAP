#include "include/stack.h"
#include "include/stack_utils.h"
#include <stdio.h>
 
int	main(int argc, char *argv[])
{
	// heads definitions
	t_node 	*headA;
	t_node 	*headB;
	int		i;
	int		j;

	headA = NULL;
	headB = NULL;
	i = 0;
	// protection des arguments via main
	if (argc <= 1)
	{
		printf("Error\n");
		return(-1);
	}
	i = 1;
	while(i < argc)
	{
		j = 0;
		while(argv[i][j])
		{
			if(argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				return(1);
			}
			j++;
		}
		i++;
	}
	init_list(&headA, argc, argv);
	show_results(headA, headB);
	swap(&headA);
	//ordering_three_elem(&headA, &headB);	
	show_results(headA, headB);
	return (0);
}