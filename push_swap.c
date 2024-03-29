/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: data_kernel <data_kernel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:54:22 by data_kernel       #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/08/03 00:25:20 by data_kernel      ###   ########.fr       */
=======
/*   Updated: 2023/08/05 19:27:09 by data_kernel      ###   ########.fr       */
>>>>>>> 67496ee3fc9f99d6bdc19ff04e32d79a6995de67
/*                                                                            */
/* ************************************************************************** */

#include "include/stack.h"
#include "PRINTF/ft_printf.h"
#include "PRINTF/libft/libft.h"
#include "include/stack_utils.h"
#include <stdlib.h>
#include <stdio.h>

void	init_list(t_node **headA, int argc, char *argv[])
{
	t_node	*nodecreation;
	int		i;
	int		j;

	i = argc - 1;
	if (ft_strncmp(argv[0], "./push_swap", ft_strlen(argv[0])))
		j = 0;
	else
		j = 1;
	while (j < argc)
	{
		nodecreation = create_node(ft_atoi(argv[i]));
		push_element(headA, nodecreation);
		i--;
		j++;
	}
}

void	check_argv_alpha(int argc, char **argv)
{
	int		i;
	int		j;

	if (ft_strncmp(argv[0], "./push_swap", ft_strlen(argv[0])))
		i = 0;
	else
		i = 1;
	while (i <= argc - 1)
	{
		j = 0;
		if (argv[i][0] == '-')
			j++;
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != ' ')
			{
				ft_putstr_fd("Error\n", 2);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

int	check_space(char *str)
{
	int		space;
	int		i;

	space = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			space++;
		i++;
	}
	return (space + 1);
}

void	check_arguments(int argc, char *argv[], 
t_node **head_a)
{
	char	**split_array;

	if (argv[1][ft_strlen(argv[1]) - 1] == ' ' || argv[1][0] == ' ')
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	if (argc == 2 && check_space(argv[1]) > 1)
	{
		split_array = ft_split(argv[1], ' ');
		check_argv_alpha(check_space(argv[1] + 1), split_array);
		init_list(head_a, check_space(argv[1]), split_array);
		free_split_array(split_array);
	}
	else
	{
		check_argv_alpha(argc, argv);
		init_list(head_a, argc, argv);
	}
	if (check_doublons(*head_a))
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	t_node			*head_a;
	t_node			*head_b;

	if (argc < 2)
		return (0);
	head_a = NULL;
	head_b = NULL;
	check_arguments(argc, argv, &head_a);
	if (check_list_is_ordered(head_a))
		return (0);
	split_heada_and_headb(&head_a, &head_b);
	insertion_into_head_a(&head_a, &head_b);
	free_list(head_a);
	return (0);
}
