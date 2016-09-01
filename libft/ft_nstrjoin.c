/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 14:37:10 by dmather           #+#    #+#             */
/*   Updated: 2016/08/19 16:15:57 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_nstrjoin(char *s1, char *s2, char *s3)
{
	char	*tmp;

	if (s1 && s2 && s3)
	{
		tmp = ft_strjoin(s1, s2);
		s1 = ft_strjoin(tmp, s3);
		free(tmp);
		return (s1);
	}
	else
		return (NULL);
}
