#include "stack.h"
#include <stdio.h>
#include <unistd.h>

static int	test_str(char c, char *str)
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
	int	result;
	int	check;

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

int	main(int argc, char *argv[])
{
	// checking values from args
	printf("nbr args: %i\n", argc);
	for (int i = 1; i < argc; i++)
		printf("argv[%i]-->%s\n", i, argv[i]);
	// heads definitions
	t_node  *headA;
	t_node  *headB;
	// node definitions
	t_node  *nodeA;
	t_node  *nodeB;
	int i;

	headA = NULL;
	headB = NULL;
	i = 1;
    //protection des arguments via main
    if(argc <= 1)
        return(-1);
	while (i < argc)
	{
        
		nodeA = create_node(ft_atoi(argv[i]));
        //check(debug)
        push(&headA, nodeA);
		i++;
	}
    printf("%i", headA->next->next->value);
	return (0);
}