/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 17:00:58 by dmather           #+#    #+#             */
/*   Updated: 2016/06/12 17:01:01 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnclear(t_list **begin_list, int nb)
{
	t_list	*list;
	t_list	*tmp;
	int		i;

	list = *begin_list;
	tmp = NULL;
	i = -1;
	while (list && ++i < nb)
	{
		if (list->next)
			tmp = list->next;
		else
			tmp = NULL;
		free(list);
		list = tmp;
	}
	*begin_list = NULL;
	return (list);
}
