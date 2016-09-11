/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 16:03:29 by dmather           #+#    #+#             */
/*   Updated: 2016/09/11 10:59:32 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		ft_cd(t_env *e)
{
	char	*cwd;
	char	*tmp;
	int		i;

	i = 1;
	if (e->n_input == 1)
		i = chdir(ft_getenv("HOME", e->environ));
	else if (e->input[1][0] == '/')
		i = chdir(e->input[1]);
	else if (e->input[1][0] == '-')
		i = chdir(e->last_cwd);
	else if (e->input[1][0] == '~')
		i = more_cd(e, i);
	else if (e->input[1][0] != '/')
	{
		cwd = NULL;
		cwd = getcwd(cwd, ft_strlen(cwd));
		tmp = ft_strdup(cwd);
		ft_strdel(&cwd);
		cwd = ft_nstrjoin(tmp, "/", e->input[1]);
		ft_strdel(&tmp);
		i = chdir(cwd);
		if (i == 0)
		{
			ft_strdel(&e->last_cwd);
			e->last_cwd = ft_strdup(cwd);
		}
		ft_strdel(&cwd);
	}
	if (i != 0)
		ft_putstr(C_RED"No such file or directory. Walala!\n"C_RESET);
	return (CONT);
}

int		more_cd(t_env *e, int i)
{
	char	*path;

	path = NULL;
	if (!ft_strcmp(e->input[1], "~"))
	{
		i = chdir(ft_getenv("HOME", e->environ));
		if (i == 0)
		{
			ft_strdel(&e->last_cwd);
			e->last_cwd = ft_strdup(ft_getenv("HOME", e->environ));
		}
	}
	else
	{
		path = ft_strchr(e->input[1], '/');
		path = ft_strjoin(ft_getenv("HOME", e->environ), path);
		i = chdir(path);
		if (i == 0)
		{
			ft_strdel(&e->last_cwd);
			e->last_cwd = ft_strdup(path);
		}
		ft_strdel(&path);
	}
	return (i);
}

int		ex(t_env *e)
{
	if (e->n_input > 2)
	{
		ft_putstr(C_RED"bash: exit: too many arguments\n"C_RESET);
		return (0);
	}
	else if (e->n_input == 2)
	{
		if (ft_isint(e->input[1]) == 1)
		{
			ft_putstr(C_RED"There are stopped jobs.\n"C_RESET);
			return (0);
		}
		else
		{
			ft_putstr(C_RED"bash: exit: numeric argument required\n"C_RESET);
			return (0);
		}
	}
	else
	{
		ft_putstr(C_RED"exit\n"C_RESET);
		return (0);
	}
}

int		ft_env(t_env *e)
{
	int		i;

	i = 0;
	while (i < e->ie)
	{
		ft_putstr(e->environ[i]);
		ft_putstr("\n");
		++i;
	}
	return (CONT);
}
