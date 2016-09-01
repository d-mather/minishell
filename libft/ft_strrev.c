/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 17:03:20 by dmather           #+#    #+#             */
/*   Updated: 2016/06/12 17:03:21 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	temp;
	int		c;
	int		l;

	c = 0;
	l = 0;
	l = ft_strlen(str);
	while (--l > c)
	{
		temp = str[c];
		str[c] = str[l];
		str[l] = temp;
		c++;
	}
	return (str);
}
