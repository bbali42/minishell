/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 04:03:11 by bbali             #+#    #+#             */
/*   Updated: 2022/07/31 04:03:11 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_input(t_input *head)
{
	while (head)
	{
		ft_memdel(head->input);
		ft_memdel(head->prev);
		head = head->next;
	}
	head = ft_memdel(head);
}

void	free_env(t_env *head)
{
	while (head)
	{
		ft_memdel(head->value);
		head = head->next;
	}
	ft_memdel(head);
}
