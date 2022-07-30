/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:06:43 by bbali             #+#    #+#             */
/*   Updated: 2022/07/30 21:23:16 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**split_args(t_input *parse)
{
	t_input	*args;
	char	**res;
	int		i;

	if (!parse)
		return (NULL);
	args = parse->next;
	i = 1;
	while (args && args->type == NO_SEP)
	{
		args = args->next;
		i++;
	}
	res = (char **)malloc(sizeof(char *) * (i + 1));
	if (!res)
		return (NULL);
	i = -1;
	args = parse;
	while (args && args->type == NO_SEP)
	{
		res[++i] = args->input;
		args = args->next;
	}
	res[i + 1] = NULL;
	return (res);
}

static char	**split_env(t_env *env)
{
	char	**res;
	int		i;

	res = (char **)malloc(sizeof(char *) * env_size(env) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (env)
	{
		res[i] = env->value;
		if (!res[i])
		{
			free_split(res, i);
			return (NULL);
		}
		env = env->next;
		i++;
	}
	res[i] = NULL;
	return (res);
}

static char	*path_join(char *path, char *cmd)
{
	char	*res;
	int		i;
	int		j;

	res = malloc(sizeof(char) * (ft_strlenchr(path, 0) + \
	ft_strlenchr(cmd, 0) + 2));
	i = 0;
	j = 0;
	while (path[j])
		res[i++] = path[j++];
	res[i++] = '/';
	j = 0;
	while (cmd[j])
		res[i++] = cmd[j++];
	res[i] = 0;
	return (res);
}

static char	*bin_path(char *cmd, char **env)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (cmd);
	path = env[i] + 5;
	while (path && ft_strlenchr(path, ':') > -1)
	{
		dir = ft_strndup(path, ft_strlenchr(path, ':'));
		bin = path_join(dir, cmd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += ft_strlenchr(path, ':') + 1;
	}
	return (cmd);
}

void	exe_generic(t_root *root, t_input *cmd)
{
	pid_t	pid;
	char	**args;
	char	*path;
	char	**env_format;

	pid = fork();
	if (!pid)
	{	
		args = split_args(cmd);
		env_format = split_env(root->env);
		path = bin_path(cmd->input, env_format);
		execve(path, args, env_format);
		write(STDERR_FILENO, "minishell '", 11);
		write(STDERR_FILENO, args[0], ft_strlenchr(args[0], 0));
		write(STDERR_FILENO, "' : command not found\n", 22);
		exit(127);
	}
	else
		waitpid(pid, NULL, 0);
		//Need to return value of EXECVE for $?
}
