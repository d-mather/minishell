/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 17:37:19 by dmather           #+#    #+#             */
/*   Updated: 2016/06/12 17:37:21 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <inttypes.h>

void	process_int(t_data *data)
{
	char	*val_str;
	int		arg;

	if (*data->ptr == 'i' || *data->ptr == 'd')
	{
		arg = va_arg(data->ap, int);
		val_str = ft_itoa(arg);
		add_int_flags(data, &val_str, arg);
		data->buff = ft_strnjoin(data->buff, val_str, ft_strlen(val_str));
	}
	else if (*data->ptr == 'c')
	{
		val_str = ft_ctostr(va_arg(data->ap, int));
		data->buff = ft_strnjoin(data->buff, val_str, ft_strlen(val_str));
	}
}

void	process_uint(t_data *data)
{
	char	*val_str;
	size_t	arg;

	arg = 0;
	if (*data->ptr == 'u')
	{
		val_str = ft_uitoa(va_arg(data->ap, unsigned int));
		data->buff = ft_strnjoin(data->buff, val_str, ft_strlen(val_str));
	}
	else if (*data->ptr == 'o')
	{
		arg = va_arg(data->ap, unsigned int);
		if (arg && data->flag == '#')
			data->buff = ft_strnjoin(data->buff, "0", 1);
		val_str = ft_uitoa_base(arg, 8);
		data->buff = ft_strnjoin(data->buff, val_str, ft_strlen(val_str));
	}
	else if (*data->ptr == 'x' || *data->ptr == 'X')
	{
		arg = va_arg(data->ap, unsigned int);
		val_str = ft_uitoa_base(arg, 16);
		process_hex(data, &val_str, arg);
	}
}

void	process_chars(t_data *data)
{
	char	*val_str;

	if (*data->ptr == 's')
	{
		val_str = va_arg(data->ap, char *);
		data->buff = ft_strnjoin(data->buff, val_str, ft_strlen(val_str));
	}
}

void	process_addr(t_data *data)
{
	size_t	addr;
	char	*val_str;

	if (*data->ptr == 'p')
	{
		addr = (uintptr_t)va_arg(data->ap, size_t);
		val_str = ft_uitoa_base(addr, 16);
		data->buff = ft_strnjoin(data->buff, "0x", 2);
		data->buff = ft_strnjoin(data->buff, val_str, ft_strlen(val_str));
	}
}

void	process_args(t_data *data)
{
	if (*data->ptr == '%')
		(data->ptr)++;
	if (*data->ptr == '%')
		data->buff = ft_strnjoin(data->buff, "%", 1);
	while ((data->flag = find_char(&(data->ptr), data->flag_arr)))
		data->flags = ft_strnjoin(data->flags, ft_ctostr(data->flag), 1);
	get_width(data->ap, &(data->ptr), &(data->width));
	if (find_char(&(data->ptr), "."))
		get_prec(data->ap, &(data->ptr), &(data->prec));
	if (*data->ptr == 'i' || *data->ptr == 'd' || *data->ptr == 'c')
		process_int(data);
	else if (*data->ptr == 'u' || *data->ptr == 'o' ||
			*data->ptr == 'x' || *data->ptr == 'X')
		process_uint(data);
	else if (*data->ptr == 's')
		process_chars(data);
	else if (*data->ptr == 'p')
		process_addr(data);
}
