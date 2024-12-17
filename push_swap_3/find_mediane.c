/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_mediane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgastelu <tgastelu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:57:26 by tgastelu          #+#    #+#             */
/*   Updated: 2024/12/17 15:13:54 by tgastelu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int num_of_smaller(t_num *pile_a, int num)
{
    int count;

    count = 0;
    while (pile_a != NULL)
    {
        if (pile_a->num < num)
            count++;
        pile_a = pile_a->next;
    }
    return (count);
}

int find_mediane(t_num *pile_a)
{
    int size;
    t_num *temp;

    temp = pile_a;
    size = my_lstlen(&pile_a) / 2;
    while (pile_a != NULL)
    {
        if (num_of_smaller(temp, pile_a->num) == size)
            break;
        pile_a = pile_a->next;        
    }
    return (pile_a->num);
}