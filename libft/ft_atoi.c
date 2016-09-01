/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 11:47:23 by dmather           #+#    #+#             */
/*   Updated: 2016/08/23 18:52:20 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int		i;
	int		neg;
	int		number;

	i = 0;
	neg = 0;
	number = 0;
	while ((nptr[i] == ' ') || (nptr[i] == '\t') || (nptr[i] == '\n')
			|| (nptr[i] == '\v') || (nptr[i] == '\f') || (nptr[i] == '\r'))
		i++;
	if (nptr[i] == 45)
		neg = 1;
	if ((nptr[i] == 45) || (nptr[i] == 43))
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		number *= 10;
		number += ((int)nptr[i] - 48);
		i++;
	}
	if (neg == 1)
		return (-number);
	else
		return (number);
}
