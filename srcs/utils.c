/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 05:07:24 by nkannan           #+#    #+#             */
/*   Updated: 2024/03/23 05:31:45 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"
#include "../libft/libft.h"

static void	error_msg(char *str)
{
	ft_putendl_fd(str, 2);
}

static void	usage_msg(void)
{
	ft_putstr_fd("\x1b[31m", 2);
	error_msg("Error : Invalid input");
	exit(1);
}

void	validates_args(int argc, char *argv[])
{
	if (argc != 5)
	{
		printf("Error: Invalid number of arguments\n");
		exit(1);
	}
	if (ft_strlen(argv[1]) != 1 || ft_strlen(argv[2]) != 1)
	{
		printf("Error: Invalid operator\n");
		exit(1);
	}
	if (ft_strlen(argv[3]) == 0 || ft_strlen(argv[4]) == 0)
	{
		printf("Error: Invalid number\n");
		exit(1);
	}
}
