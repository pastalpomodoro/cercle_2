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

// parsing
int parsing(int ac, char **av, t_num **pile_a);

//moove
void sa(t_num **pile_a);
void sb(t_num **pile_b);
void ss(t_num **pile_a, t_num **pile_b);

int pb(t_num **pile_a, t_num **pile_b);
int pa(t_num **pile_a, t_num **pile_b);

int ra(t_num **pile_a);
int rb(t_num **pile_b);
int rr(t_num **pile_a, t_num **pile_b);

int rra(t_num **pile_a);
int rrb(t_num **pile_b);
int rrr(t_num **pile_a, t_num **pile_b);

//algo utils
int absolue(int n);
int if_smaller(t_num *pile, int n);
int if_bigger(t_num *pile, int n);
int find_index_smaller(t_num *pile);
int find_index_biggher(t_num *pile);

int nm_pile_b(int n, t_num **pile_b);
int nm_pile_a(t_num **pile_a, t_num **pile_b);

void test(t_num **pile_a, t_num **pile_b);

#endif