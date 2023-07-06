#ifndef STACK_UTILS_H
# define STACK_UTILS_H

# define END_OF_LINE ' '
# define END_OF_FILE '\n'

# include "stack.h"
# include <string.h>
# include <stdbool.h>


/**
 * @brief copy the list values and return the reference allocated to the HEAP
 * @param head ptr on `t_node` given as the HEAD
 * @return return heap reference with list copied
*/
t_node  *copy_head(t_node *head);

/**
 * @brief init the list based on the arguments given by the program
 * @param head ptr on ptr on `t_node` given as the HEAD
 * @param argc integer representing the numbers of arguments given by the prog
 * @param argv string array representing the values of arguments given by the prog
 * @return VOID
 */
void	init_list(t_node **head, int argc, char *argv[]);

/**
 * @brief print values and element indexation to each nodes from
 * both HEAD provided
 * @param headA ptr on `t_node` given as the copy of the HEAD
 * @param headB ptr on `t_node` given as the copy of the HEAD
 * @return VOID
 */
void	show_results(t_node *headA, t_node *headB);

/**
 * @brief check from the standard input what swap_function to call to apply on
 * stackA and stackB via 2 heads
 * @param headA ptr on ptr on `t_node` given as the HEAD
 * @param headB ptr on ptr on `t_node` given as the HEAD
 * @return VOID
 */
void	exec_swap_func(t_node **headA, t_node **headB);

/**
 * @brief call the right `base` function depending of the string provided
 * @param headA ptr on ptr on `t_node` given as the HEAD
 * @param headB ptr on ptr on `t_node` given as the HEAD
 * @param str ptr on `char` given as the string corresponding to the std intput
 * @return VOID
 */
void	func_choice_base(t_node **headA, t_node **headB, char *str);

/**
 * @brief call the right `advanced` function depending of the string  provided
 * @param headA ptr on ptr on `t_node` given as the HEAD
 * @param headB ptr on ptr on `t_node` given as the HEAD
 * @param str ptr on `char` given as the string corresponding to the std intput
 */
void	func_choice_advanced(t_node **headA, t_node **headB, char *str);

/**
 * @brief reorder 3 elem from the list, do nothing if there is not element or
 * just 1. use the swap functions to use the 2 stack to reorganize elements.
 * @param headA ptr on ptr on `t_node` given as the HEAD
 * @param headB ptr on ptr on `t_node` given as the HEAD
 * @return VOID
 */
void	sort_three_elem(t_node **headA);

/**
 * @brief slipting all values from headA to headB except for the last 3 values
 * @param headA ptr on ptr on `t_node` given as the HEAD
 * @param headB ptr on ptr on `t_node`given as the HEAD
 * @return VOID
*/
void    split_headA_and_headB(t_node **headA, t_node **headB);

/**
 * @brief insert values from headB into the right place in headA
 * @param headA ptr on ptr on `t_node` given as the HEAD
 * @param headB ptr on ptr on `t_node`given as the HEAD
 * @return VOID
*/
void    insertion_into_headA(t_node **headA, t_node **headB);

/**
 * @brief free the head and all the nodes from the HEAP
 * @param head ptr on ptr on `t_node` given as the HEAD
 * @return void
*/
void    free_list(t_node *head);

/**
 * @brief check that the list is ordered
 * @param head ptr on `t_node` given as the HEAD
 * @return boolean to know if it's ordered or not
*/
bool	check_list_is_ordered(t_node *head);

/**
 * @brief check inside the list with the value provided where to insert the elem via
 * his indexation.
 * @param headA ptr on `t_node` given as the HEAD
 * @param value integer from stack B
 * @return integer corresponding to the right index insertion
*/
int     check_index_insert(t_node *head, int value);

/**
 * @brief iterate the list from the HEAD to get the number of elements
 * contained by the list
 * @param head ptr on `t_node` given as the HEAD
 * @return VOID
 */
int		size_list(t_node *head);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		test_str(char c, char *str);
int		ft_atoi(const char *str);

#endif