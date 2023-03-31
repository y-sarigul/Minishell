#include "../../inc/minishell.h"
#include <stdio.h>

static void ft_lexerparser(t_shell **shell)
{
    char *buff;

    buff = (*shell)->cmd.line;
    while (*buff){
        if (*buff == '>'){

        }
    }
}

void ft_lexer(t_shell **shell)
{
    printf("%s\n", (*shell)->cmd.line);
}
