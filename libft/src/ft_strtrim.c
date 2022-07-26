/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:47:03 by bbali             #+#    #+#             */
/*   Updated: 2021/12/07 12:32:42 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

static char	*create_str(char *str, int start, int end, int n)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * (ft_strlen(str) - n) + 1);
	if (!new)
		return (NULL);
	n = 0;
	while (start != end + 1)
	{
		new[n] = str[start];
		n++;
		start++;
	}
	new[n] = '\0';
	return (new);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		n;

	if (!s1)
		return (NULL);
	else if (!set)
		return ((char *)s1);
	start = 0;
	end = ft_strlen(s1) - 1;
	n = 0;
	while (s1[start] && is_set(s1[start], set))
	{
		start++;
		n++;
	}
	if (s1[start] != '\0')
	{
		while (s1[end] && is_set(s1[end], set))
		{
			end--;
			n++;
		}
	}
	return (create_str((char *)s1, start, end, n));
}
