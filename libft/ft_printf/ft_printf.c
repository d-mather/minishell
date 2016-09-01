/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 17:37:12 by dmather           #+#    #+#             */
/*   Updated: 2016/06/12 17:37:14 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	init_data(t_data *data, const char *format)
{
	data->ptr = (char *)format;
	data->buff = ft_strnew(1);
	data->flag_arr = "#0+- ";
	data->flag = -1;
	data->flags = ft_strnew(1);
	data->left_align = 0;
	data->width = 0;
	data->prec = 0;
}

int		analyze(t_data *data, const char *format)
{
	init_data(data, format);
	while (*data->ptr != '\0')
	{
		if (*data->ptr == '%')
			process_args(data);
		else
			data->buff = ft_strnjoin(data->buff, data->ptr, 1);
		data->ptr++;
	}
	ft_putstr(data->buff);
	return (ft_strlen(data->buff));
}

int		ft_printf(const char *format, ...)
{
	int		ret;
	t_data	data;

	ret = 0;
	if (*format)
	{
		va_start(data.ap, format);
		ret = analyze(&data, format);
		va_end(data.ap);
	}
	return (ret);
}
