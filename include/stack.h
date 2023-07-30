/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: data_kernel <data_kernel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:50:03 by data_kernel       #+#    #+#             */
/*   Updated: 2023/07/30 18:47:43 by data_kernel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "stdbool.h"

typedef struct s_node
{
	int				value;
	int				state;
	struct s_node	*next;
}t_node;

typedef struct s_rotate_and_reverse
{
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
}t_rotate_and_reverse;

typedef struct s_index_and_value
{
	int				index;
	int				value;
}t_index_and_value;

/**
 * @brief create a node on the `HEAP` who returns a ptr on `t_node`
 * with the given value
 * @param value integer given as value
 * @return return a ptr `t_node` from the heap
 */
t_node	*create_node(int value);

/**
 * @brief Take out the first element of the list(src),
 * and return it, while pointing the elem to NULL.
 * @param head ptr on the first elem of the list.
 * @return the first element of the list
 */
t_node	*pop(t_node **head);

/**
 * @brief push a node at the top of the stack(head) and link all the others nodes
 * between them until null (used to init the list)
 * @param head ptr on ptr on `t_node` given as the HEAD
 * @param elem ptr on `t_node` given as a node element
 * @return `VOID`
 */
void	push_element(t_node **head, t_node *elem);

/**
 * @brief take the first element of the list(headB) and push it
 * to an other list on the top of it(headA). Don't do anything if src is empty
 * @param headB ptr on ptr on `t_node` given as the HEAD->source
 * @param headA ptr on ptr on `t_node`given as the HEAD->destination
 * @return `VOID`
 */
void	push_a(t_node **headB, t_node **headA);

/**
 * @brief take the first element of the list(headA) and push it
 * to an other list on the top of it (headB). Don't do anything if src is empty
 * @param headA ptr on ptr on `t_node` given as the HEAD->source
 * @param headB ptr on ptr on `t_node` given as the HEAD->destination
 * @return VOID
*/
void	push_b(t_node **headA, t_node **headB);

/**
 * @brief swap the node value contained by the head with the 2nd node 
 * for both list
 * @param headA ptr on ptr on `t_node` given as the HEAD
 * @param headB ptr on ptr on `t_node` given as the HEAD
 * return VOID
 */
void	swap_all(t_node **headA, t_node **headB);

/**
 * @brief swap the node value contained by the head with the 2nd node on the list
 * Check if the head or the next element are NULL so meaning that the list has at
 * least a size of 2
 * @param copy boolean to check the swap is done on src or copy
 * @param headA ptr on ptr on `t_node` given as the HEAD
 * @return `VOID`
 */
void	swap_a(t_node **headA, bool copy);

/**
 * @brief swap the node value contained by the head with the 2nd node on the list
 * Check if the head of the next element are NULL so meaning that the list has at
 * least a size of 2
 * @param headB ptr on ptr on `t_node` given as the HEAD
 * @return VOID
*/
void	swap_b(t_node **headB);

/**
 * @brief shift of one position all the elements of the list from headA
 * to the top
 * @param headA ptr on ptr on `t_node` given as the HEAD
 * @return `VOID`
 */
void	rotate_a(t_node **headA);

/**
 * @brief shift of one position all the elements of the list 
 * from headB to the top
 * @param headB ptr on ptr on `t_node` given as the HEAD
 * @return `VOID`
 *
*/
void	rotate_b(t_node **headB);

/**
 * @brief shift of one position all the elements of the list A to to bottom
 * @param head ptr on ptr on `t_node` given as the HEAD A
 * @return `VOID`
 */
void	reverse_a(t_node **head);

/**
 * @brief shift of one position all the elements of the list B to the bottom
 * @param head ptr on ptr on `t_node` given as the HEAD B
 * @return `VOID`
*/
void	reverse_b(t_node **head);

/**
 * @brief shift of one position all the elements of the both list to the top
 * @param headA ptr on ptr on `t_node` given as the HEAD
 * @param headB ptr on ptr on `t_node` given as the HEAD
 * @return `VOID`
 */
void	rotate_all(t_node **headA, t_node **headB);

/**
 * @brief shift of one position all the elements of the both list to the top
 * @param headA ptr on ptr on `t_node` given as the HEAD
 * @param headB ptr on ptr on `t_node` given as the HEAD
 * @return `VOID`
 */
void	reverse_all(t_node **headA, t_node **headB);

#endif