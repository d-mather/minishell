/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 15:01:39 by dmather           #+#    #+#             */
/*   Updated: 2016/09/11 10:36:29 by dmather          ###   ########.fr       */
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
//	e->line = read_it();
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
	return (0);
}
/*
void	redirection(t_env *e)
{
	int		n;
	int		file;
	char	c[1];

	if (ft_strncmp(str, ">", 1) == 0)
	{
		file = open(path, O_RDONLY | O_WRONLY | O_TRUNC);
		write(file,input,ft_strlen(input) + 1);
		close(file);
		return 0;
	}
	if (ft_strncmp(str, ">>", 2) == 0) //needs a condition for NFS file systems 
	{
		file = open(path, O_RDONLY | O_WRONLY | O_APPEND);
		write(file,input,ft_strlen(input) + 1);   
		close(file);
		return 0;
	}
	if (ft_strncmp(str, "<", 1) == 0) // input redirected from a file in this manner
	{
		file = open(path, O_RDONLY);
		while(read(file, c, 1) > 0);
			write(1, c, 1);
		write(1, "\n", 1);
	}
}

char	*read_it(void)
{
	static size_t	pos = 4;
	static ssize_t	eob = 4;
	static char		buff[4];
	char			*temp_line;
	int				i;

	i = 0;
	temp_line = ft_strnew(1);
	ft_bzero(buff, 4);
	while (buff[pos] != '\n' && eob > 0)
	{
		if ((ssize_t)pos == eob)
			if (((pos = 0) == 0) &&
								((eob = read(0, buff, 4)) == -1))
				return (NULL);
		if ((temp_line = sjoin(buff, &pos, eob, temp_line)) == NULL)
			return (NULL);
	//	ft_printf("|%c|\n", temp_line[i]);
		line_eddition(temp_line, i);
	//	if (ft_isprint(temp_line[i]))
	//		ft_putchar(temp_line[i]);
		i++;
	}
//	ft_putstr("\n");
	return (temp_line);
}

void	pipe_loop(t_env *e)
{
	t_split_string	args;
	char			*tmp;
	int				i;

	i = 0;
	tmp = ;
	args = ft_nstrsplit(tmp, "|");
	ft_strdel(&tmp);
	e->pipes = ft_tabdup(args.strings, args.words);
	e->n_pipes = args.words;
	ft_free_tab(&args.strings, args.words);
	while (i < n_pipes)
	{
		ft_pipes(e);
		i++;
	}
}

int		ft_pipes(t_env *e)
{
	int		fd[2];
	int		nbytes;
	pid_t	child_pid;
	char	readbuffer[80];

	pipe(fd);
	if((child_pid = fork()) < 0)
	{
		ft_putstr(C_RED"ERROR: Fork"C_RESET);
		return(0);
	}
	if(child_pid == 0)
	{
		close(fd[0]);
		write(fd[1], input[0], ft_strlen(input[0]) + 1);
		exit(0);
//		return (1);
	}
	else
	{
		close(fd[1]);
		nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
	}
	return(1);
}
*/

