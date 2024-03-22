/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 06:24:10 by nkannan           #+#    #+#             */
/*   Updated: 2024/03/23 06:40:36 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isdouble_helper(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '.')
		return (0);
	return (1);
}

int	ft_isdouble(char *str)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	if (!ft_isdouble_helper(str))
		return (0);
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (dot)
				return (0);
			dot = 1;
		}
		else if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (str[i - 1] == '.')
		return (0);
	return (1);
}
