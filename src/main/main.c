#include "minishell.h"

void	handler(int signum)
{
	if (signum == 2) // ctrl c
		exit(EXIT_SUCCESS);
}

static void	redirect_input(t_parse *parse, char **env)
{
	child_work(parse->data, get_path_bin(parse->data, env), env);
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	
	t_root	root;
	t_parse **parsed;
	char	*input;

	if(!init_env(&root, env))
		return (0);
	while(1)
	{
		signal(SIGINT, handler);
		signal(SIGQUIT, handler);
		
		input = readline("minishell: ");
		parsed = parsing(input);
		redirect_input(*parsed, env);
	}	
}
