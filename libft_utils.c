#include "include/stack.h"
#include <stdio.h>
#include <stdlib.h>

int	test_str(char c, char *str)
{
	while (*str != '\0')
	{
		if (*str++ == c)
			return (1);
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;
	int				result;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	result = 0;
	while (i < n)
	{
		if (str1[i] != str2[i] || str1[i] == '\0')
		{
			result = str1[i] - str2[i];
			break ;
		}
		i++;
	}
	if (result > 0)
		result = 1;
	else if (result < 0)
		result = -1;
	return (result);
}

int	ft_atoi(const char *str)
{
	long	tmp_result;
	int		result;
	int		check;

	result = 0;
	check = 1;
	while (test_str(*str, "\t\n\v\f\r "))
		str++;
	if (test_str(*str, "-+"))
		if (*str++ == '-')
			check = -1;
	while (*str >= '0' && *str <= '9')
	{
		tmp_result = ((long)(result)) * 10 + ((long)(*str - '0'));
		if (check == 1 && tmp_result >= 2147483648 || tmp_result >= 2147483649)
		{
			printf("Error\n");
			exit(-1);
		}
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result * check);
}

void	ft_memset()
{
	//...
}

void	show_results(t_node *headA, t_node *headB)
{
	int i;

	printf("============================================\n");
	printf("--------STACK_A-------|\n");
	i = 1;
	while (headA)
	{
		printf("Element(A)[%i]->%i      |\n", i, headA->value);
		headA = headA->next;
		i++;
	}
	printf("----------------------|\n\n");
	printf("--------STACK_B-------|\n");
	i = 1;
	while (headB)
	{
		printf("Element(B)[%i]->%i      |\n", i, headB->value);
		headB = headB->next;
		i++;
	}
	printf("----------------------|\n");
	printf("============================================\n\n");
}