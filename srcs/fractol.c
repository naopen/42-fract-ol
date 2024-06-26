/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:12:45 by nkannan           #+#    #+#             */
/*   Updated: 2024/04/30 23:08:34 by nkannan          ###   ########.fr       */
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

int	calculate_fractal_pixel(double z_re, double z_im, double c_re, double c_im)
{
	int		n;
	double	next_z_re;

	n = 0;
	next_z_re = 0;
	while (z_re * z_re + z_im * z_im <= 4 && n < MAX_ITER)
	{
		next_z_re = z_re * z_re - z_im * z_im + c_re;
		z_im = 2 * z_re * z_im + c_im;
		z_re = next_z_re;
		n++;
	}
	return (n);
}

void	process_fractal_pixel(t_fractol *fractol, int x, int y,
		const char *fractal_type)
{
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
	int		iteration;

	c_re = (x - fractol->width / 2.0) / (fractol->width / (fractol->zoom * 4))
		+ fractol->offset_x;
	c_im = (y - fractol->height / 2.0) / (fractol->height / (fractol->zoom * 4))
		+ fractol->offset_y;
	z_re = 0;
	z_im = 0;
	iteration = 0;
	if (ft_memcmp(fractal_type, "julia", 6) == 0)
	{
		c_re = fractol->julia_re;
		c_im = fractol->julia_im;
		z_re = (x - fractol->width / 2.0) / (fractol->width / (fractol->zoom
					* 4)) + fractol->offset_x;
		z_im = (y - fractol->height / 2.0) / (fractol->height / (fractol->zoom
					* 4)) + fractol->offset_y;
	}
	iteration = calculate_fractal_pixel(z_re, z_im, c_re, c_im);
	plot_pixel(fractol, x, y, calculate_color(iteration, fractol));
}

void	draw_fractol(t_fractol *fractol)
{
	int	x;
	int	y;

	if (fractol->image.img != NULL)
		mlx_destroy_image(fractol->mlx, fractol->image.img);
	fractol->image.img = mlx_new_image(fractol->mlx, fractol->width,
			fractol->height);
	fractol->image.pixels = mlx_get_data_addr(fractol->image.img,
			&fractol->image.bpp, &fractol->image.line_size,
			&fractol->image.endian);
	y = 0;
	while (y < fractol->height)
	{
		x = 0;
		while (x < fractol->width)
		{
			process_fractal_pixel(fractol, x, y, fractol->type);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->image.img, 0,
		0);
}
