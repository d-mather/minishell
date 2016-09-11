/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 11:52:07 by dmather           #+#    #+#             */
/*   Updated: 2016/09/11 11:54:46 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*area;

	area = NULL;
	if (size)
	{
		area = (void *)malloc(size);
		if (!area)
			return (NULL);
		ft_bzero(area, size);
	}
	return (area);
}
