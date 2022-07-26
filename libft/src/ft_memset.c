/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:45:57 by bbali             #+#    #+#             */
/*   Updated: 2021/11/24 13:49:09 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *tab, int c, size_t n)
{
	int		i;

	i = 0;
	while (n--)
		((unsigned char *)tab)[i++] = (unsigned char)c;
	return (tab);
}
