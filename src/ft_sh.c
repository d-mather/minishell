/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 15:01:39 by dmather           #+#    #+#             */
/*   Updated: 2016/09/11 11:32:02 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		run_commands(t_env *e)
{
	ft_putstr(C_BLUE"");
	if (!ft_strcmp(e->input[0], "exit"))
		return (ex(e));
	else if (!ft_strcmp(e->input[0], "setenv"))
		return (ft_setenv(e));
	else if (!ft_strcmp(e->input[0], "unsetenv"))
		return (ft_unsetenv(e));
	else if (!ft_strcmp(e->input[0], "env"))
		return (ft_env(e));
	else if (!ft_strcmp(e->input[0], "cd"))
		return (ft_cd(e));
	else if (!ft_strcmp(e->input[0], "echo"))
		return (ft_echo(e));
	else if (system_func(e) == 1)
		return (CONT);
	else
		cmd_nf(e);
	ft_putstr(""C_RESET);
	return (CONT);
}

int		get_input(t_env *e)
{
	t_split_string	args;
	int				i;
	char			*tmp;

	i = 0;
	while (i < e->n_cmds && e)
	{
		if (ft_strncmp(e->cmds[i], "", 1) == 0 || !ft_strcmp(e->cmds[i], " "))
		{
			ft_putstr(C_RED
					"bash: syntax error near unexpected token\';\'\n"C_RESET);
			break ;
		}
		tmp = ft_strtrim(e->cmds[i]);
		args = ft_nstrsplit(tmp, ' ');
		ft_strdel(&tmp);
		e->input = ft_tabdup(args.strings, args.words);
		e->n_input = args.words;
		ft_free_tab(&args.strings, args.words);
		e->stat *= run_commands(e);
		ft_free_tab(&e->input, e->n_input);
		i++;
	}
	return (CONT);
}

int		get_command(t_env *e)
{
	t_split_string	args;
	char			*tmp;

	tmp = NULL;
	prompt(e);
	set_input_mode();
	ft_gnl(0, &e->line);
	reset_input_mode();
	if (ft_issp(e->line) == 0)
	{
		ft_strdel(&e->line);
		return (CONT);
	}
	tmp = ft_strtrim(e->line);
	ft_strdel(&e->line);
	e->line = tmp;
	args = ft_nstrsplit(e->line, ';');
	e->cmds = ft_tabdup(args.strings, args.words);
	e->n_cmds = args.words;
	ft_free_tab(&args.strings, args.words);
	ft_strdel(&e->line);
	return (get_input(e));
}

void	save_env(char **envp, t_env *e)
{
	e->environ = ft_tabdup(envp, ft_tablen(envp));
	e->ie = ft_tablen(e->environ);
}

int		main(int argc, char *argv[], char **envp)
{
	t_env	e;

	e.environ = NULL;
	e.last_cwd = ft_strnew(24);
	if (argc > 1 && argv[1])
		ft_putstr(C_RED"No arguments handled yet\n"C_RESET);
	save_env(envp, &e);
	e.stat = 1;
	while (e.stat)
	{
		init(&e);
		if (get_command(&e) == 0)
			continue;
		ft_free_tab(&e.cmds, e.n_cmds);
	}
	ft_free_tab(&e.environ, e.ie);
	if (e.last_cwd != NULL)
		ft_strdel(&e.last_cwd);
	return (0);
}
