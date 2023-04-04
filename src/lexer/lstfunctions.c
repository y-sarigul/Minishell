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
void ft_addlst_lexer(t_shell **shell, size_t size)
{
    t_shell *iter;
    size_t i;

    i = 0;
    iter = (*shell);
    while (size--)
    {
        if (!(*shell)->cmdline)
        {
            (*shell)->cmdline = (t_cmdline *)malloc(sizeof(t_cmdline));
            (*shell)->cmdline->next = NULL;
            (*shell)->cmdline->prev = NULL;
            (*shell)->cmdline->value = (*shell)->cmd.splited_line[i];
            (*shell)->cmdline->type = 0;
        }
        else 
        {
            while (iter -> cmdline -> next)
            {
                iter -> cmdline = iter -> cmdline -> next;
                ft_check_type(shell, (*shell)->cmd.splited_line[i]);
                printf("%s\n", iter -> cmdline -> value);
            }
            iter -> cmdline -> next = (t_cmdline *)malloc(sizeof(t_cmdline));
            iter -> cmdline -> next -> value = (*shell)->cmd.splited_line[i];
        }
        i++;
    }
}
