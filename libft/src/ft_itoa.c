/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:33:05 by bbali             #+#    #+#             */
/*   Updated: 2021/12/02 16:33:47 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_nbrlen(long nbr)
{
	int		count;

	count = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		count++;
	}
	while (nbr > 0)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*res;
	int		len;

	nb = n;
	len = ft_nbrlen(nb);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len--] = '\0';
	if (nb == 0)
		res[0] = 48;
	else if (nb < 0)
	{
		res[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		res[len] = nb % 10 + 48;
		nb /= 10;
		len--;
	}
	return (res);
}
