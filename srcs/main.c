/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:56:53 by nkannan           #+#    #+#             */
/*   Updated: 2024/04/21 20:34:02 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_fractol(t_fractol *fractol)
{
	fractol->width = WIDTH;
	fractol->height = HEIGHT;
	fractol->zoom = 1.0;
	fractol->offset_x = 0;
	fractol->offset_y = 0;
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		malloc_error();
	fractol->win = mlx_new_window(fractol->mlx, fractol->width, fractol->height,
			"Fractol");
	if (!fractol->win)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		malloc_error();
	}
}

void	setup_image(t_fractol *fractol)
{
	fractol->image.img = mlx_new_image(fractol->mlx, fractol->width,
			fractol->height);
	if (!fractol->image.img)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		malloc_error();
	}
	fractol->image.pixels = mlx_get_data_addr(fractol->image.img,
			&fractol->image.bpp, &fractol->image.line_size,
			&fractol->image.endian);
	draw_fractol(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->image.img, 0,
		0);
}

int	main(int argc, char *argv[])
{
	t_fractol	fractol;

	validates_args(argc, argv);
	fractol.type = argv[1];
	if (argc == 4)
	{
		fractol.julia_re = ft_atof(argv[2]);
		fractol.julia_im = ft_atof(argv[3]);
	}
	init_fractol(&fractol);
	setup_image(&fractol);
	init_hooks(&fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
