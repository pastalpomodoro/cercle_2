#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct t_num
{
    int num;
    struct t_num *next;
}               t_num;


# include"../../cercle_1/libft/libft.h"
# include"../../cercle_1/printf/ft_printf.h"
#include<stdlib.h>
#include<unistd.h>

//utils
int 	my_lstlen(t_num **pile);
void	free_lst(t_num **pile);
void	my_ft_lstadd_back(t_num **lst, t_num *new);
t_num	*my_ft_lstnew(int num);
int lst_last(t_num *pile);

// parsing
int parsing(int ac, char **av, t_num **pile_a);

//moove
int sa(t_num **pile_a);
int sb(t_num **pile_b);
int ss(t_num **pile_a, t_num **pile_b);

int pb(t_num **pile_a, t_num **pile_b);
int pa(t_num **pile_a, t_num **pile_b);

int ra(t_num **pile_a);
int rb(t_num **pile_b);
int rr(t_num **pile_a, t_num **pile_b);

int rra(t_num **pile_a);
int rrb(t_num **pile_b);
int rrr(t_num **pile_a, t_num **pile_b);

//algo utils
int find_index(t_num *pile, int num);
int if_smaller(t_num *pile, int n);
int if_bigger(t_num *pile, int n);
int find_index_smaller(t_num *pile);
int find_index_biggher(t_num *pile);

//find_mediane
int find_biggher(t_num *pile);
int find_under(t_num *pile, int n);
int find_mediane(t_num *pile_a);

//p_to_a_utils
int *find_eight_bigghers(t_num *pile, int percent);
int puscher(t_num **pile_a, t_num **pile_b);
int in(int *tab, int n, int percent);
int if_new_tab(int *tab, t_num *pile, int percent);

//p_to_b_utils
int small_sort(t_num **pile_a);
int if_three_biggher(t_num *pile, int c);

#endif