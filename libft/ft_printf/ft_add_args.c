/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 17:36:56 by dmather           #+#    #+#             */
/*   Updated: 2016/06/12 17:37:07 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	add_padding(t_data *d, char **str)
{
	size_t	l;
	void	*pad;

	if ((l = d->width) > 0)
	{
		if ((ft_strstr(d->flags, "0")))
			pad = ft_memset((void *)ft_strnew(l), '0', l);
		else
			pad = ft_memset((void *)ft_strnew(l), ' ', l);
		if (d->left_align)
			*str = ft_strnjoin(*str, (char *)pad, l);
		else if (!(d->left_align))
			*str = ft_strnjoin((char *)pad, *str, ft_strlen(*str));
	}
}

void	add_int_flags(t_data *d, char **str, int arg)
{
	if (ft_strstr(d->flags, "+"))
		*str = ft_strnjoin("+", *str, ft_strlen(*str));
	if (ft_strstr(d->flags, "-"))
		d->left_align = 1;
	add_padding(d, str);
	if ((ft_strstr(d->flags, " ")) && !(ft_strstr(d->flags, "+")) &&
															arg > -1)
		*str = ft_strnjoin(" ", *str, ft_strlen(*str));
}

void	process_hex(t_data *data, char **val_str, size_t arg)
{
	if (arg && data->flag == '#')
	{
		if (*data->ptr == 'X')
		{
			data->buff = ft_strnjoin(data->buff, "0X", 2);
			*val_str = ft_strmap(*val_str, &ft_toupper);
		}
		else
			data->buff = ft_strnjoin(data->buff, "0x", 2);
	}
	data->buff = ft_strnjoin(data->buff, *val_str, ft_strlen(*val_str));
}
