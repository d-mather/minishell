/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 09:40:47 by dmather           #+#    #+#             */
/*   Updated: 2016/08/20 11:29:03 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	getsize(void *p)
{
	size_t *in;

	in = p;
	if (in)
		return (*in);
	return (-1);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void	*newptr;
	size_t	msize;

	msize = getsize(ptr);
	if (size <= msize)
		return (ptr);
	newptr = malloc(size);
	ft_memcpy(newptr, ptr, msize);
	free(ptr);
	return (newptr);
}
