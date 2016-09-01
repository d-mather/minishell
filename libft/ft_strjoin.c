/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 11:57:08 by dmather           #+#    #+#             */
/*   Updated: 2016/08/15 11:57:02 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		len;

	ret = NULL;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
		if ((ret = (char*)ft_memalloc(sizeof(char) * len)) == NULL)
			return (NULL);
		ft_strcpy(ret, s1);
		ft_strcat(ret, s2);
	}
	return (ret);
}
