/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 12:53:00 by dmather           #+#    #+#             */
/*   Updated: 2016/09/11 11:53:38 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(char ***table, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_strdel(&(*table)[i]);
		++i;
	}
	free(*table);
	*table = NULL;
}
