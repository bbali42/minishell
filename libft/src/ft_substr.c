/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:47:07 by bbali             #+#    #+#             */
/*   Updated: 2021/12/09 15:25:11 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_size(char const *s, int i, int j)
{
	int		n;

	n = 0;
	while (s[i + n] && n < j)
		n++;
	return (n);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*res;
	unsigned int		i;

	if (!s || start > ft_strlen(s))
	{
		start = 0;
		len = 0;
	}
	res = (char *)malloc(sizeof(char) * get_size(s, start, len) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
