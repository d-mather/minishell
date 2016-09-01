/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 08:09:40 by dmather           #+#    #+#             */
/*   Updated: 2016/08/19 16:48:20 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		len;

	ptr = (char *)s;
	len = ft_strlen(ptr);
	while ((ptr[len] != c) && (len > -1))
		len--;
	if (ptr[len] == c)
		return (&ptr[len]);
	return (NULL);
}
