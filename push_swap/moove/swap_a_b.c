#include "../push_swap.h"

void sa(t_num **pile_a)
{
    t_num *temp;
    int a;

    temp = *pile_a;
    if (*pile_a == NULL || temp->next == NULL)
        return ;
    temp = temp->next;
    a = temp->num;
    temp->num = pile_a[0]->num;
    pile_a[0]->num = a;
}
void sb(t_num **pile_b)
{
    t_num *temp;
    int a;

    temp = *pile_b;
    if (*pile_b == NULL || temp->next == NULL)
        return ;
    temp = temp->next;
    a = temp->num;
    temp->num = pile_b[0]->num;
    pile_b[0]->num = a;
}
void ss(t_num **pile_a, t_num **pile_b)
{
    sa(pile_a);
    sb(pile_b);
}