/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgastelu <tgastelu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:21:10 by tgastelu          #+#    #+#             */
/*   Updated: 2024/12/03 20:17:57 by tgastelu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_free(char **tab, int size)
{
    while (size >= 0)
    {
        free(tab[size]);
        size--;
    }
    free(tab);
}

int check_max_min(char *num)
{
    long n;
    int i;
    int signe;

    i = 0;
    n = 0;
    signe = 1;
    if (num[i] == '-')
    {
        i++;
        signe = -1;
    }
    while (num[i])
    {
        if (!(num[i] <= '9' && num[i] >= '0'))
            return (ft_putstr("ERROR\nonly decimal number pls"), 0);
        n = n * 10 + num[i] - '0';
        i++;
    }
    n *= signe;
    if (n > 2147483647 || n < -2147483648)
        return (ft_putstr("ERROR:\nINT_MAX or MIN"), 0);
    return (1);
}
int check_double(char **tab, int z)
{
    int x;
    int y;
    int i;

    i = z;
    while (i++, tab[i])
    {
        y = z;
        while (y++, tab[y])
        {
            x = 0;
            while (tab[y][x] == tab[i][x] && tab[y][x] && i != y)
                x++;
            if (tab[i][x] == '\0' && tab[y][x] == '\0')
                return (0);
        }
    }
    return (1);
}
//RICORDARMI CHE DEFO FARE LA FUNZIONE CHE FREE TUTTI I NUDO DELLA LISTA SE check_max_min ==0
int fill_list(char **tab, t_num **pile_a, int ac)
{
    int y;

    if (ac > 2)
    {
        y = 0;
        while (y++, tab[y])
        {
            if (check_max_min(tab[y]) == 0)
                    return (0);
                my_ft_lstadd_back(pile_a,  my_ft_lstnew(ft_atoi(tab[y])));
        }
    }
    else if (ac == 2)
    {
        y = -1;
        while (y++, tab[y])
        {
            if (check_max_min(tab[y]) == 0)
                return (0);
            my_ft_lstadd_back(pile_a, my_ft_lstnew(ft_atoi(tab[y])));
        }
        ft_free(tab, y - 1);
    }
    return (1);
}
// void type_split
int parsing(int ac, char **av, t_num **pile_a)
{
    char **tab;

    if (ac > 2)
    {
        if (check_double(av, 0) == 0)
            return (ft_putstr("Two or more identical numbers"), 0);
        if (fill_list(av, pile_a, ac) == 0)
            return (0);
    }
    else if (ac == 2)
    {
        tab = ft_split(av[1], ' ');
        if (!tab)
            return (0);
        if (check_double(tab, -1) == 0)
            return (ft_putstr("Two or more identical numbers"), 0);
        if (fill_list(tab, pile_a, ac) == 0)
            return (0);
    }
    return (1);
}
