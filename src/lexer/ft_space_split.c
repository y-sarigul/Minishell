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
 * Burada input.splited_line icerisine readlinedan gelen input lini splitliyorum
 * ve bunu cift yonlu bagli liste olusturmak icin addlst_lexer icerisine
 * atiyorum.
 * */
void ft_space_split(t_shell **shell)
{
    int i;
    size_t size;
    t_cmdline *iter;

    i = 0;
    if (!(*shell)->input.line)
        ft_error("I dont know command line");
    (*shell)->input.splited_line = ft_split((*shell)->input.line, ' ');
    // cmd.splited_line icerisine duzegun bir sekilde aktarilip aktarilmadigina bakiyorum
    // ve burada bosluk koyuldugu zaman dogru oldugunu goruyorum
    // while (*(*shell)->cmd.splited_line)
    // {
    //     printf("%s\n", *(*shell)->cmd.splited_line);
    //     (*shell)->cmd.splited_line++;
    // }
    size = ft_buff_size((*shell)->input.splited_line);

    addlst_lexer(&(*shell)->cmdline, (*shell), size);
    //Burasini yeni ekledim sorun var gibi
    iter = (*shell)->cmdline;
    /*
     * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
     * Eger minishell e gelen cmd bosluk ile basliyor ise burda segment yiyor 
     * */
    while (iter -> next)
    {
        ft_check_type(shell, iter->value);
        iter = iter -> next;
    }
    free((*shell)->input.splited_line);
}
