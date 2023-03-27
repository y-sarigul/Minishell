#ifndef MINISHELL_H
# define MINISHELL_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <readline/readline.h>

typedef struct s_cmd{
    char *line;
    char **history;
} t_cmd;

typedef struct s_pwd{
    char *line;
}   t_pwd;

typedef struct s_shell{
    t_pwd pwd;
    t_cmd cmd;
} t_shell;

/********init********/
void   ft_mshell_loop(t_shell **shell, char **envp);
void ft_parse_pwd(t_shell **shell, char **envp);

/*****history.c*****/
void get_lines(t_shell **shell);
void ft_get_history(t_shell **shell, const char *line);


#endif
