#include "../../inc/minishell.h"
#include <stdio.h>

// This functions parser for pwd.
// Return value is a line.
// Its will show us where we are
//
void ft_mshell_loop(t_shell **shell, char **envp)
{
    while (1){
        ft_parse_pwd(shell, envp);
        printf("%s => ", (*shell) -> pwd.line);
        (*shell) -> cmd.line = readline("");
        ft_save_history(shell, (*shell)->cmd.line);
        ft_lexer(shell);
    }
}
