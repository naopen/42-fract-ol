/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:39:32 by nkannan           #+#    #+#             */
/*   Updated: 2024/04/21 19:28:43 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800

# define MAX_ITER 100
# define ZOOM_IN 0.9
# define ZOOM_OUT 1.1
# define MOVE 0.1

# define MANDELBROT "mandelbrot"
# define JULIA "julia"

# define JULIA_RE -0.7
# define JULIA_IM 0.27015

# define ESC 53

# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000

typedef struct s_image
{
	void	*img;
	char	*pixels;
	int		bpp;
	int		line_size;
	int		endian;
}			t_image;
typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	t_image	image;
	int		width;
	int		height;
	double	zoom;
	double	offset_x;
	double	offset_y;
	char	*type;
}			t_fractol;

void	validates_args(int argc, char *argv[]);
void	malloc_error(void);

void	plot_pixel(t_fractol *fractol, int x, int y, int color);
void	draw_fractol(t_fractol *fractol);

void	init_hooks(t_fractol *fractol);

#endif