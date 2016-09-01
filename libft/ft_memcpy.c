/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 08:08:05 by dmather           #+#    #+#             */
/*   Updated: 2016/08/23 20:16:32 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (dest && src)
	{
		str1 = (unsigned char *)dest;
		str2 = (unsigned char *)src;
		while (n--)
			*str1++ = *str2++;
	}
	return (dest);
}
