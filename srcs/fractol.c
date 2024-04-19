/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:12:45 by nkannan           #+#    #+#             */
/*   Updated: 2024/04/19 23:02:06 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	plot_pixel(t_fractol *fractol, int x, int y, int color)
{
	char	*dst;

	dst = fractol->image.pixels + (y * fractol->image.line_size + x
			* (fractol->image.bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_fractal(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y < fractol->height)
	{
		x = 0;
		while (x < fractol->width)
		{
			plot_pixel(fractol, x, y, 0x00FF00);
			x++;
		}
		y++;
	}
}
