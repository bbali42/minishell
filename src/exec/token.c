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
		close(root->w_pipe);
		root->w_pipe = -1;
		exit(EXIT_SUCCESS);
	}
	dup2(STDOUT_FILENO, STDOUT_FILENO);
	close(root->r_pipe);
	root->r_pipe = -1;
}

void	reset_fd(t_root *root)
{
	dup2(STDIN_FILENO, STDIN_FILENO);
	root->w_pipe = -1;
}

void	ft_pipe(t_root *root, t_input *cmd)
{
	pid_t	pid;
	int		pipefd[2];

	//TODO : if pipe/fork/dup fail ?
	pipe(pipefd);
	pid = fork();
	if (pid)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		root->r_pipe = pipefd[0];
		root->pid = pid;
		waitpid(-1, NULL, 0);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		root->w_pipe = pipefd[1];
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
