#include "include/stack.h"
#include "include/stack_utils.h"
#include <stdio.h>

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

int	main(int argc, char *argv[])
{
	t_node *headA;
	t_node *headB;
	int i;
	int j;

	// heads definitions
	headA = NULL;
	headB = NULL;
	i = 0;
	// protection des arguments via main
	if (argc <= 1)
	{
		printf("Error\n");
		return (-1);
	}
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	init_list(&headA, argc, argv);
	split_headA_and_headB(&headA, &headB);
	show_results(headA, headB);
	insertion_into_headA(&headA, &headB);
	return (0);
}