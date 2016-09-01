/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 14:01:01 by dmather           #+#    #+#             */
/*   Updated: 2016/08/04 14:06:27 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

int		nlen(int n)
{
	int	l;

	l = 1;
	if (n < 0)
		++l;
	while (n /= 10)
		++l;
	return (l);
}

char	*ft_itoa(int nbr)
{
	int		l;
	char	*res;

	l = nlen(nbr);
	res = malloc(l + 1);
	if (nbr == 0)
		res[0] = '0';
	if (nbr < 0)
		res[0] = '-';
	res[l--] = '\0';
	while (nbr)
	{
		res[l--] = ft_abs(nbr % 10) + '0';
		nbr /= 10;
	}
	return (res);
}
