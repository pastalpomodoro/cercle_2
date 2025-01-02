
#include "pipex.h"

int execution(char **command, char *outfile, char *infile)
{

    char *null;
    int fd_out;
    int fd_in;
    
    null = NULL;
    fd_in = open(infile, O_RDONLY | O_CREAT);
    if (!fd_in)
        return (ft_printf("Erreur durant la creation de fd_in"), 0);
    fd_out = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (!fd_out)
        return (ft_printf("Erreur durant la creation de fd_out"), 0);
    if (dup2(fd_in, STDIN_FILENO) < 0)
        return (ft_printf("Erreur durant l operation dup2 pour le infile"), 0);
    if (dup2(fd_out, STDOUT_FILENO) < 0)
        return (ft_printf("Erreur durant l operation dup2 pour le outfile"), 0);
    if (execve(command[0], command, &null) < 0)
    {
        perror("Erreur durant execve");
        return (close(fd_in), close(fd_out), 0);
    }
    close(fd_in);
    close (fd_out);
    return (1);
}

int start_command(char **command, char *outfile, char *infile)
{
    pid_t pid;

    pid = fork();
    if (pid < 0)
    {
        perror("Erreur durant l'initialisation de fork");
        return (0);   
    }
    else if (pid == 0)
    {
        if (!execution(command, outfile, infile))
            return (0);
    }
    else
        wait(NULL);
    return (1);
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
        return (ft_free(command1), 0);
    if (!start_command(command1, "file.txt", av[1]))
        return (ft_free(command1), 0);
    ft_free(command1);
    command2 = fill_command(av[3]);
    if (!command2)
        return (ft_free(command1), ft_free(command2), 0);
    if (!start_command(command2, av[4], "file.txt"))
        return (ft_free(command1), ft_free(command2), 0);
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