#ifndef STACK_H
# define STACK_H

typedef struct      s_node
{
    int             value;
    struct s_node   *next; 
}t_node;

t_node  *create_node(int value);

void    push_element(t_node **head, t_node *elem);
void    push(t_node **headA, t_node **headB);

#endif