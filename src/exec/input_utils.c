/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:47:45 by bbali             #+#    #+#             */
/*   Updated: 2022/07/28 14:47:45 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	quoted(char *line, int index)
{
	int	i;
	int	is_closed;

	i = 0;
	is_closed = 1;
	while (line[i] && i != index)
	{
		if (is_closed == 1 && line[i] == '\"')
			is_closed = 0;
		else if (is_closed == 1 && line[i] == '\'')
			is_closed = -1;
		else if (!is_closed && line[i] == '\"')
			is_closed = 1;
		else if (is_closed == -1 && line[i] == '\'')
			is_closed = 1;
		i++;
	}
	return (is_closed);
}

void	print_input(t_input	*input)
{
	t_input	*head;

	if (!input)
		return ;
	head = input;
	while (head)
	{
		ft_putendl_fd(head->input, STDIN_FILENO);
		head = head->next;
	}
}

t_input	*next_cmd(t_input *index)
{
	while (index && !index->type)
		index = index->next;
	if (index && index->type)
		index = index->next;
	return (index);
}

t_input	*get_token(t_input *index)
{
	while (index && !index->type)
		index = index->next;
	return (index);
}
