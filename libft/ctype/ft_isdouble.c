/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:47:58 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/03 19:28:26 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

bool	ft_isdouble(char *str)
{
	size_t	i;
	bool	is_dot;
	bool	has_digit;

	is_dot = false;
	has_digit = false;
	i = 0;
	if (str == NULL || *str == '\0')
		return (false);
	if (*str == '-' || *str == '+')
		str++;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (is_dot) // 小数点が2度目に現れた場合
				return (false);
			is_dot = true;
		}
		else if (ft_isdigit(str[i]))
			has_digit = true; // 数値部分が少なくとも1つは存在する
		else
			return (false); // 数値でも小数点でもない文字があった場合
		i++;
	}
	return (has_digit); // 数値部分が1つもない場合はfalseを返す
}
