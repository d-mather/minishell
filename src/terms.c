/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 11:51:51 by dmather           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/09/01 14:37:15 by dmather          ###   ########.fr       */
=======
/*   Updated: 2016/08/27 17:40:23 by dmather          ###   ########.fr       */
>>>>>>> 055a3bf3d38ffa79f11bcbd199d95b173beac010
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
