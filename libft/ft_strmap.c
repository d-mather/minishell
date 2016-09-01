/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 11:57:27 by dmather           #+#    #+#             */
/*   Updated: 2016/05/28 11:57:32 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*ret;

	ret = ft_strdup(s);
	if (!s || !f || !ret)
		return (NULL);
	i = -1;
	while (ret && ret[++i])
		ret[i] = f(ret[i]);
	ret[i] = '\0';
	return (ret);
}
