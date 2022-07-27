#include "minishell.h"

int	init_env(t_root *root, char **array)
{
	t_env	*env;
	t_env	*new;
	int		i;

	env = malloc(sizeof(t_env));
	if (!env)
		return (0);
	env->value = ft_strdup(array[0]);
	env->next = NULL;
	root->env = env;
	i = 1;
	while (array && array[0] && array[i])
	{
		new = malloc(sizeof(t_env));
		if (!new)
			return (0);
		new->value = ft_strdup(array[i]);
		new->next = NULL;
		env->next = new;
		env = new;
		i++;
	}
	return (1);
}

void	print_env(t_env	*env)
{
	t_env	*head;

	head = env;
	while (head->next)
	{
		ft_putendl_fd(head->value, STDIN_FILENO);
		head = head->next;
	}
}