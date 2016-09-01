/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/02 15:25:20 by dmather           #+#    #+#             */
/*   Updated: 2016/07/02 15:27:00 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_hex(const char *nptr)
{
	size_t		res;
	size_t		i;

	res = 0;
	i = 0;
	while (ft_isdigit(nptr[i]) ||
		(ft_toupper(nptr[i] >= 'A' && ft_toupper(nptr[i]) <= 'F')))
	{
		res *= 16;
		if (nptr[i] < 'A')
			res += (nptr[i++] - '0');
		else
			res += (10 + (nptr[i++] - 'A'));
	}
	return (res);
}
