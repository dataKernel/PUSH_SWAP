#ifndef STACK_UTILS_H
# define STACK_UTILS_H

#define END_OF_LINE ' '
#define END_OF_FILE '\n'

#include <string.h>
#include "stack.h"

/**
 * @brief init the list based on the arguments given by the program
 * @param head ptr on ptr on `t_node` given as the HEAD
 * @param argc integer representing the numbers of arguments given by the prog
 * @param argv string array representing the values of arguments given by the prog
 * @return VOID
*/
void    init_list(t_node **head, int argc, char *argv[]);

/**
 * @brief print values and element indexation to each nodes from 
 * both HEAD provided
 * @param headA ptr on `t_node` given as the copy of the HEAD
 * @param headB ptr on `t_node` given as the copy of the HEAD
 * @return VOID
*/
void    show_results(t_node *headA, t_node *headB);

/**
 * @brief iterate the list from the HEAD to get the number of elements
 * contained by the list
 * @param head ptr on ptr on `t_node` given as the HEAD
 * @return VOID 
*/
int     size_list(t_node **head);

int     ft_strncmp(const char *s1, const char *s2, size_t n);
int     test_str(char c, char *str);
int     ft_atoi(const char *str);

#endif