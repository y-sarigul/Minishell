#include "../../inc/minishell.h"

// redirections'lari buldugumuzda bunlari cmd linin bulundugu konumdan
// sonraki konuma ekliyor
void ft_addlst_center(t_shell **shell, char *redirection)
{
    t_shell *iter;

    iter =(*shell);
    while (iter -> cmdline -> next)
        iter -> cmdline = iter -> cmdline -> next;
    iter -> cmdline -> next = (t_cmdline *)malloc(sizeof(t_cmdline));
    iter -> cmdline -> next -> value = redirection;
    iter -> cmdline -> next -> next = NULL;
    iter -> cmdline -> next -> prev = iter -> cmdline;
    iter -> cmdline -> next -> type = 2; // Degisebir
}

/*
 * Listemi olusturuyorum ve her bir kelimeyi bir struct icerisinde tutuyorum
 * bunlarida birbirine bagliyorum 
 * Buradaki onemli nokta kullanacagim operatorlerin argumanlar ile 
 * Bitisik yazilmasina dikkat etmek
 * Bunlarida ft_check_type ile halletmeyi planliyorum
 * */
void ft_addlst_lexer(t_cmdline **cmd, t_shell *shell, size_t size)
{
    t_cmdline *iter;
    size_t i;

    i = 0;
    iter = (*cmd);
    while (size--)
    {
        if (!(*cmd))
        {
            (*cmd) = (t_cmdline *)malloc(sizeof(t_cmdline));
            (*cmd)->next = NULL;
            (*cmd)->prev = NULL;
            (*cmd)->value = shell->cmd.splited_line[i];
            (*cmd)->type = 0;
        }
        else 
        {
            while (iter -> next)
              iter = iter -> next;
            iter -> next = (t_cmdline *)malloc(sizeof(t_cmdline));
            iter -> next -> value = shell -> cmd.splited_line[i];
            iter -> next -> next = NULL;
            iter -> next -> prev = iter;
            iter -> next -> type = 0;
        }
        i++;
    }
}
