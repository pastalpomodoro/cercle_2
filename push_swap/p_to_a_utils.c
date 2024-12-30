#include"push_swap.h"

int *find_eight_bigghers(t_num *pile, int percent)
{
    int *tab;
    int i;

    tab = malloc(sizeof(int) * percent);
    if (!tab)
        return (NULL);
    i = 1;
    tab[0] = find_biggher(pile);
    while (i < percent)
    {
        tab[i] = find_under(pile, tab[i - 1]);
        i++;
    }
    return (tab);
}
int puscher(t_num **pile_a, t_num **pile_b)
{
    int count;

    count = 0;
    while (pile_b[0]->num > pile_a[0]->num)
        count += ra(pile_a);
    while (lst_last(*pile_a) != find_biggher(*pile_a) && lst_last(*pile_a) > pile_b[0]->num)
        count += rra(pile_a);
    count += pa(pile_a, pile_b);
    return (count);
}
int in(int *tab, int n, int percent)
{
    int i;

    i = -1;
    while (i++, i < percent)
    {
        if (n == tab[i])
            return (1);
    }
    return (0);
}
int if_new_tab(int *tab, t_num *pile, int percent)
{
    int i;

    while (pile)
    {
        i = 0;
        while (i < percent)
        {
            if (tab[i] == pile->num)
                return (0);
            i++;
        }
        pile = pile->next;
    }
    return (1);
}