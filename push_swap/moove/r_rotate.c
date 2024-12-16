#include "../push_swap.h"
int rra(t_num **pile_a)
{
    t_num *new;
    t_num *pile;
    t_num *temp;

    pile = *pile_a;
    while (pile->next != NULL)
    {
        temp = pile;
        pile = pile->next;
    }
    new = my_ft_lstnew(pile->num);
    if (!new)
        return (-1);
    free(pile->next);
    free(pile);
    temp->next = NULL;
    new->next = *pile_a;
    *pile_a = new;
    return (1);
}
int rrb(t_num **pile_b)
{
    t_num *new;
    t_num *pile;
    t_num *temp;

    pile = *pile_b;
    while (pile->next != NULL)
    {
        temp = pile;
        pile = pile->next;
    }
    new = my_ft_lstnew(pile->num);
    if (!new)
        return (-1);
    free(pile->next);
    free(pile);
    temp->next = NULL;
    new->next = *pile_b;
    *pile_b = new;
    return (1);
}
int rrr(t_num **pile_a, t_num **pile_b)
{
    if (rra(pile_a) == -1)
        return (-1);
    if (rrb(pile_b) == -1)
        return (-1);
    return (1);
}