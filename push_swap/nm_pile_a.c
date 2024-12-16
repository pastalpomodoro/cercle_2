#include "push_swap.h"

int nm_pile_a(t_num **pile_a, t_num **pile_b)
{
    int i;
    int count;
    int temp_count;
    t_num *temp;

    temp = *pile_a;
    count = nm_pile_b(temp->num, pile_b);
    i = 1;
    ft_printf("PILE_B MOOVE: %d\n", count);
    temp = temp->next;
    while (temp != NULL)
    {
        temp_count = nm_pile_b(temp->num, pile_b);
        if (i > my_lstlen(pile_a) / 2)
            i = my_lstlen(pile_a) - i + 1;
        ft_printf("INDEX: %d   NUM: %d\n", i, temp->num);
        temp_count += i;
        if (count > temp_count)
            count = temp_count;
        temp = temp->next;
        i++;
    }
    return (count);
}