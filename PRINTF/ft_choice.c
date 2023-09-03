/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: data_kernel <data_kernel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:27:36 by lancelot          #+#    #+#             */
/*   Updated: 2023/07/18 16:33:42 by data_kernel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

int	ft_choice(char choice, va_list lst)
{
	char	*tmp;

	if (choice == 's')
	{
		tmp = va_arg(lst, char *);
		if (!tmp)
		{
			ft_putstr_fd("(null)", 1);
			return (6);
		}
		ft_putstr_fd(tmp, 1);
		return (ft_strlen(tmp));
	}
	else if (choice == 'i' || choice == 'd')
		return (ft_putnbr(va_arg(lst, int)));
	else if (choice == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	else
		return (0);
}
