/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 17:38:25 by dmather           #+#    #+#             */
/*   Updated: 2016/09/11 11:50:41 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		ft_echo(t_env *e)
{
	char		*env;
	char		*tmp;
	int			y;

	env = NULL;
	y = check_dquote(e);
	if (e->n_input <= 1)
		ft_putstr("\n");
	else if (y == 1)
		return (parenthesis_management());
	else if (e->input[1][0] == '$' ||
							(e->input[1][0] == '\"' && e->input[1][1] == '$'))
	{
		tmp = ft_trim_qu(ft_strchr(e->input[1], '$'));
		env = ft_getenv(tmp + 1, e->environ);
		if (ft_strcmp(env, ft_strchr(e->input[1], '$')) == 0)
			ft_putstr(C_RED"Invalid environment."C_RESET);
		else
			ft_putstr(env);
		ft_putstr("\n");
		ft_strdel(&tmp);
	}
	else
		more_echo(e);
	return (CONT);
}

void	more_echo(t_env *e)
{
	int		i;
	char	*o;
	char	*tmp;

	i = 1;
	tmp = NULL;
	while (i < e->n_input)
	{
		tmp = ft_trim_qu(e->input[i]);
		ft_strdel(&e->input[i]);
		e->input[i] = ft_strdup(tmp);
		o = ft_strjoin(e->input[i], " ");
		ft_strdel(&tmp);
		ft_putstr(o);
		ft_strdel(&o);
		i++;
	}
	ft_putstr("\n");
}

int		check_dquote(t_env *e)
{
	int	i;
	int	j;
	int	y;

	y = 0;
	j = e->n_input;
	if (!e->input[1])
		return (y);
	while (e->input[j - 1] && y <= 2)
	{
		i = 0;
		if (!ft_strcmp(e->input[j - 1], "echo"))
			return (y);
		while (e->input[j - 1][i] && y <= 2)
		{
			if (e->input[j - 1][i] == '\"')
				y++;
			i++;
		}
		j--;
	}
	return (y);
}

int		parenthesis_management(void)
{
	t_paren_manage	pm;
	int				word;

	word = 0;
	pm.p_m_lines = (char **)ft_memalloc(sizeof(char *) * 100);
	ft_putstr("*>");
	set_input_mode();
	ft_gnl(0, &pm.p_m_lines[word]);
	if (!pm.p_m_lines[word])
		pm.p_m_lines[word] = "\n";
	while (pm.p_m_lines[word] &&
			pm.p_m_lines[word][ft_strlen(pm.p_m_lines[word]) - 1] != '\"')
	{
		if (!pm.p_m_lines[word])
			pm.p_m_lines[word] = "\n";
		word++;
		ft_putstr("*>");
		ft_gnl(0, &pm.p_m_lines[word]);
		if (!pm.p_m_lines[word])
			pm.p_m_lines[word] = "\n";
	}
	reset_input_mode();
	print_paren_man(&pm, word);
	ft_free_tab(&pm.p_m_lines, word + 1);
	return (CONT);
}

void	print_paren_man(t_paren_manage *pm, int j)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i <= j)
	{
		ft_putstr("\n");
		if (!pm->p_m_lines[i])
			pm->p_m_lines[i] = NULL;
		else if (pm->p_m_lines[i][0] == '\"')
			return ;
		else if (pm->p_m_lines[i][ft_strlen(pm->p_m_lines[i]) - 1] == '\"')
		{
			tmp = ft_strdup(pm->p_m_lines[i]);
			ft_strdel(&pm->p_m_lines[i]);
			pm->p_m_lines[i] = ft_trim_qu(tmp);
			ft_strdel(&tmp);
		}
		if (pm->p_m_lines[i] != NULL)
			ft_putstr(pm->p_m_lines[i]);
		i++;
	}
	ft_putstr("\n");
}
