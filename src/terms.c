/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 11:51:51 by dmather           #+#    #+#             */
/*   Updated: 2016/09/06 22:45:42 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	reset_input_mode(void)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &saved_attributes);
}

void	set_input_mode(void)
{
	struct termios	tattr;

	/* Make sure stdin is a terminal. */
	if (!isatty(STDIN_FILENO))
	{
		ft_putstr(C_RED"Not a terminal.\n"C_RESET);
		exit(EXIT_FAILURE);
	}
	/* Save the terminal attributes so we can restore them later. */
	tcgetattr(STDIN_FILENO, &saved_attributes);
	atexit(reset_input_mode);
	/* Set the funny terminal modes. */
	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag &= ~(ICANON);// | ECHO); /* Clear ICANON and ECHO. */
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &tattr);
}
/*
int		tputs_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void	line_eddition(char *line, int i)
{
	//ft_putnbr(i);
	if (line[i] == 27)
	{
		i++;
		if (line[i] == '[')
		{
			i++;
			if (line[i] == 'D')
				tputs(tgetstr("le", NULL), 1, tputs_putchar);
		}
	}
//	else
//	{
//		ft_putchar(line[i]);
//	}
}*/
