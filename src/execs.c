/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 17:58:59 by dmather           #+#    #+#             */
/*   Updated: 2016/09/10 18:02:04 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	run_it(t_env *e)
{
	if (e->input[0][0] == '/')
	{
		free_all(e);
		execve(e->input[0], e->input, e->environ);
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
		free_all(e);
		return (CONT);
	}
	else
	{
		free_all(e);
		return (0);
	}
}

void	more_setenv(t_env *e)
{
	char	**tmp2;
	char	*tmp;

	tmp2 = ft_tabdup(e->environ, ++e->ie);
	ft_free_tab(&e->environ, e->ie);
	e->environ = tmp2;
	tmp = e->input[1];
	e->input[1] = ft_trim_qu(tmp);
	ft_strdel(&tmp);
	e->environ[e->ie - 1] = ft_strdup(e->input[1]);
}

int		more_unsetenv(t_env *e)
{
	ft_putstr(C_RED"Invironment variable not found\n"C_RESET);
	ft_strdel(&e->name);
	return (CONT);
}
