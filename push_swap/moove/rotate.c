#include"../push_swap.h"

int ra(t_num **pile_a)
{
    t_num *temp;
    t_num *temp1;

    temp = *pile_a;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = my_ft_lstnew(pile_a[0]->num);
    if (!temp->next)
        return (-1);
    temp1 = *pile_a;
    *pile_a = pile_a[0]->next;
    free(temp1);
    return (1);
}
int rb(t_num **pile_b)
{
    t_num *temp;
    t_num *temp1;

    temp = *pile_b;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = my_ft_lstnew(pile_b[0]->num);
    if (!temp->next)
        return (-1);
    temp1 = *pile_b;
    *pile_b = pile_b[0]->next;
    free(temp1);
    return (1);
}

int rr(t_num **pile_a, t_num **pile_b)
{
    if (ra(pile_a) == -1)
        return (-1);
    if (rb(pile_b) == -1)
        return (-1);
    return (1);
}