/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:00:03 by rbenayou          #+#    #+#             */
/*   Updated: 2022/07/28 00:25:21 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_type(char *str)
{
	int		i;

	i = 0;
	while(str[i])
	{
		if (str[0] == '|' || str[0] == '<' || str[0] == '>')
		{
			if (ft_strcmp(str, "|") == 0)
				return (PIPE);
			else if (ft_strcmp(str, "<") == 0)
				return (REDIRECT_INPUT);
			else if (ft_strcmp(str, ">") == 0)
				return (REDIRECT_OUTPUT);
			else if (ft_strcmp(str, "<") == 0)
				return (CAT);
			else if (ft_strcmp(str, ">>") == 0)
				return (APPEND);
		}
		i++;
	}
}

void	print_parse(t_parse	*parse)
{
	t_parse	*head;

	if (!parse)
		return ;
	head = parse;
	while (head)
	{
		ft_putendl_fd(head->data, STDIN_FILENO);
		head = head->next;
	}
}

int		quoted(char *line, int index)
{
	int	i;
	int	is_closed;

	i = 0;
	is_closed = 1;
	while (line[i] && i != index)
	{
		if (i > 0 && line[i - 1] == '\\')
			;
		else if (is_closed == 1 && line[i] == '\"')
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

t_parse	**parsing(char *input)
{
	t_parse	**list;
	
	if (!quoted(input, INT_MAX))
	{
		ft_putendl_fd("Quotes not close !", STDERR_FILENO);
		return (NULL);
	}
	list = (t_parse **)malloc(sizeof(t_parse *));
	if (!list)
		return (NULL);
	*list = NULL;
	split_to_list(list, input, ' ');
	add_history(input);
	return (list);
}

/*void	handler(int signum)
{
	if (signum == 2) // ctrl c
		exit(EXIT_SUCCESS);
}

int main()
{
	char *ok;
	t_parse	*parsed_input;

	parsed_input = NULL;
	while(1)
	{
		signal(SIGINT, handler);
		signal(SIGQUIT, handler);
		ok = readline("minishell: ");
		parsing(ok, &parsed_input);
		add_history(ok);
		while(parsed_input)
		{
			printf("%s\n",parsed_input->data);
		//	printf("%d\n",parsed_input->type);
			parsed_input = parsed_input->next;
		}
	}
}
*/
