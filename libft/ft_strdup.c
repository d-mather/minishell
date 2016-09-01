/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 11:54:51 by dmather           #+#    #+#             */
/*   Updated: 2016/08/27 16:34:37 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s)
{
	char *s2;

	s2 = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	ft_strcpy(s2, s);
	return (s2);
}
