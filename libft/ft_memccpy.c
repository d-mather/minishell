/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 11:53:09 by dmather           #+#    #+#             */
/*   Updated: 2016/05/28 11:53:14 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*a;
	unsigned char	*b;
	unsigned char	x;

	if (dst && src)
	{
		i = 0;
		a = (unsigned char *)dst;
		b = (unsigned char *)src;
		x = (unsigned char)c;
		while (i < n)
		{
			*a = *b;
			if (*b == x)
				return ((void *)(a + 1));
			a++;
			b++;
			i++;
		}
	}
	return (NULL);
}
