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

	token = get_token(input);
	while (input)
	{
		if (token && token->type == PIPE)
		{
			ft_pipe(root, input);
		}
		if (!token)
		{
			execute_cmd(root, input);
			reset_std_fd(root);
		}
		input = next_cmd(input);
		token = get_token(input);
	}
}

int	main(int ac, char **av, char **env)
{
	t_root	root;
	t_input	*parse;

	(void)ac;
	(void)av;
	get_std_fd(&root);
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
