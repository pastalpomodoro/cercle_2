
#include "pipex.h"

// char **add_bin(char **no_bin, char *infile)
// {
//     int size;
//     int i;
//     char **commands;

//     i = 0;
//     size = size_double_tab(no_bin);
//     commands = malloc(sizeof(char *) * (size + 2));
//     commands[i] = ft_strjoin("/bin/", no_bin[i]);
//     while (++i, no_bin[i])
//         commands[i] = ft_strdup(no_bin[i]);
//     commands[i] = ft_strdup(infile);
//     commands[i + 1] = NULL;
//     return (commands);
// }

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
void second_command(char **command, char *outfile, char *infile)
{
    pid_t pid;
    char *null;
    int fd_out;
    int fd_in;
    
    fd_in = open(infile, O_RDONLY | O_CREAT);
    fd_out = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    null = NULL;
    pid = fork();
    if (pid < 0)
    {
        perror("Erreur durant l'initialisation de fork");
        close(fd_in);
        close(fd_out);
        return ;   
    }
    else if (pid == 0)
    {
        dup2(fd_in, STDIN_FILENO);
        dup2(fd_out, STDOUT_FILENO);
        if (execve(command[0], command, &null) < 0)
        {
            close(fd_in);
            close (fd_out);
            perror("Erreur durant execve");
            return ;
        }
    }
    else
        wait(NULL);
    close(fd_out);
    close(fd_in);
}

char **fill_command(char *com)
{
    char **no_bin;
    char **commande;

    no_bin = ft_split(com, ' ');
    if (!no_bin)
        return (ft_printf("Erreur durant le split de no_bin"), NULL);
    commande = add_bin(no_bin);
    if (!commande)
    {
        ft_free(no_bin);
        return (ft_printf("Erreur durant le split de command"), NULL);
    }
    else
        ft_free(no_bin);
    return (commande);
}

int pipex(char **av)
{
    char **command1;
    char **command2;

    command1 = fill_command(av[2]);
    if (!command1)
        return (0);
    second_command(command1, "file.txt", av[1]);
    ft_free(command1);
    command2 = fill_command(av[3]);
    if (!command2)
        return (0);
    second_command(command2, av[4], "file.txt");
    ft_free(command2);
    return (1);
}
int main(int ac, char **av)
{
    if (ac < 5)
        return (ft_printf("Missing arguments!!"), 0);
    else if (ac == 5)
        pipex(av);
    else
        return (ft_printf("Too many arguments!!"), 0);
    return (0);
}