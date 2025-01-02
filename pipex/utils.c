#include"pipex.h"

int size_double_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i]!= NULL)
        i++;
    return (i);
}
void ft_free(char **tab)
{
    int i;

    i = size_double_tab(tab);
    while (i > 0)
        free(tab[--i]);
    free(tab);
}