#include "../../inc/minishell.h"

/*
 * Listemi olusturuyorum ve her bir kelimeyi bir struct icerisinde tutuyorum
 * bunlarida birbirine bagliyorum 
 * Buradaki onemli nokta kullanacagim operatorlerin argumanlar ile 
 * Bitisik yazilmasina dikkat etmek
 * Bunlarida ft_check_type ile halletmeyi planliyorum
 */
void addlst_lexer(t_cmdline **cmd, t_shell **shell, size_t size)
{
    t_cmdline *iter;
    size_t i;

    i = 0;
    iter = (*cmd);
    while (size--)
    {
        cmdline_addlst_back(cmd, cmdline_new_list((*shell)->input.splited_line[i], 0, shell));
        i++;
    }
}

