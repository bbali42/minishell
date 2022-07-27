#include "minishell.h"

void	handler(int signum)
{
	if (signum == 2) // ctrl c
		exit(EXIT_SUCCESS);
}

int	main(int ac, char **av, char **env)
{
	(void) ac, (void) av, (void) env;
	char *ok;
	t_parse	*parsed_input;

	parsed_input = NULL;
	while(1)
	{
		signal(SIGINT, handler);
		signal(SIGQUIT, handler);
		ok = readline("minishell: ");
		parsing(ok, &parsed_input);
		add_history(ok);
		while(parsed_input)
		{
			printf("%s\n",parsed_input->data);
		//	printf("%d\n",parsed_input->type);
			parsed_input = parsed_input->next;
		}
	}	
}
