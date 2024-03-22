/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 08:38:20 by nkannan           #+#    #+#             */
/*   Updated: 2024/03/23 04:32:54 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// Convert a string to an integer.
// If the string is not a valid integer, return 0.
// Integers can start with an optional '+' or '-' sign.
// Integers can contain digits only.
// Convert the string until the first non-digit character.

// ——About strtol——
// If it overflows, LONG_MAX or LONG_MIN is returned.

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

// Function to determine if 'num' will overflow
static int	ft_is_overflow(unsigned long long num, int sign, unsigned int digit)
{
	if (num > LONG_MAX / 10 || (num == LONG_MAX / 10 && digit > LONG_MAX % 10))
	{
		if (sign == 1)
			return (1);
		else
			return (-1);
	}
	return (0);
}

static long	ft_strtol(const char *restrict str, char **restrict endptr)
{
	unsigned long long	num;
	int					sign;

	num = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		if (ft_is_overflow(num, sign, *str - '0'))
		{
			if (sign == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		num = num * 10 + (*str++ - '0');
	}
	if (endptr)
		*endptr = (char *)str;
	return (num * sign);
}

int	ft_atoi(const char *str)
{
	return ((int)ft_strtol(str, NULL));
}
