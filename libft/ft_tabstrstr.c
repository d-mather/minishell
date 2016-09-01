/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstrstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 11:30:08 by dmather           #+#    #+#             */
/*   Updated: 2016/07/10 13:00:15 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tabstrstr(char **haystack, const char *needle)
{
	int	i;

	i = 0;
	while (haystack[i])
	{
		if (ft_strstr(haystack[i], needle) != 0)
			return (haystack[i]);
		i++;
	}
	return (NULL);
}
