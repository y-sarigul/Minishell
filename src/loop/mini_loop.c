#include "../../inc/minishell.h"

void mini_loop()
{
    t_shell *shell;

    while (1)
    {
        shell = (t_shell *)malloc(sizeof(t_shell));
        printf("minishell: ");
        shell->input.line = ft_split(readline(""), 32);
        parser(&shell);
        c_printlst_next((*shell).cmdline);
        printf("============================\n");
        printf("============================\n");
        c_printlst_prev((*shell).cmdline);
    }
}
