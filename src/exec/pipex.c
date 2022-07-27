/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:06:43 by bbali             #+#    #+#             */
/*   Updated: 2022/07/27 19:01:47 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	openfile(char *filename, int mode)
{
	if (mode == STDIN_FILENO)
	{
		if (access(filename, F_OK))
		{
			write(STDERR_FILENO, "pipex '", 7);
			write(STDERR_FILENO, filename, strlen_chr(filename, 0));
			write(STDERR_FILENO, "' : No such file or directory\n", 30);
			return (STDIN_FILENO);
		}
		return (open(filename, O_RDONLY));
	}
	else
		return (open(filename, O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH));
}

static void	exec(char *cmd, char **env)
{
	char	**args;
	char	*path;

	args = str_split(cmd, ' ');
	if (strlen_chr(args[0], '/') > -1)
		path = args[0];
	else
		path = get_path(args[0], env);
	execve(path, args, env);
	write(STDERR_FILENO, "pipex '", 7);
	write(STDERR_FILENO, cmd, strlen_chr(cmd, 0));
	write(STDERR_FILENO, "' : command not found\n", 22);
	free_split(args);
	free(path);
	exit(127);
}

static void	redirect(char *cmd, char **env)
{
	pid_t	pid;
	int		pipe_fd[2];

	pipe(pipe_fd);
	pid = fork();
	if (pid)
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		exec(cmd, env);
	}
}

int	pipex(char *cmd, char *path)
{
	int	fdin;
	int	fdout;
	int	i;

	i = 2;
	if (ac >= 5)
	{
		fdin = openfile(av[1], STDIN_FILENO);
		if (fdin < 0)
		{
			write(STDERR_FILENO, av[1], strlen_chr(av[1], 0));
			write(STDERR_FILENO, " : permission denied\n", 21);
		}
		if (fdin == STDIN_FILENO || fdin < 0)
			return (0);
		fdout = openfile(av[ac - 1], STDOUT_FILENO);
		dup2(fdin, STDIN_FILENO);
		dup2(fdout, STDOUT_FILENO);
		
		while (i < size(token))
		{
			redirect(*cmd, *args, PATH);
		}
		exec(av[i], env);
	}
	else
		write(STDERR_FILENO, "Invalid arguments.\n", 19);
	return (0);
}
