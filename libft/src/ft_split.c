/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:46:16 by bbali             #+#    #+#             */
/*   Updated: 2022/07/28 23:32:13 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_nb_strs(char const *str, char set)
{
	int		count;

	count = 0;
	while (*str)
	{
		while (*str && *str == set)
			str++;
		if (*str && *str != set)
		{
			count++;
			while (*str && *str != set)
				str++;
		}
	}
	return (count);
}

static	char	*ft_malloc_str(char const *str, char set)
{
	char	*res;
	int		i;

	i = 0;
	while (str[i] && str[i] != set)
		i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != set)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	free_split(char **strs, int i)
{
	while (i-- > 0)
		free(strs[i]);
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**res;	

	res = (char **)malloc(sizeof(char *) * (ft_nb_strs(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			res[i] = ft_malloc_str(s, c);
			if (!res[i])
				free_split(res, i);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	res[i] = NULL;
	return (res);
}
