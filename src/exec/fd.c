/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 00:29:45 by bbali             #+#    #+#             */
/*   Updated: 2022/08/06 00:29:45 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_std_fd(t_root *root)
{
	//Handle errno if fails
	root->stdin = dup(STDIN_FILENO);
	root->stdout = dup(STDOUT_FILENO);
	return (1);
}

int	reset_std_fd(t_root *root)
{
	//Handle errno if fails
	dup2(root->stdin, STDIN_FILENO);
	dup2(root->stdout, STDOUT_FILENO);
	return (1);
}

// TODO redirection
