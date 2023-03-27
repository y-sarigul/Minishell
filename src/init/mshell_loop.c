#include "../../inc/minishell.h"
#include <stdio.h>

static void get_lines(t_shell **shell)
{
    int i;

    i = 0;
    while ((*shell) -> cmd.history[i]){
        printf("%s\n", (*shell) -> cmd.history[i]);
        i++;
    }
}

// this fuction is wrong
static void ft_get_history_ten(t_shell **shell)
{
    size_t i;

    i = 0;
    while (i <= 10){
        if (i == 10)
            (*shell)->cmd.history[10] = 0;
        (*shell)->cmd.history[i] = (*shell)->cmd.history[i + 1];
        i++;
    }
}

static void ft_get_history(t_shell **shell, const char *line)
{
    size_t i;

    i = 0;
    if (!(*shell)->cmd.history)
        (*shell)->cmd.history = (char **)malloc(sizeof(char *) * 10);
    while ((*shell)->cmd.history[i])
        i++;
    if (i == 10)
        ft_get_history_ten(shell);
    (*shell)->cmd.history[i] = ft_strdup(line);
    (*shell)->cmd.history[i + 1] = 0;
}

void ft_mshell_loop(t_shell **shell, char **envp)
{
    while (1){
        // This functions parser for pwd.
        // Return value is a line.
        // Its will show us where we are
        ft_parse_pwd(shell, envp);
        printf("%s => ", (*shell) -> pwd.line);
        (*shell) -> cmd.line = readline("");
        ft_get_history(shell, (*shell) ->cmd.line);
        get_lines(shell);
    }
}
