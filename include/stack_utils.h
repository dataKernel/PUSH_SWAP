#ifndef STACK_UTILS_H
# define STACK_UTILS_H

#define END_OF_LINE ' '
#define END_OF_FILE '\n'

#include <string.h>
#include "stack.h"

void    init_list(t_node **headA, int argc, char *argv[]);
void    show_results(t_node **headA, t_node **headB);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
int     test_str(char c, char *str);
int     ft_atoi(const char *str);
int     size_list(t_node **head);

#endif