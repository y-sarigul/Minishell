#include "../inc/minishell.h"
#include <stdio.h>

int main (int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;
    t_pwd *pwd;

    // This functions is parser for pwd.
    // Return value is a line.
    // Its will show us where we are
    ft_parse_pwd(&pwd, envp);
    printf("%s\n", pwd -> line);
    return 0;
    //samet was here
}
