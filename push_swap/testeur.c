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

int sorting(t_num **pile_a, t_num **pile_b)
{
    int count;
    
    pb(pile_a, pile_b);
    pb(pile_a, pile_b);
    pb(pile_a, pile_b);
    pb(pile_a, pile_b);
    pb(pile_a, pile_b);
    pb(pile_a, pile_b);
    pb(pile_a, pile_b);
    pb(pile_a, pile_b);
    pb(pile_a, pile_b);
    pb(pile_a, pile_b);
    count = 10;
    return (count);
}
void test(t_num **pile_a, t_num **pile_b)
{

    sorting(pile_a, pile_b);
    print(*pile_a);
    print(*pile_b);
    nm_pile_a(pile_a, pile_b);
}
