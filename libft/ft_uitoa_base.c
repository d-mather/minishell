/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 17:03:45 by dmather           #+#    #+#             */
/*   Updated: 2016/06/26 10:22:01 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert(size_t *n, unsigned int base, size_t *n_arr)
{
	int	i;

	i = 0;
	while (*n != 0)
	{
		n_arr[i] = *n % base;
		*n = *n / base;
		++i;
	}
	return (i);
}

char		*ft_uitoa_base(size_t n, unsigned int base)
{
	static char	base_digits[16] = {'0', '1', '2', '3', '4', '5', '6',
							'7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	size_t		cnvtd_nmbr[32];
	int			i;
	size_t		j;
	char		*res;

	j = 0;
	if (n == 0 || base < 2 || base > 16)
		return ("0");
	i = convert(&n, base, cnvtd_nmbr);
	res = ft_strnew(i);
	while (--i >= 0)
		res[j++] = base_digits[cnvtd_nmbr[i]];
	return (res);
}
