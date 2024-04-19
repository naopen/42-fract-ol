/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 00:55:16 by nkannan           #+#    #+#             */
/*   Updated: 2024/04/20 00:59:28 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	key_press(int keycode, t_fractol *fractol)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		exit(0);
	}
	return (0);
}

static int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		fractol->zoom *= 1.1;
		draw_fractol(fractol);
	}
	else if (button == 5)
	{
		fractol->zoom /= 1.1;
		draw_fractol(fractol);
	}
	return (0);
}

void	init_hooks(t_fractol *fractol)
{
	mlx_key_hook(fractol->win, key_press, fractol);
	mlx_mouse_hook(fractol->win, mouse_hook, fractol);
}
