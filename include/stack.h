#ifndef STACK_H
# define STACK_H

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

/**
 * @brief create a node on the `HEAP` who returns a ptr on `t_node` with the given value
 * @param value integer given as value
 * @return return a ptr `t_node` from the heap
 */
t_node  *create_node(int value);
/**
 * @brief Take out the first element of the list(src),
 * and return it, while pointing the elem to NULL.
 * @param head ptr on the first elem of the list.
 * @return the first element of the list 
 */
t_node  *pop(t_node **head);
/**
 * @brief push a node at the top of the stack(head) and link all the others nodes between them until null (used to init the list)
 * @param head ptr on ptr on `t_node` given as the HEAD
 * @param elem ptr on `t_node` given as a node element
 * @return `VOID`
 */
void    push_element(t_node **head, t_node *elem);
/**
 * @brief take the first element of the list(src) and push it to an other list on the top of it(dst). Don't do anything if src is empty.
 * @param src ptr on ptr on `t_node` given as the HEAD->source
 * @param dst ptr on ptr on `t_node`given as the HEAD->destination
 * @return `VOID`
 */
void    push(t_node **headA, t_node **headB);

#endif