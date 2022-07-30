/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:12:33 by bbali             #+#    #+#             */
/*   Updated: 2022/07/28 15:12:33 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
static char	*builtin[] = {"echo", "cd", "pwd", "export", "unset", "env", "exit"};

int	is_builtin(char *cmd)
{
	int		i;

	i = -1;
	while (builtin[++i])
	{
		if (!strcmp(cmd, builtin[i]))
			return (1);
	}
	return (0);
}

void	exe_builtin(t_root *root, char *cmd)
{
	if (!strcmp(cmd, builtin[5]))
		ft_env(root->env);
}
