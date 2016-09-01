/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 16:58:55 by dmather           #+#    #+#             */
/*   Updated: 2016/08/23 18:59:58 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_isupper(char c)
{
	if (c > 64 && c < 91)
		return (1);
	else
		return (0);
}
