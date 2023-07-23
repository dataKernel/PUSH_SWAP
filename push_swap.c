/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaint-l <lsaint-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:54:22 by data_kernel       #+#    #+#             */
/*   Updated: 2023/07/23 20:51:17 by lsaint-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/stack.h"
#include "PRINTF/ft_printf.h"
#include "include/stack_utils.h"
#include <stdlib.h>
#include <stdio.h>

void	init_list(t_node **headA, int argc, char *argv[])
{
	t_node	*nodecreation;
	int		i;
	int		j;

	i = argc - 1;
	j = 1;
	while (j < argc)
	{
		nodecreation = create_node(ft_atoi(argv[i]));
		push_element(headA, nodecreation);
		i--;
		j++;
	}
}

void	arguments_checking(int argc, char **argv)
{
	int		i;
	int		j;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	i = 1;
	while (i < argc - 1)
	{
		j = 0;
		if (argv[i][j] < '0' || argv[i][j] > '9')
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		j++;
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
	if (argc > 2)
	{
		init_list(&head_a, argc, argv);
		split_heada_and_headb(&head_a, &head_b);
		insertion_into_head_a(&head_a, &head_b);
		show_results(head_a, head_b);
	}
	return (0);
}
