/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:00:03 by rbenayou          #+#    #+#             */
/*   Updated: 2022/07/27 19:49:39 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>


void	scan_parse(t_parse **list)
{
	t_parse *tmp;

	tmp = *list;
	while(tmp)
	{
		if (tmp->data[0] == '|' || tmp->data[0] == '<' || tmp->data[0] == '>')
		{
			if (ft_strcmp(tmp->data, "|") == 0)
				tmp->type = PIPE;
			else if (ft_strcmp(tmp->data, "<") == 0)
				tmp->type = REDIRECT_INPUT;
			else if (ft_strcmp(tmp->data, ">") == 0)
				tmp->type = REDIRECT_OUTPUT;
			else if (ft_strcmp(tmp->data, "<") == 0)
				tmp->type = CAT;
			else if (ft_strcmp(tmp->data, ">>") == 0)
				tmp->type = APPEND;
		}
		tmp = tmp->next;
	}
}

void	parsing(char *input, t_parse **list)
{
	split_to_list(list, input, ' ');
	scan_parse(list);
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
