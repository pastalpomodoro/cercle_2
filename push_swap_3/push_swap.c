/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgastelu <tgastelu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:57:33 by tgastelu          #+#    #+#             */
/*   Updated: 2024/12/05 16:20:09 by tgastelu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void checker(t_num *pile)
{
    int temp;
    const char *red = "\033[1;31m";
    const char *reset = "\033[0m";
    const char *message = "KO  %d: \n";
    const char *green = "\033[1;32m";


    temp = 0;
    while (pile != NULL)
    {
        temp = pile->num;
        pile = pile->next;
        if (pile && temp > pile->num)
        {
            ft_printf(red);
            ft_printf(message, pile->num);
            ft_printf(reset);
            return ;
        }
    }
    ft_printf(green);
    ft_printf("OK\n");
    ft_printf(reset);
}
int p_to_a(t_num **pile_a, t_num **pile_b, int percent)
{
    int *tab;
    int count;

    count = 0;
    tab = find_eight_bigghers(*pile_b, percent);
    if (!tab)
        exit(0);
    while (my_lstlen(pile_b) > 0)
    {
        if (if_new_tab(tab, *pile_b, percent))
        {
            free(tab);
            tab = find_eight_bigghers(*pile_b, percent);
        }
        if (in(tab, pile_b[0]->num, percent))
            count += puscher(pile_a, pile_b);
        else if (find_index_biggher(*pile_b) > my_lstlen(pile_b) / 2)
            count += rrb(pile_b);
        else
            count += rb(pile_b);
    }
    while (lst_last(*pile_a) != find_biggher(*pile_a))
        count += rra(pile_a);
    free(tab);
    return (count);
}

int p_to_b(t_num **pile_a, t_num **pile_b, int percent)
{
    int mediane;
    int count;

    count = 0;
    mediane = find_mediane(*pile_a);
    while (my_lstlen(pile_a) > 3)
    {
        if (if_smaller(*pile_a, mediane))
            mediane = find_mediane(*pile_a);
        if (if_three_biggher(*pile_a, pile_a[0]->num) == 0 && pile_a[0]->num < mediane)
            count += pb(pile_a, pile_b);
        else
            count += ra(pile_a);
    }
    count += small_sort(pile_a);
    count += p_to_a(pile_a, pile_b, percent);
    return (count);
}
int push_swap(t_num **pile_a, t_num **pile_b, int percent)
{
    int count;

    count = p_to_b(pile_a, pile_b, percent);
    ft_printf("COUNT: %d\nP: %d\n", count, percent);
    return (count);
}

int main(int ac, char **av)
{
    t_num *pile_a;
    t_num *pile_b;
    
    pile_b = NULL;
    if (ac <= 1)
        return (ft_putstr("Missing Argumets!!"), 0);
    pile_a = NULL;
    if (parsing(ac, av, &pile_a) == 0)
        return (0);
    push_swap(&pile_a, &pile_b, my_lstlen(&pile_a) * 8 / 100);
    free_lst(&pile_a);
    free_lst(&pile_b);
    return (1);
}
