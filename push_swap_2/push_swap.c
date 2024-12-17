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



int main(int ac, char **av)
{
    t_num *pile_a;
    t_num *pile_b;
    
    pile_b = malloc(sizeof(t_num));
    if (!pile_b)
        return (0);
    pile_b = NULL;
    if (ac <= 1)
        return (ft_putstr("Missing Argumets!!"), 0);
    pile_a = NULL;
    if (parsing(ac, av, &pile_a) == 0)
        return (0);
    test(&pile_a, &pile_b);
    free_lst(&pile_a);
    free_lst(&pile_b);
    return (1);
}
