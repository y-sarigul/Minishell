#ifndef MINISHELL_H
# define MINISHELL_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <readline/readline.h>

# define BUFFSIZE 512
# define LINESIZE 1024

// bu enumda benim turleri tutugum yer maskelemek kolay olmasi icin
// 2 nin katlari ile islem yapiyorum
typedef enum e_kind {
    CMD = 0,
    PIPE = 1,
    REDIRECT = 2,
    ARG = 4,
    QUOTE = 8,
} e_kind;

//Burasi benim cmd.splited_line dan algim ve artik kimliklerini aktardigim yer
//cift yonlu bagli liste ile bunlari burada tutuyorum ve hepsine birer id veriyorum
typedef struct s_cmdline{
    struct s_cmdline *next;
    struct s_cmdline *prev;
    e_kind type;
    char *value;
} t_cmdline;


// cmd ile readline ile donen yazilari tutuyorum ve 
// bunlari splitliyorum ve onuda ** icerisinde tutuyorum
typedef struct s_cmd{
    char *line;
    char **splited_line;
} t_cmd;

// pwd enviroment ini tutan structim
typedef struct s_pwd{
    char *line;
}   t_pwd;


// Ana struct yapim
typedef struct s_shell{
    t_pwd pwd;
    t_cmd cmd;
    t_cmdline *cmdline;
    char **history;
} t_shell;

/********init********/
void   ft_mshell_loop(t_shell **shell, char **envp);
void ft_parse_pwd(t_shell **shell, char **envp);

/*****history.c*****/
void ft_save_history(t_shell **shell, const char *line);

// ***
void new_history(t_shell **shell, char *line);
// ***

/******lexer**********/
void ft_space_split(t_shell **shell);
void ft_addlst_lexer(t_shell **shell, size_t size);
char **ft_split_test(char *str);

/******utils**********/
char *ft_strstr(const char *s1, const char del);
size_t ft_strnlen(const char *s1, const char del);
void ft_error(const char *err);
int check_greater_than(char **line);


#endif
