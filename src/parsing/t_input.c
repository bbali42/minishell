/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_input.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:44:37 by bbali             #+#    #+#             */
/*   Updated: 2022/07/28 22:44:37 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_input	*last_input(t_input *head)
{
	while (head->next)
	{
		head = head->next;
		if (head->next == NULL)
			return (head);
	}
	return (head);
}

t_input	*new_input(char *str)
{
	t_input	*new;

	new = (t_input *) malloc(sizeof(t_input));
	if (!new)
		return (NULL);
	new->input = str;
	if (!new->input)
	{
		free(new);
		return (NULL);
	}
	new->type = get_type(str);
	new->next = NULL;
	return (new);
}

void	input_add_back(t_input *list, t_input *new)
{
	t_input	*last;

	if (list)
	{
		last = last_input(list);
		last->next = new;
		new->next = NULL;
		new->prev = last;
	}
	else
	{	
		list = new;
		list->next = NULL;
		list->prev = NULL;
	}
}

int	add_input(t_input *list, char *str)
{
	t_input	*new;

	new = new_input(str);
	if (!new)
		return (0);
	input_add_back(list, new);
	return (1);
}

int	input_size(t_input *head)
{
	int		i;

	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}
