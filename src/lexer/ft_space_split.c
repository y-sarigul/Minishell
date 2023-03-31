#include "../../inc/minishell.h"
#include <stdio.h>

// cat > a.txt | grep deneme
// bosluklari 

void ft_space_split(t_shell **shell)
{
    if (!(*shell)->cmd.line)
        ft_error("I dont know command line");
    (*shell)->cmd.splited_line = ft_split((*shell)->cmd.line, ' ');
    ft_addlst_lexer(shell);
}
