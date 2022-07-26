/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:08:52 by bbali             #+#    #+#             */
/*   Updated: 2021/12/01 11:38:13 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	res = ft_lstnew(f(lst->content));
	if (!res)
	{
		ft_lstclear(&res, del);
		return (NULL);
	}
	tmp = res;
	lst = lst->next;
	while (lst)
	{
		ft_lstadd_back(&tmp, ft_lstnew(f(lst->content)));
		lst = lst->next;
	}
	return (res);
}
