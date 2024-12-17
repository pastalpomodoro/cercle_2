#include "push_swap.h"

int find_index_under(t_num *pile, int n)
{
    t_num *temp;
    int small;
    int i;

    small = -2147483648;
    temp = pile;
    while (pile != NULL)
    {
        if (pile->num < n && small <= pile->num)
            small = pile->num;
        pile = pile->next;
    }
    i = 0;
    while (temp != NULL)
    {
        if (temp->num == small)
            break;
        i++;
        temp = temp->next;
    }
    return (i);
}
int find_index_upper(t_num *pile, int n)
{
    t_num *temp;
    int big;
    int i;

    big = 2147483647;
    temp = pile;
    while (pile != NULL)
    {
        if (pile->num > n && big >= pile->num)
            big = pile->num;
        pile = pile->next;
    }
    i = 0;
    while (temp != NULL)
    {
        if (temp->num == big)
            break;
        i++;
        temp = temp->next;
    }
    return (i);
}
//fonction qui definis le nombre de mouvement pour l index small donne return un nombre negatif sy il faut rra et un nombre positif sy il faut ra
int nm_small(t_num *pile, int small)
{
    if (small >= my_lstlen(&pile) / 2)
        return (small - my_lstlen(&pile));
    else
        return (small);
}
int nm_big(t_num *pile, int big)
{
    if (big >= my_lstlen(&pile) / 2)
        return (big - my_lstlen(&pile) + 1);
    else
        return (big + 1);
}
//fonction a la quel on va envoyer le numero a comparer pour savoir sy
//c'est celui avec le moins de mouvemenet
int nm_pile_b(int n, t_num **pile_b)
{
    int small;
    int big;

    small = 0;
    big = 0;
    if (if_smaller(*pile_b, n) == 1) // gerer le cas ou c est le plus petit et ou c est le plus grand 
        return (nm_big(*pile_b, find_index_upper(*pile_b, n)));
    else
        small = find_index_under(*pile_b, n);
    if (if_bigger(*pile_b, n) == 1)
        return (nm_small(*pile_b, find_index_under(*pile_b, n)));
    else
        big = find_index_upper(*pile_b, n);
    big = nm_big(*pile_b, big);
    small = nm_small(*pile_b, small);
    if (absolue(small) < absolue(big))
        return (small);
    return (big);
}
