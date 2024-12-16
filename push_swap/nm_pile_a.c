#include "push_swap.h"

int total_moove(int index, int num, t_num **pile_a, t_num **pile_b)
{
    if (index > my_lstlen(pile_a) / 2)
        index = -(my_lstlen(pile_a) - index);
    ft_printf("NUM: %d   INDEX: %d   P_B: %d\n", num, index, nm_pile_b(num, pile_b));
    return (index + nm_pile_b(num, pile_b));
}
int nm_pile_a(t_num **pile_a, t_num **pile_b)
{
    int i;
    int num;
    int count;
    int temp_count;
    t_num *temp;

    temp = *pile_a;
    count = total_moove(0, temp->num, pile_a, pile_b);
    temp = temp->next;
    i = 1;
    num = temp->num;
    while (temp != NULL)
    {
        temp_count = total_moove(i, temp->num, pile_a, pile_b);
        if (count > absolue(temp_count))
        {
            count = temp_count;
            num = temp->num;
        }
        temp = temp->next;
        i++;
    }
    ft_printf("\nNUM: %d   COUNT: %d", num, count);
    return (count);
}
