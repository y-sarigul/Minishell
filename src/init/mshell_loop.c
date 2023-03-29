#include "../../inc/minishell.h"
#include <stdio.h>

void ft_mshell_loop(t_shell **shell, char **envp)
{
    while (1){
        // This functions parser for pwd.
        // Return value is a line.
        // Its will show us where we are
        ft_parse_pwd(shell, envp);
        printf("%s => ", (*shell) -> pwd.line);
        (*shell) -> cmd.line = readline("");
    }
}
