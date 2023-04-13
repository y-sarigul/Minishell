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
    //readlinedan gelen inputu struct input icerisine splitleyip
    //input.splited_line olarak atiyorum
    (*shell)->input.splited_line = ft_split((*shell)->input.line, ' ');
    // bu gelen linin sizini buluryorum
    size = ft_buff_size((*shell)->input.splited_line);
    // yeni bir liste olusturmak icin aldigim argumalarla beraber
    // addlst_lexer fonksiyonuna gonderiyorum ve listemi olusturuyorum
    addlst_lexer(&(*shell)->cmdline, shell, size);
    free((*shell)->input.splited_line);
}
