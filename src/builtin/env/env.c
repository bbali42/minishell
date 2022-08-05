/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 21:24:08 by bbali             #+#    #+#             */
/*   Updated: 2022/07/30 21:24:08 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_env *env)
{
	t_env	*head;

	head = env;
	while (env)
	{
		ft_putendl_fd(env->value, STDIN_FILENO);
		env = env->next;
	}
	return (0);
}

int	init_env(t_root *root, char **array)
{
	t_env	*env;
	t_env	*new;
	int		i;

	env = malloc(sizeof(t_env));
	if (!env)
		return (0);
	env->value = ft_strdup(array[0]);
	if (!env->value)
		return (0);
	env->next = NULL;
	root->env = env;
	i = 1;
	while (array && array[i])
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

int	env_size(t_env *head)
{
	int		i;
	t_env	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
