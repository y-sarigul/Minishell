#include "../../inc/minishell.h"
#include <stdio.h>

// Burada cift pointerin buyuklugunu bulmaya calisiyorum
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

/*
 * Burada cmd.splited_line icerisine readlinedan gelen cmd lini splitliyorum
 * ve bunu cift yonlu bagli liste olusturmak icin ft_addlst_lexer icerisine
 * atiyorum.
 * */
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
