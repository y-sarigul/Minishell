#include "../../inc/minishell.h"
#include <stdio.h>

void ft_free_list(t_cmdline **cmd)
{
    while ((*cmd) != NULL)
    {
        t_cmdline *temp;
        temp = (*cmd) -> next;
        free ((*cmd));
        (*cmd) = temp;
    }
}

static t_cmdline *ft_lstnew(char *line)
{
    t_cmdline *new;

    new = malloc(sizeof(t_cmdline));
    if (!new)
        return (NULL);
    new -> value = line;
    new -> type = 0;
    new -> next = NULL;
    new -> prev = NULL;
    return (new);
}

static void ft_lstadd_back(t_cmdline **lst, t_cmdline *new)
{
    t_cmdline *ptr;

    if (*lst == NULL)
        *lst = new;
    else 
    {
        ptr = *lst;
        while (ptr -> next != NULL)
            ptr = ptr -> next;
        ptr -> next = new;
        new -> prev = ptr;
    }
}

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
 */
void ft_addlst_lexer(t_cmdline **cmd, t_shell *shell, size_t size)
{
    t_cmdline *iter;
    size_t i;

    i = 0;
    iter = (*cmd);
    while (size--)
    {
        ft_lstadd_back(cmd, ft_lstnew(shell->cmd.splited_line[i]));
        i++;
    }
}
