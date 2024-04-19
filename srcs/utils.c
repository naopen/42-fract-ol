/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 05:07:24 by nkannan           #+#    #+#             */
/*   Updated: 2024/04/19 23:08:53 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"
#include "../libft/libft.h"

static void	color_msg(char *color, char *msg, int fd)
{
	ft_putstr_fd(color, fd);
	ft_putendl_fd(msg, fd);
	ft_putstr_fd("\x1b[0m", fd);
}

static void	error_msg(char *msg)
{
	color_msg("\x1b[31m", msg, 2);
}

static void	malloc_error(void)
{
	error_msg("Error : Malloc failed.");
	exit(1);
}

static void	usage_msg_and_exit(void)
{
	ft_putendl_fd("", 2);
	color_msg("\x1b[31m", "Usage : ./fractol mandelbrot", 2);
	color_msg("\x1b[31m", "        ./fractol julia [number1] [number2]", 2);
	ft_putendl_fd("", 2);
	color_msg("\033[1;34m", "Tips  : The numbers must be between -2 to 2.", 2);
	color_msg("\033[1;34m", "Recomend :", 2);
	color_msg("\033[1;34m", "        ./fractol julia 0 0.67", 2);
	color_msg("\033[1;34m", "        ./fractol julia 0.116 0.66", 2);
	exit(1);
}

void	validates_args(int argc, char *argv[])
{
	if (argc != 2 && argc != 4 || argc == 4 && ft_strncmp(argv[1], "mandelbrot",
			10) == 0 || argc == 2 && ft_strncmp(argv[1], "julia", 5 == 0))
	{
		error_msg("Error : Invalid number of arguments.");
		usage_msg_and_exit();
	}
	else if (ft_strncmp(argv[1], "mandelbrot", 10) != 0 && ft_strncmp(argv[1],
			"julia", 5) != 0)
	{
		error_msg("Error : Invalid fractol name.");
		usage_msg_and_exit();
	}
	else if (argc == 4)
	{
		if (!ft_isdouble(argv[2]) || !ft_isdouble(argv[3] || ft_atof(argv[2]) < \
				-2 || ft_atof(argv[2]) > 2 || ft_atof(argv[3]) < -2
				|| ft_atof(argv[3]) > 2))
			error_msg("Error : Invalid number format.");
		usage_msg_and_exit();
	}
}
