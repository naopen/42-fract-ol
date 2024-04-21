/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:47:58 by nkannan           #+#    #+#             */
/*   Updated: 2024/04/22 00:03:41 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

bool	ft_isdouble(char *str)
{
	size_t	i;
	bool	is_dot;

	is_dot = false;
	i = 0;
	if (str == NULL || *str == '\0')
		return (false);
	if (*str == '-')
		str++;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (is_dot)
				return (false);
			is_dot = true;
		}
		else if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}
