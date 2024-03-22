#include "libft.h"

void ft_lstadd_front(t_list **list, t_list *new)
{
    t_list *temp_position;

    temp_position = *list;
    *list = new;

    new->next = temp_position;
}