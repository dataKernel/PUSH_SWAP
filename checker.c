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

int main(int argc, char *argv[])
{
	// heads definitions
	t_node  *headA;
	t_node  *headB;
	t_node	*nodeCreation;
	int i;

	headA = NULL;
	headB = NULL;
	i = 1;
    //protection des arguments via main
    if(argc <= 1)
        return(-1);
	while (i < argc)
	{       
		nodeCreation = create_node(ft_atoi(argv[i]));
        push_element(&headB, nodeCreation);
		i++;
	}
	push(&headB, &headA);
	i = 1;
	while(headA)
	{
		printf("Element(A)[%i]->%i\n", i, headA->value);
		headA = headA->next;
		i++;
	}
	i = 1;
	while(headB)
	{
		printf("Element(B)[%i]->%i\n", i, headB->value);
		headB = headB->next;
		i++;
	}
	return (0);
}