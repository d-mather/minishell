/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 15:01:39 by dmather           #+#    #+#             */
/*   Updated: 2016/09/02 14:54:45 by dmather          ###   ########.fr       */
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
		if (ft_strncmp(e->cmds[i], "", 1) == 0)
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

/*
void	read_it(t_env *e)
{
	char	line[1];
	int		file;
	int		i;

	file = 1;
	i = 0;
	e->line = ft_memalloc(1000);
	while((file = read(0, &line, 4)) > 0 && line[i] != '\n')
	{
		e->line[i] = line[i];
		i++;
	}
}
*/

int		get_command(t_env *e)
{
	t_split_string	args;
	char			*tmp;

	prompt(e);
	set_input_mode();
//	read_it(e);
	ft_gnl(0, &e->line);
	reset_input_mode();
	tmp = ft_strtrim(e->line);
	ft_strdel(&e->line);
	e->line = tmp;
	if (ft_issp(e->line) == 0)
	{
		if (!e->line)
			return (0);
		ft_strdel(&e->line);
		return (0);
	}
	args = ft_nstrsplit(e->line, ';');
	e->cmds = ft_tabdup(args.strings, args.words);
	e->n_cmds = args.words;
	ft_free_tab(&args.strings, args.words);
	ft_strdel(&e->line);
	return (get_input(e));
}

void	save_env(char **envp, t_env *e)
{
	int	i;

	e->ie = 0;
	i = 0;
	while (envp[i])
	{
		e->ie++;
		i++;
	}
	e->environ = (char **)malloc(sizeof(char *) * e->ie + 1);
	i = 0;
	while (i < e->ie)
	{
		e->environ[i] = envp[i];
		i++;
	}
//	e->environ[e->ie] = NULL;
}

int		main(int argc, char *argv[], char **envp)
{
	t_env	e;

	e.environ = NULL;
	if (argc > 1 && argv[1])
		ft_putstr(C_RED"No arguments handled yet\n"C_RESET);
	save_env(envp, &e);
	e.stat = 1;
	while (e.stat)
	{
		init(&e);
		if (get_command(&e) == 0)
			continue;
		free_all(&e);
	}
//	ft_free_tab(&e.environ, e.ie);
	return (0);
}
