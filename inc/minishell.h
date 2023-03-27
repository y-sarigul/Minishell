#ifndef MINISHELL_H
# define MINISHELL_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <readline/readline.h>


typedef struct s_pwd{
    char *line;
}   t_pwd;

typedef struct s_shell{
    t_pwd pwd;
} t_shell;

/********init********/
void   ft_mshell_loop(t_shell *shell);
void ft_parse_pwd(t_shell **shell, char **envp);

#endif
