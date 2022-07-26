/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:45:33 by bbali             #+#    #+#             */
/*   Updated: 2021/11/24 17:20:23 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (--n && (*(unsigned char *)s1) == (*(unsigned char *)s2))
	{
		s1++;
		s2++;
	}
	return ((*(unsigned char *)s1) - (*(unsigned char *)s2));
}
