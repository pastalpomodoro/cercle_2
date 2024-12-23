#include "push_swap.h"

int absolue(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}
// fonction qui permet de comprendre sy le numero passe en parametre est le plus petit de toute la pile
int if_smaller(t_num *pile, int n)
{
    while (pile != NULL)
    {
        if (n > pile->num)
            return (0);
        pile = pile->next;
    }
    return (1);
}
// fonction qui permet de comprendre sy le numero passe en parametre est le plus grand de toute la pile
int if_bigger(t_num *pile, int n)
{
    while (pile != NULL)
    {
        if (n < pile->num)
            return (0);
        pile = pile->next;
    }
    return (1);
}
int find_index_smaller(t_num *pile)
{
    t_num *temp;
    int    size;

    temp = pile;
    size = 0;
    while (pile != NULL)
    {
        if (if_smaller(temp, pile->num) == 1)
            return (size);
        size++; 
        pile = pile->next;
    }
    return (0);
}
int find_index_biggher(t_num *pile)
{
    t_num *temp;
    int    size;

    temp = pile;
    size = 0;
    while (pile != NULL)
    {
        if (if_bigger(temp, pile->num) == 1)
            return (size);
        size++; 
        pile = pile->next;
    }
    return (0);
}
int find_index(t_num *pile, int n)
{
    int i;

    i = 0;
    while (pile)
    {
        if (pile->num == n)
            return (i);
        pile = pile->next;
        i++;
    }
    return (-1);
}
