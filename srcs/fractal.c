/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:12:45 by nkannan           #+#    #+#             */
/*   Updated: 2024/04/19 19:55:39 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_fractal(t_fractol *fractol)
{
}

int	main(int argc, char *argv[])
{
	t_fractol	fractol;

	validates_args(argc, argv);
	fractol.width = WIDTH;
	fractol.height = HEIGHT;
	fractol.mlx = mlx_init();
	fractol.win = mlx_new_window(fractol.mlx, fractol.width, fractol.height,
			"Fractol");
	fractol.image.img = mlx_new_image(fractol.mlx, fractol.width,
			fractol.height);
	fractol.image.pixels = mlx_get_data_addr(fractol.image.img,
			&fractol.image.bpp, &fractol.image.line_size,
			&fractol.image.endian);
	draw_fractal(&fractol);
	mlx_put_image_to_window(fractol.mlx, fractol.win, fractol.image.img, 0, 0);
	mlx_loop(fractol.mlx);
	return (0);
}
