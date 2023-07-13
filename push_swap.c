/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: data_kernel <data_kernel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:54:22 by data_kernel       #+#    #+#             */
/*   Updated: 2023/07/13 20:48:28 by data_kernel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/stack.h"
#include "include/stack_utils.h"
#include <stdio.h>
#include <stdlib.h>

void	init_list(t_node **headA, int argc, char *argv[])
{
	t_node	*nodecreation;
	int		i;

	i = 1;
	while (i < argc)
	{
		nodecreation = create_node(ft_atoi(argv[i]));
		push_element(headA, nodecreation);
		i++;
	}
}

void	arguments_checking(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				if (argv[i][j] != '-' || argc < 2)
				{
					printf("Error\n");
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_node	*head_a;
	t_node	*head_b;

	head_a = NULL;
	head_b = NULL;
	arguments_checking(argc, argv);
	init_list(&head_a, argc, argv);
	split_headA_and_headB(&head_a, &head_b);
	show_results(head_a, head_b);
	//insertion_into_headA(&headA, &headB);
	return (0);
}
