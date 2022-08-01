#include "minishell.h"

void	handler(int signum)
{
	if (signum == 2) // ctrl c
		exit(EXIT_SUCCESS);
}

static void	process_input(t_root *root, t_input *input)
{
	t_input	*cmd;
	t_input	*token;
	int		pipe;

	cmd = input;
	token = get_token(input);
	while (cmd)
	{
		root->pid = 1;
		if (token && token->type == PIPE)
		{
			ft_pipe(root, cmd);
			if (cmd->next && !get_token(cmd->next))
				reset_fd(root);
		}
		if (!token)
			execute_cmd(root, cmd);
		cmd = next_cmd(cmd);
		token = get_token(cmd);
	}
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
		free_input(parse);
	}	
}
