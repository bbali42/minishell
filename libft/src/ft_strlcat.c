/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:46:39 by bbali             #+#    #+#             */
/*   Updated: 2021/12/03 16:32:38 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	len_d;

	len_d = ft_strlen(dst);
	if (size <= len_d)
		return (ft_strlen(src) + size);
	while (*src && (len_d + 1) < size)
		dst[len_d++] = *src++;
	dst[len_d] = '\0';
	return (ft_strlen(src) + len_d);
}
