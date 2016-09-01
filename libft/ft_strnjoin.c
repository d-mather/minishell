/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 17:02:52 by dmather           #+#    #+#             */
/*   Updated: 2016/06/12 17:02:53 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(const char *s1, const char *s2, size_t n_chars)
{
	char	*new_str;
	size_t	tot_len;

	tot_len = (ft_strlen(s1) + n_chars);
	new_str = ft_strnew(tot_len + 1);
	if (new_str == NULL)
		return (NULL);
	new_str = ft_strncat(new_str, s1, ft_strlen(s1));
	new_str = ft_strncat(new_str, s2, n_chars);
	new_str[tot_len] = '\0';
	return (new_str);
}
