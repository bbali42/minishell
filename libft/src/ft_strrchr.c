/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:47:00 by bbali             #+#    #+#             */
/*   Updated: 2021/11/25 11:17:50 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		len;

	len = ft_strlen(str) + 1;
	while (len--)
	{
		if (str[len] == (char)c)
			return ((char *)&str[len]);
	}
	return (NULL);
}
