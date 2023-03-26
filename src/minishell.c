#include "../inc/minishell.h"
#include <stdio.h>

int main (int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;
    t_shell *shell;

    if (!shell)
        shell = (t_shell *)malloc(sizeof(t_shell));

    // This functions parser for pwd.
    // Return value is a line.
    // Its will show us where we are
    ft_parse_pwd(&shell, envp);
    //looping shell program
    ft_mshell_loop(shell);

    return 0;
}
