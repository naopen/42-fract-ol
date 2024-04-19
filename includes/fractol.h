/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:39:32 by nkannan           #+#    #+#             */
/*   Updated: 2024/04/19 16:03:18 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
	t_image	img;
	int		width;
	int		height;
}			t_fractol;

#endif