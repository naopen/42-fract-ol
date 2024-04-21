/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:12:45 by nkannan           #+#    #+#             */
/*   Updated: 2024/04/21 17:01:09 by nkannan          ###   ########.fr       */
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

static void	draw_mandelbrot(t_fractol *fractol, int x, int y)
{
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
	int		i;

	c_re = (x - fractol->width / 2.0) * 4.0 / fractol->width;
	c_im = (y - fractol->height / 2.0) * 4.0 / fractol->height;
	z_re = 0;
	z_im = 0;
	i = 0;
	while (z_re * z_re + z_im * z_im <= 4 && i < MAX_ITER)
	{
		double next_z_re = z_re * z_re - z_im * z_im + c_re;
		z_im = 2 * z_re * z_im + c_im;
		z_re = next_z_re;
		i++;
	}
	if (i == MAX_ITER)
		plot_pixel(fractol, x, y, 0x000000);
	else
		plot_pixel(fractol, x, y, 0x0000FF);
}

void	draw_julia(t_fractol *fractol, int x, int y)
{
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
	int		i;

	c_re = -0.7;
	c_im = 0.27015;
	z_re = (x - fractol->width / 2.0) * 4.0 / fractol->width;
	z_im = (y - fractol->height / 2.0) * 4.0 / fractol->height;
	i = 0;
	while (z_re * z_re + z_im * z_im <= 4 && i < MAX_ITER)
	{
		double next_z_re = z_re * z_re - z_im * z_im + c_re;
		z_im = 2 * z_re * z_im + c_im;
		z_re = next_z_re;
		i++;
	}
	if (i == MAX_ITER)
		plot_pixel(fractol, x, y, 0x000000);
	else
		plot_pixel(fractol, x, y, 0x0000FF);
}

void	draw_fractol(t_fractol *fractol)
{
	int	x;
	int	y;

	if (fractol->image.img != NULL)
		mlx_destroy_image(fractol->mlx, fractol->image.img);

	fractol->image.img = mlx_new_image(fractol->mlx, fractol->width, fractol->height);
	fractol->image.pixels = mlx_get_data_addr(fractol->image.img, &fractol->image.bpp, &fractol->image.line_size, &fractol->image.endian);

	y = 0;
	while (y < fractol->height)
	{
		x = 0;
		while (x < fractol->width)
		{
			if (ft_strncmp(fractol->type, "mandelbrot", 10) == 0)
				draw_mandelbrot(fractol, x, y);
			else if (ft_strncmp(fractol->type, "julia", 5) == 0)
				draw_julia(fractol, x, y);
			x++;
		}
		y++;
	}

	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->image.img, 0, 0);
}
