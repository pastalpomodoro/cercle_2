/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgastelu <tgastelu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:21:42 by tgastelu          #+#    #+#             */
/*   Updated: 2024/12/05 17:23:13 by tgastelu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	my_lstlen(t_num **pile)
{
	t_num *temp;
	int 	count;

	count = 0;
	temp = *pile;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

void	free_lst(t_num **pile)
{
	t_num *lst;
	t_num *next;

	if (!pile)
		return ;
	lst = *pile;
	while (lst != NULL)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
}
void	my_ft_lstadd_back(t_num **lst, t_num *new)
{
	t_num	*temp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ; 
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}
t_num	*my_ft_lstnew(int num)
{
	t_num	*new;

	new = malloc(sizeof(t_num));
	if (!new)
		return (NULL);
	new->num = num;
	new->next = NULL;
	return (new);
}