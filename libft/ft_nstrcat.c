/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nstrcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 08:02:20 by dmather           #+#    #+#             */
/*   Updated: 2016/08/24 17:49:46 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_nstrcat(char *dest, const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(dest);
	if (dest && s1)
	{
		while (s1[i] != '\0')
		{
			dest[j] = s1[i];
			j++;
			i++;
		}
		i = 0;
		while (s2[i] != '\0')
		{
			dest[j] = s2[i];
			i++;
			j++;
		}
		dest[j] = '\0';
		return (dest);
	}
	return (NULL);
}
