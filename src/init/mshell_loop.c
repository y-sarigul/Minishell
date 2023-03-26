#include "../../inc/minishell.h"
#include <stdio.h>

void ft_mshell_loop(t_shell *shell)
{
    while (1){
        printf("%s => ", shell -> pwd.line);
        getchar();
        printf("\n");
    }
}
