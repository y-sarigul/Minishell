#include "../../inc/minishell.h"

void ft_save_history(t_shell **shell, const char *line)
{
    if (!(*shell)->history)
        (*shell)->history = (t_history *)malloc(sizeof(t_history));

}
