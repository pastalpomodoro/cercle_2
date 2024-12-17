#include "push_swap.h"

void print(t_num *pile)
{
    while (pile != NULL)
    {
        ft_printf("%d  ", pile->num);
        pile = pile->next;
    }
    ft_printf("\n");
}
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
int p_to_a(t_num **pile_a, t_num **pile_b)
{
    int count;

    count = 0;
    while (my_lstlen(pile_b) != 0)
    {
        if (find_index_biggher(*pile_b) > my_lstlen(pile_b) / 2)
        {
            rra(pile_b);
            count++;
        }
        if (if_bigger(*pile_b, pile_b[0]->num))
            pa(pile_a, pile_b);
        else
        {
            if (find_index_biggher(*pile_b) > my_lstlen(pile_b) / 2)
                rra(pile_b);
            else
                rb(pile_b);
        }
        count++;
    }
    return (count);
}
int p_to_b(t_num **pile_a, t_num **pile_b)
{
    int mediane;
    int count;

    count = 0;
    while (my_lstlen(pile_a) != 3)
    {    
        mediane = find_mediane(*pile_a);
        while (if_smaller(*pile_a, mediane) == 0 && my_lstlen(pile_a) != 3)
        {
            if (pile_a[0]->num < mediane)
                pb(pile_a, pile_b);
            else
                ra(pile_a);
            count++;
        }
    }
    count += small_sort(pile_a);
    count += p_to_a(pile_a, pile_b);
    return (count);
}
void test(t_num **pile_a, t_num **pile_b)
{
    int count;

    count = p_to_b(pile_a, pile_b);
    // ft_printf("\n");
    print(*pile_a);
    // ft_printf("COUNT: %d", count);
}
