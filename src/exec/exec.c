/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:06:43 by bbali             #+#    #+#             */
/*   Updated: 2022/07/28 01:58:03 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_work(char *cmd, char *path_env, char **env)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
		exec(cmd, path_env, env);
	else
		waitpid(pid, NULL, 0);
}

void	exec(char *cmd, char *path_env, char **env)
{
	char	**args;

	args = str_split(cmd, ' ');
	execve(path_env, args, env);
	write(STDERR_FILENO, "minishell '", 11);
	write(STDERR_FILENO, cmd, strlen_chr(cmd, 0));
	write(STDERR_FILENO, "' : command not found\n", 22);
	exit(127);
}
