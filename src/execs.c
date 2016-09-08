/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 17:58:59 by dmather           #+#    #+#             */
/*   Updated: 2016/09/08 07:17:49 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	run_it(t_env *e)
{
	if (e->input[0][0] == '/')
	{
		if (access(e->input[0], F_OK) == 0)
			execve(e->input[0], e->input, e->environ);
		else
			ft_putstr(C_RED"Invalid program or path to file program\n"C_RESET);
		exit(0);
	}
	else
	{
		execve(e->execute, e->input, e->environ);
		exit(0);
	}
}

int		system_func(t_env *e)
{
	pid_t	pid;

	get_full_paths(e);
	if (accessible(e) == 1)
	{
		if ((pid = fork()) < 0)
		{
			ft_putstr(C_RED"Unfortunately: Forking error.\n"C_RESET);
			return (CONT);
		}
		if (pid == 0)
			run_it(e);
		wait(&pid);
	}
	else
		return (0);
	return (CONT);
}
