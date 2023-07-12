#include "include/stack.h"
#include "include/stack_utils.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief init the list based on the arguments given by the program
 * @param head ptr on ptr on `t_node` given as the HEAD
 * @param argc integer representing the numbers of arguments given by the prog
 * @param argv string array representing the values of arguments given by the prog
 * @return VOID
 */
void	init_list(t_node **headA, int argc, char *argv[])
{
	t_node	*nodeCreation;
	int		i;

	i = 1;
	while (i < argc)
	{
		nodeCreation = create_node(ft_atoi(argv[i]));
		push_element(headA, nodeCreation);
		i++;
	}
}

void	arguments_checking(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	if (argc <= 2)
	{
		printf("Error\n");
		exit(1);
	}
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				if(argv[i][j] != '-')
				{
					printf("Error\n");
					exit(1);
				}
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_node *headA;
	t_node *headB;

	headA = NULL;
	headB = NULL;
	arguments_checking(argc, argv);
	init_list(&headB, argc, argv);
	//split_headA_and_headB(&headA, &headB);
	show_results(headA, headB);
	swap_all(&headA, &headB);
	show_results(headA, headB);
	//insertion_into_headA(&headA, &headB);
	return (0);
}