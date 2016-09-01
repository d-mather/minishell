/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 11:57:39 by dmather           #+#    #+#             */
/*   Updated: 2016/05/28 11:57:42 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_s;

	if (!s || !f)
		return (NULL);
	i = 0;
	new_s = ft_strdup(s);
	while (new_s && new_s[i])
	{
		new_s[i] = f(i, new_s[i]);
		i++;
	}
	return (new_s);
}
