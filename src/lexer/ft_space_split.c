#include "../../inc/minishell.h"
#include <stdio.h>

// cat > a.txt | grep deneme
// bosluklari 
//
static size_t ft_buff_size(char **line)
{
    int i;

    i = 0;
    while (*line){
        i++;
        line++;
    }
    return (i);
}

void ft_space_split(t_shell **shell)
{
    int i;
    size_t size;

    i = 0;
    if (!(*shell)->cmd.line)
        ft_error("I dont know command line");
    (*shell)->cmd.splited_line = ft_split((*shell)->cmd.line, ' ');
    size = ft_buff_size((*shell)->cmd.splited_line);

    ft_addlst_lexer(shell, size);
    free((*shell)->cmd.splited_line);
}
