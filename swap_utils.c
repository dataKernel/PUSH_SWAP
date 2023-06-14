#include "include/stack.h"

int	test_str(char c, char *str)
{
	while (*str != '\0')
	{
		if (*str++ == c)
			return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int result;
	int check;

	result = 0;
	check = 1;
	while (test_str(*str, "\t\n\v\f\r "))
		str++;
	if (test_str(*str, "-+"))
		if (*str++ == '-')
			check = -1;
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result * check);
}

int	size_list(t_node *head)
{
	int		size;

	size = 0;
	while(head)
	{
		head = head->next;
		size++;
	}
	return(size);
}