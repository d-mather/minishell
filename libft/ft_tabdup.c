/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 10:51:51 by dmather           #+#    #+#             */
/*   Updated: 2016/09/11 11:56:48 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **table, int len)
{
	int		i;
	char	**newtab;

	i = 0;
	if ((newtab = (char **)malloc(sizeof(char *) * (len + 1))) != NULL)
	{
		while (i < len && table[i])
		{
			newtab[i] = ft_strdup(table[i]);
			++i;
		}
		while (i < len)
		{
			newtab[i] = NULL;
			++i;
		}
		newtab[len] = NULL;
	}
	return (newtab);
}
