/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 00:55:16 by nkannan           #+#    #+#             */
/*   Updated: 2024/04/30 20:58:43 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	key_press(int keycode, t_fractol *fractol)
{
	const double	move_step = MOVE_STEP / fractol->zoom;

	if (keycode == ESC)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		exit(0);
	}
	else if (keycode == LEFT_ARROW)
		fractol->offset_x -= move_step;
	else if (keycode == RIGHT_ARROW)
		fractol->offset_x += move_step;
	else if (keycode == UP_ARROW)
		fractol->offset_y -= move_step;
	else if (keycode == DOWN_ARROW)
		fractol->offset_y += move_step;
	draw_fractol(fractol);
	return (0);
}

void	update_zoom_and_color(int button, t_fractol *fractol, double *new_zoom,
		double *interpolation)
{
	if (button == 4)
	{
		fractol->color_shift += COLOR_SHIFT;
		*new_zoom = fractol->zoom * ZOOM_IN;
		*interpolation = 1.0 / ZOOM_IN;
	}
	else if (button == 5)
	{
		fractol->color_shift -= COLOR_SHIFT;
		*new_zoom = fractol->zoom * ZOOM_OUT;
		*interpolation = 1.0 / ZOOM_OUT;
	}
	else
	{
		*new_zoom = fractol->zoom;
		*interpolation = 1.0;
	}
}

static int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	double	mouse_re;
	double	mouse_im;
	double	new_zoom;
	double	interpolation;

	mouse_re = (double)(x - fractol->width / 2) / (0.5 * fractol->zoom
			* fractol->width) + fractol->offset_x;
	mouse_im = (double)(y - fractol->height / 2) / (0.5 * fractol->zoom
			* fractol->height) + fractol->offset_y;
	update_zoom_and_color(button, fractol, &new_zoom, &interpolation);
	fractol->offset_x = mouse_re + ((fractol->offset_x - mouse_re)
			* interpolation);
	fractol->offset_y = mouse_im + ((fractol->offset_y - mouse_im)
			* interpolation);
	fractol->zoom = new_zoom;
	draw_fractol(fractol);
	return (0);
}

static int	close_window(t_fractol *fractol)
{
	(void)fractol;
	mlx_destroy_window(fractol->mlx, fractol->win);
	exit(0);
	return (0);
}

void	init_hooks(t_fractol *fractol)
{
	mlx_mouse_hook(fractol->win, mouse_hook, fractol);
	mlx_key_hook(fractol->win, key_press, fractol);
	mlx_hook(fractol->win, 17, 0, close_window, fractol);
}
