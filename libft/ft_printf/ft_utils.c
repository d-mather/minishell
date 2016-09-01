/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 17:37:25 by dmather           #+#    #+#             */
/*   Updated: 2016/06/12 17:37:30 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		get_prec(va_list ap, char **ptr, int *nbr)
{
	if (**ptr == '*')
	{
		*nbr = va_arg(ap, int);
		++(*ptr);
		return (1);
	}
	else if (get_number(ptr, nbr))
	{
		return (1);
	}
	else
		return (0);
}

int		get_number(char **ptr, int *nbr)
{
	int		neg;

	neg = 0;
	if (**ptr)
	{
		if (**ptr == '-')
		{
			++neg;
			++(*ptr);
		}
		while (**ptr >= '0' && **ptr <= '9')
		{
			*nbr = *nbr * 10 + (**ptr - '0');
			++(*ptr);
		}
		if (neg)
			*nbr = *nbr * -1;
		return (1);
	}
	return (0);
}

int		get_width(va_list ap, char **ptr, int *nbr)
{
	if (**ptr == '*')
	{
		*nbr = va_arg(ap, int);
		++(*ptr);
		return (1);
	}
	else if (get_number(ptr, nbr))
		return (1);
	else
		return (0);
}

int		find_char(char **ptr, char *chars)
{
	int		i;
	char	c;

	i = 0;
	if (chars[i] && ptr[i])
	{
		c = **ptr;
		while (chars[i] != '\0')
		{
			if (c == chars[i])
			{
				(*ptr)++;
				return (chars[i]);
			}
			i++;
		}
	}
	return (0);
}
