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
int nm_pile_a(int index, t_num **pile_a)
{
    if (index > my_lstlen(pile_a) / 2)
        return (index - my_lstlen(pile_a));
    return (index);
}
//fonction qui return l index dans la pile_a du normbre le plus rapide a placer dans la pile_b
int find_quicker(t_num *pile_a, t_num **pile_b)
{
    int index;
    int total;
    int temp_total;
    int i;

    total = absolue(nm_pile_b(pile_a->num, pile_b)) + absolue(nm_pile_a(0, &pile_a));
    pile_a = pile_a->next;
    index = 0;
    i = 1;
    while (pile_a != NULL)
    {
        temp_total= absolue(nm_pile_a(i, &pile_a)) + absolue(nm_pile_b(pile_a->num, pile_b));
        if (total > temp_total)
        {
            total = temp_total;
            index = i;
        }
        pile_a = pile_a->next;
        i++;
    }
    return (index);
}
int place_in_b(t_num **pile_a, t_num **pile_b)
{
    int m_a;
    int m_b;
    int count;
    
    count = 0;
    m_a = nm_pile_a(find_quicker(*pile_a, pile_b), pile_a);
    m_b = nm_pile_b(pile_a[0]->num, pile_b);
    if (m_a < 0 && m_b < 0)
    {
        while (m_a != 0 && m_b != 0)
        {
            rrr(pile_a, pile_b);
            m_a++;
            m_b++;
            count++;
        }
    }
    else if (m_a > 0 && m_b > 0)
    {
        while (m_a != 0 && m_b != 0)
        {
            rrr(pile_a, pile_b);
            m_a--;
            m_b--;
            count++;
        }
    }
    if (m_b < 0)
    {
        while (m_b != 0)
        {
            rrb(pile_b);
            m_b++;
            count++;
        }
    }
    else if (m_b > 0)
    {
        while (m_b != 0)
        {
            rb(pile_b);
            m_b--;
            count++;
        }
    }
    if (m_a < 0)
    {
        while (m_a != 0)
        {
            rra(pile_a);
            m_a++;
            count++;
        }
    }
    else if (m_a > 0)
    {
        while (m_a != 0)
        {
            ra(pile_a);
            m_a--;
            count++;
        }
    }
    pb(pile_a, pile_b);
    return (count);
}
int sorting(t_num **pile_a, t_num **pile_b)
{
    int count;
    
    count = 0;
    pb(pile_a, pile_b);
    pb(pile_a, pile_b);
    while (my_lstlen(pile_a) != 2)
        count += place_in_b(pile_a, pile_b);
    return (count);
}
void test(t_num **pile_a, t_num **pile_b)
{
    int count;

    count = sorting(pile_a, pile_b);
    print(*pile_a);
    print(*pile_b);
    ft_printf("CounT: %d\n", count);
}
