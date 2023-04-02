#include "../inc/minishell.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv, char **envp) {
    (void)argc;
    (void)argv;
    t_shell *shell;

    if (!shell)
        shell = (t_shell *)malloc(sizeof(t_shell));

    // Shell'i loop'a gonderiyorum
    ft_mshell_loop(&shell, envp);
  return 0;
}

