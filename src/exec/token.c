/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 04:18:39 by bbali             #+#    #+#             */
/*   Updated: 2022/07/31 04:18:39 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	redirect_fd(t_root *root)
{
	if (root->pid == 0)
	{
		close(root->pipefd[WRITE]);
		root->pipefd[WRITE] = -1;
		exit(EXIT_SUCCESS); // TODO return $?
	}
	dup2(STDOUT_FILENO, STDOUT_FILENO);
	close(root->pipefd[READ]);
	root->pipefd[READ] = -1;
}

void	reset_fd(t_root *root)
{
	dup2(STDIN_FILENO, STDIN_FILENO);
	root->pipefd[WRITE] = -1;
}

void	ft_pipe(t_root *root, t_input *cmd)
{
	pid_t	pid;

	//TODO : if pipe/fork/dup fail ?
	pipe(root->pipefd);
	pid = fork();
	if (pid)
	{
		close(root->pipefd[WRITE]);
		dup2(root->pipefd[READ], STDIN_FILENO);
		root->pid = pid;
		waitpid(-1, NULL, 0);
	}
	else
	{
		close(root->pipefd[READ]);
		dup2(root->pipefd[WRITE], STDOUT_FILENO);
		root->pid = 0;
		execute_cmd(root, cmd);
	}
	redirect_fd(root);
}

void	execute_cmd(t_root *root, t_input *cmd)
{
	if (is_builtin(cmd->input))
		exe_builtin(root, cmd->input);
	else
		exe_generic(root, cmd);
}
