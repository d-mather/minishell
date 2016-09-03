/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 16:20:40 by dmather           #+#    #+#             */
/*   Updated: 2016/09/03 11:13:30 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	cmd_nf(t_env *e)
{
	char	*in;

	in = e->input[0];
	ft_putstr(C_BLUE"Walala");
	ft_putstr(C_RED"!");
	ft_putstr(C_BLUE" Command not found: "C_GREEN);
	ft_putstr(in);
	ft_putstr(C_BLUE".\n"C_RESET);
}

void	init(t_env *e)
{
	t_term t;

	tgetent(t.term_buffer, getenv("TERM"));
	e->n_cmds = 0;
	e->cmds = NULL;
	e->n_input = 0;
	e->input = NULL;
	e->n_paths = 0;
	e->paths = NULL;
	e->full_paths = NULL;
	e->line = NULL;
	e->execute = NULL;
	e->name = NULL;
}

void	prompt(t_env *e)
{
	char		*prompt;

	prompt = ft_getenv("USER", e->environ);
	ft_putstr(C_PURPLE"");
	ft_putstr(prompt);
	ft_putstr(">> "C_L_BLUE);
}

void	free_all(t_env *e)
{
	ft_free_tab(&e->cmds, e->n_cmds);
	ft_free_tab(&e->full_paths, e->n_paths);
	ft_free_tab(&e->paths, e->n_paths);
}

int		ft_issp(char *o)
{
	int	i;

	i = 0;
	if (o)
	{
		if (o[i] == '\0' || o[i] == '\n')
			return (0);
		while (o[i] == ' ' || o[i] == '\t')
		{
			if (o[i] == '\0' || o[i] == '\n')
				return (0);
			i++;
		}
		return (CONT);
	}
	return (0);
}
