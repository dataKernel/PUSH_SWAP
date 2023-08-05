/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_fuker_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: data_kernel <data_kernel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:58:13 by data_kernel       #+#    #+#             */
/*   Updated: 2023/08/05 16:19:25 by data_kernel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/stack_utils.h"
#include <stdlib.h>

void	free_split_array(char **split_array)
{
	char	**to_free;

	to_free = split_array;
	while (*to_free)
	{
		free(*to_free);
		to_free++;
	}
	free(split_array);
}
