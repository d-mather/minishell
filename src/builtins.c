/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 16:03:29 by dmather           #+#    #+#             */
/*   Updated: 2016/09/07 16:08:38 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		ft_cd(t_env *e)
{
	char	*cwd;
	int		i;

	i = 1;
	if (e->n_input == 1)
	{
		chdir(ft_getenv("HOME", e->environ));
		return (CONT);
	}
	if (e->input[1][0] != '/')
	{
		cwd = NULL;
		cwd = getcwd(cwd, ft_strlen(cwd));
		ft_strcat(cwd, "/");
		ft_strcat(cwd, e->input[1]);
		i = chdir(cwd);
		ft_strdel(&cwd);
	}
	else if (e->input[1][0] == '/')
		i = chdir(e->input[1]);
	if (i != 0)
		ft_putstr(C_RED"No such file or directory. Walala!\n"C_RESET);
	return (CONT);
}

void	print_paren_man(t_paren_manage *pm, int j)
{
	int	i;

	i = 0;
	while (i <= j)
	{
		ft_putstr("\n");
		if (pm->p_m_lines[i][0] == '\"')
			pm->p_m_lines[i] = NULL;
		else if (pm->p_m_lines[i][0] == '\"' ||
					pm->p_m_lines[i][ft_strlen(pm->p_m_lines[i]) - 1] == '\"')
			pm->p_m_lines[i] = ft_trim_qu(pm->p_m_lines[i]);
		if (pm->p_m_lines[i] != NULL)
			ft_putstr(pm->p_m_lines[i]);
		i++;
	}
	ft_putstr("\n");
}

int		parenthesis_management(void)
{
	t_paren_manage	pm;
	int				word;

	word = 0;
	pm.p_m_lines = (char **)malloc(sizeof (char *) * 100);
	ft_putstr("*>");
	while (ft_gnl(0, &pm.p_m_lines[word]) && ft_strcmp(pm.p_m_lines[word], "\"") &&
				pm.p_m_lines[word][ft_strlen(pm.p_m_lines[word]) - 1] != '\"')
	{
		if (!pm.p_m_lines[word] || pm.p_m_lines[word][0] == '\0')
		{
			ft_printf("You entered Enter! :)\n");
			pm.p_m_lines[word] = "\n";
		//	word++;
		//	ft_putstr("*>");
		//	continue ;
		}
		ft_putstr("*>");
		word++;
	}
	print_paren_man(&pm, word);
	ft_free_tab(&pm.p_m_lines, word + 1);
	return (CONT);
}

int		ft_echo(t_env *e)
{
	char		*env;

	env = NULL;
	if (e->n_input <= 1)
		ft_putstr("\n");
	else if (!ft_strcmp(e->input[1], "\""))
		return (parenthesis_management());
	else if (e->input[1][0] == '$' ||
							(e->input[1][0] == '\"' && e->input[1][1] == '$'))
	{
		env = ft_getenv(ft_trim_qu(ft_strchr(e->input[1], '$')) + 1,
																	e->environ);
		if (ft_strcmp(env, ft_strchr(e->input[1], '$')) == 0)
			ft_putstr(C_RED"Invalid environment."C_RESET);
		else
			ft_putstr(env);
		ft_putstr("\n");
	}
	else
		more_echo(e);
	return (CONT);
}

void	more_echo(t_env *e)
{
	int		i;
	char	*o;

	i = 1;
	while (i < e->n_input)
	{
		o = ft_strjoin(ft_trim_qu(e->input[i]), " ");
		ft_putstr(o);
		ft_strdel(&o);
		i++;
	}
	ft_putstr("\n");
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
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (i < e->ie)
	{
		tmp = NULL;
		tmp = e->environ[i++];
		ft_putstr(tmp);
		ft_putstr("\n");
	}
	return (CONT);
}
