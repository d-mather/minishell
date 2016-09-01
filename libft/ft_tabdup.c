/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 10:51:51 by dmather           #+#    #+#             */
/*   Updated: 2016/08/20 11:39:00 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **table, int len)
{
	int		i;
	char	**newtab;

	i = 0;
	newtab = (char **)malloc(sizeof(char *) * (len + 1));
	while (i < len)
	{
		newtab[i] = ft_strdup(table[i]);
		++i;
	}
	newtab[len] = NULL;
	return (newtab);
}
