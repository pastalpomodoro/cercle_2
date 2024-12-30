#include "push_swap.h"

int small_sort(t_num **pile_a)
{
    int count;
    t_num *temp;

    count = 0;
    if (if_bigger(*pile_a, pile_a[0]->num))
    {
        ra(pile_a);
        count++;
    }
    temp = pile_a[0]->next;
    if (if_bigger(*pile_a, temp->num))
    {
        rra(pile_a);
        count++;
    }
    temp = pile_a[0]->next;
    if (pile_a[0]->num > temp->num)
    {
        sa(pile_a);
        count++;
    }
    return (count);
}

int if_three_biggher(t_num *pile, int c)
{
    int num;
    int n;

    n = c;
    num = find_biggher(pile);
    if (n == num)
        return (1);
    num = find_under(pile, find_biggher(pile));
    if (n == num)
        return (1);
    num = find_under(pile, find_under(pile, find_biggher(pile)));
    if (n == num)
        return (1);
    return (0);
}