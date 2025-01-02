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
char **add_bin(char **no_bin)
{
    int size;
    int i;
    char **commands;

    i = 0;
    size = size_double_tab(no_bin);
    commands = malloc(sizeof(char *) * (size + 1));
    commands[i] = ft_strjoin("/bin/", no_bin[i]);
    while (++i, no_bin[i])
        commands[i] = ft_strdup(no_bin[i]);
    commands[i] = NULL;
    return (commands);
}