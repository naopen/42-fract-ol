/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 06:49:37 by nkannan           #+#    #+#             */
/*   Updated: 2024/04/21 23:37:29 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_atof_helper(const char *str, int *i, double *frac_part, int *neg)
{
	while (str[*i] && str[*i] != '.')
		(*i)++;
	if (str[*i] == '.')
	{
		(*i)++;
		*frac_part = (double)ft_atoi(str + *i);
		while (ft_isdigit(str[*i]))
		{
			*frac_part /= 10;
			(*i)++;
		}
		*frac_part *= *neg;
	}
	else
		*frac_part = 0;
}

double	ft_atof(const char *str)
{
	double	result;
	double	frac_part;
	int		i;
	int		neg;

	result = 0;
	frac_part = 0;
	i = 0;
	neg = 1;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	result = (double)ft_atoi(str + i) * neg;
	ft_atof_helper(str, &i, &frac_part, &neg);
	return (result + frac_part);
}
