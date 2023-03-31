#include "../../inc/minishell.h"
#include <stdio.h>

static size_t ft_sizelst(t_shell *shell)
{
    size_t i;
    t_cmdline *iter;
    
    i = 0;
    iter = shell -> cmdline;
    while (iter){
        i++;
        iter = iter->next;
    }
    return (i);
}

static char **ft_splited_operations(const char *line)
{
    char **buff;
    size_t i;
    size_t j;

    i = 0;
    if (!line)
        return (NULL);
    buff = (char **)malloc(sizeof(char *) * ft_strlen(line) + 1);
    while (line[i]){
        buff[i][j] = line[i];
        j++;
        buff[i][j] = '\0';
        i++;
        buff[i] = 0;
    }
    return (buff);
}

static int ft_check_type(const char *line)
{
    // cat test.txt |grep yasin
    char **buff;

    buff = ft_splited_operations(line);
    printf("geldi\n");
    return (0);
}

void ft_addlst_lexer(t_shell **shell)
{
    t_cmdline *iter;
    size_t i;

    iter = (*shell)->cmdline;
    i = ft_sizelst((*shell));
    printf("%zu\n", i);
    if (!(*shell)->cmdline){
        (*shell)->cmdline = (t_cmdline *)malloc(sizeof(t_cmdline));
        (*shell)->cmdline->next = NULL;
        (*shell)->cmdline->prev = NULL;
        (*shell)->cmdline->value = ft_strdup((*shell)->cmd.splited_line[i]);
        (*shell)->cmdline->type = 0;
    }
    else {
        while (iter -> next)
            iter = iter -> next;
        iter -> next = (t_cmdline *)malloc(sizeof(t_cmdline));
        iter -> next -> value = ft_strdup((*shell)->cmd.splited_line[i]); 
        iter -> next -> type = ft_check_type(iter -> value);
        iter -> next -> next = NULL;
        iter -> next -> prev = iter;
    }
}

