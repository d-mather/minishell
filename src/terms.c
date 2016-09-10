/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 11:51:51 by dmather           #+#    #+#             */
/*   Updated: 2016/09/10 18:05:28 by dmather          ###   ########.fr       */
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

	if (!isatty(STDIN_FILENO))
	{
		ft_putstr(C_RED"Not a terminal.\n"C_RESET);
		exit(EXIT_FAILURE);
	}
	tcgetattr(STDIN_FILENO, &saved_attributes);
	atexit(reset_input_mode);
	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag &= ~(ICANON);
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &tattr);
}
