/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 16:54:21 by dmather           #+#    #+#             */
/*   Updated: 2016/09/11 11:33:16 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H

# include "libft.h"

# define CONT 1
# define UNSETENV_FIND (ft_strncmp(e->environ[i], e->name, ft_strlen(e->name)))

struct termios	saved_attributes;

typedef struct		s_env
{
	char			*line;
	int				stat;
	char			**input;
	int				n_input;
	char			**full_paths;
	char			**paths;
	int				n_paths;
	char			**cmds;
	int				n_cmds;
	char			**environ;
	int				ie;
	char			*execute;
	char			*name;
	char			**pipes;
	int				n_pipes;
	char			*last_cwd;
}					t_env;

typedef struct		s_paren_manage
{
	char			**p_m_lines;
}					t_paren_manage;

typedef struct		s_term
{
	char			*term_buffer;
}					t_term;

/*
** ft_sh.c
*/
int					run_commands(t_env *e);
int					get_input(t_env *e);
int					get_command(t_env *e);
void				save_env(char **envp, t_env *e);

/*
** execs.c
*/
void				run_it(t_env *e);
int					system_func(t_env *e);
void				more_setenv(t_env *e);
int					more_unsetenv(t_env *e);

/*
** ft_getenv.c
*/
void				get_full_paths(t_env *e);
int					accessible(t_env *e);
char				*ft_getenv(char *name, char **envp);
int					ft_setenv(t_env *e);
int					ft_unsetenv(t_env *e);

/*
** builtins.c
*/
int					ft_cd(t_env *e);
int					more_cd(t_env *e, int i);
int					even_more_cd(t_env *e, int i);
int					ex(t_env *e);
int					ft_env(t_env *e);

/*
** builtin_echo.c
*/
int					ft_echo(t_env *e);
void				more_echo(t_env *e);
int					check_dquote(t_env *e);
int					parenthesis_management(void);
void				print_paren_man(t_paren_manage *pm, int j);

/*
** small.c
*/
void				cmd_nf(t_env *e);
void				init(t_env *e);
void				prompt(t_env *e);
void				free_all(t_env *e);
int					ft_issp(char *o);

/*
** terms.c
*/
void				reset_input_mode(void);
void				set_input_mode(void);

#endif
