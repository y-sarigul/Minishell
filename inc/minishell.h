#ifndef MINISHELL_H
#define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "readline/readline.h"

extern char **environ;

typedef struct s_cmdline{
    char *word;
    int index;
    struct s_cmdline *next;
    struct s_cmdline *prev;
} t_cmdline;

typedef struct s_input {
    char **line;
} t_input;

typedef struct s_shell{
    t_input input;
    t_cmdline *cmdline;
} t_shell;


/* Loop */
void mini_loop();

/* Parser */
void parser(t_shell **shell);

/* Lst */
/* -> cmdlin */
void c_addlst_back(t_cmdline **root, t_cmdline *newlst);
t_cmdline *c_newlst(char *word, int index);
/* -> testlst */
void c_printlst_next(t_cmdline *root);
void c_printlst_prev(t_cmdline *root);

#endif // !MINISHELL_H
