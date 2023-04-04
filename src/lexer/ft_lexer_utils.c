#include "../../inc/minishell.h"
#include <stdio.h>

// Her bir kelimeyi splitliyorum ve her bir harfin ne oldugunu kontor ediyorum
char **alphabet_parser(char *str)
{
    int i;
    int i2;
    int i3;
    char **tab;

    i = 0;
    i2 = 0;
    tab = (char**)malloc(sizeof(**tab) * 100);
    while (str[i] != '\0')
    {
        i3 = 0;
        tab[i2] = (char*)malloc(sizeof(char) * 100);
        tab[i2][i3] = str[i];
        i++;
        i3++;
        tab[i2][i3] = '\0';
        i2++;
    }

    tab[i2] = 0;
    return (tab);
}
/*
 * Burada bizlere gelen cmd linin icerisinde birlesik operator varmi onlari 
 * ayirarak gonderilen kelimenin tipini belirliyorum
 */
int ft_check_type(t_shell **shell, char *line)
{

    int i;
    char **buff;
    int triger;

    buff = alphabet_parser(line);

    i = 0;
    triger = 0;
    check_greater_than(shell, buff); // lstfunc
    less_than(shell, buff);

    return(0);
}
