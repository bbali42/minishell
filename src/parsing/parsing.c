/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:00:03 by rbenayou          #+#    #+#             */
/*   Updated: 2022/07/30 21:27:57 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_type(char *str)
{
	if (!ft_strcmp(str, "|"))
		return (PIPE);
	else if (!ft_strcmp(str, "<"))
		return (REDIRECT_INPUT);
	else if (!ft_strcmp(str, ">"))
		return (REDIRECT_OUTPUT);
	else if (!ft_strcmp(str, "<"))
		return (CAT);
	else if (!ft_strcmp(str, ">>"))
		return (APPEND);
	else
		return (NO_SEP);
}

int	input_malloc(char *str, int	*i)
{
	int		count;
	int		j;
	char	to_check;

	count = 0;
	j = 0;
	to_check = ' ';
	while (str[*i + j] && (str[*i + j] != ' ' || to_check != ' '))
	{
		if (to_check == ' ' && (str[*i + j] == '\'' || str[*i + j] == '\"'))
			to_check = str[*i + j++];
		else if (to_check != ' ' && str[*i + j] == to_check)
		{
			count += 2;
			to_check = ' ';
			j++;
		}
		else
			j++;
	}
	return (j - count + 1);
}

char	*next_input(char *line, int *i)
{
	char	*input;
	int		j;
	char	to_check;

	j = 0;
	to_check = ' ';
	input = malloc(sizeof(char) * input_malloc(line, i));
	if (!input)
		return (NULL);
	while (line[*i] && (line[*i] != ' ' || to_check != ' '))
	{
		if (to_check == ' ' && (line[*i] == '\'' || line[*i] == '\"'))
			to_check = line[*i];
		else if (to_check != ' ' && line[*i] == to_check)
			to_check = ' ';
		else
			input[j++] = line[*i];
		(*i)++;
	}
	input[j] = '\0';
	return (input);
}

t_input	*split_to_list(char *str)
{
	t_input	*head;
	t_input	*new;
	int		i;

	head = NULL;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] && str[i] != ' ')
		{
			if (!head)
				head = new_input(next_input(str, &i));
			else
				add_input(head, next_input(str, &i));
			if (str[0] == '"' || str[0] == '\'')
				while ((str[0] && str[1]) && str[1] != '|')
					str++;
		}
	}
	return (head);
}

t_input	*parsing(char *str)
{
	t_input	*parse;

	parse = split_to_list(str);
	if (!parse)
		exit(EXIT_FAILURE); //TODO clean exit when malloc fail
	add_history(str);
	free(str);
	return (parse);
}
