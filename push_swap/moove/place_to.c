#include "../push_swap.h" 

int my_lst_add_front(t_num **pile_a, t_num **pile_b)
{
    t_num *new;

    new = my_ft_lstnew(pile_a[0]->num);
    if (!new)
        return (-1);
    new->next = *pile_b;
    *pile_b = new;
    return (1);
}

int pb(t_num **pile_a, t_num **pile_b)
{
    t_num *temp;

    if (*pile_a == NULL)
        return (0);
    if (my_lst_add_front(pile_a, pile_b) == -1)
        return (-1);
    temp = *pile_a;
    *pile_a = pile_a[0]->next;
    free(temp);
    ft_printf("pb\n");
    return (1);
}
int pa(t_num **pile_a, t_num **pile_b)
{
    t_num *temp;

    if (*pile_b == NULL)
        return (1);
    if (my_lst_add_front(pile_b, pile_a) == -1)
        return (-1);
    temp = *pile_b;
    *pile_b = pile_b[0]->next;
    free(temp);
    ft_printf("pa\n");
    return (1);
}