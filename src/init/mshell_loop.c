#include "../../inc/minishell.h"

// static void ft_get_history(t_shell **shell, const char *line)
// {
//     if (!(line))
//         return ;

// }

void ft_mshell_loop(t_shell **shell, char **envp)
{
    while (1){
        // This functions parser for pwd.
        // Return value is a line.
        // Its will show us where we are
        ft_parse_pwd(shell, envp);
        printf("%s => ", (*shell) -> pwd.line);
        (*shell) -> cmd.line = readline("");
        // ft_get_history(shell, (*shell) ->cmd.line);
        printf("%s\n", (*shell) -> cmd.line);
    }
}
