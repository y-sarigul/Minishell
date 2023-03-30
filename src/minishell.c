#include "../inc/minishell.h"
#include <stdio.h>

int main(int argc, char **argv, char **envp) {
  (void)argc;
  (void)argv;
  t_shell *shell;

  if (!shell)
    shell = (t_shell *)malloc(sizeof(t_shell));

  // looping shell program
  ft_mshell_loop(&shell, envp);
  return 0;
}
