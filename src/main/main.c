#include "minishell.h"

void	handler(int signum)
{
	if (signum == 2) // ctrl c
		exit(EXIT_SUCCESS);
}

static void	execute_cmd(t_root *root, t_input *cmd)
{
	if (is_builtin(cmd->input))
		exe_builtin(root, cmd->input);
	else
		exe_generic(root, cmd);
}

static void	process_input(t_root *root, t_input *input)
{
	t_input	*cmd;
	t_input	*token;

	cmd = next_cmd(input);
	execute_cmd(root, cmd);
}

int	main(int ac, char **av, char **env)
{
	t_root	root;
	t_input	*parse;

	(void)ac;
	(void)av;
	if (!init_env(&root, env))
		return (0);
	while (1)
	{
		// Need to handle signals everywhere X.X
		signal(SIGINT, handler);
		signal(SIGQUIT, handler);
		parse = parsing(readline("minishell> "));
		process_input(&root, parse);
	}	
}
