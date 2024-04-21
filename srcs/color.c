/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:48:39 by nkannan           #+#    #+#             */
/*   Updated: 2024/04/21 21:41:48 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	set_rgb_values(t_color *color, double p, double q, double t)
{
	if (6 * t < 1)
	{
		color->r = (int)((p + (q - p) * 6 * t) * 255);
		color->g = (int)((p + (q - p) * 6 * t) * 255);
		color->b = (int)((p + (q - p) * 6 * t) * 255);
	}
	else if (2 * t < 1)
	{
		color->r = (int)(q * 255);
		color->g = (int)(q * 255);
		color->b = (int)(q * 255);
	}
	else if (3 * t < 2)
	{
		color->r = (int)((p + (q - p) * (0.666 - t) * 6) * 255);
		color->g = (int)((p + (q - p) * (0.666 - t) * 6) * 255);
		color->b = (int)((p + (q - p) * (0.666 - t) * 6) * 255);
	}
	else
	{
		color->r = (int)(p * 255);
		color->g = (int)(p * 255);
		color->b = (int)(p * 255);
	}
}

t_color	hsv_to_rgb(double h, double s, double v)
{
	t_color	color;
	double	p;
	double	q;
	double	t;
	int		i;

	h = fmod(h, 360);
	if (s == 0)
	{
		color.r = (int)(v * 255);
		color.g = (int)(v * 255);
		color.b = (int)(v * 255);
		return (color);
	}
	h /= 60;
	i = (int)floor(h);
	t = h - i;
	p = v * (1 - s);
	q = v * (1 - s * t);
	t = v * (1 - s * (1 - t));
	set_rgb_values(&color, p, q, t);
	return (color);
}

int	calculate_color(int iteration)
{
	int				hue;
	t_color			color_value;
	unsigned int	color;

	hue = iteration % 360;
	if (iteration < MAX_ITER)
		color_value = hsv_to_rgb(hue, 1, 1);
	else
		color_value = hsv_to_rgb(hue, 0, 0);
	color = (color_value.r << 16) | (color_value.g << 8) | color_value.b;
	return (color);
}
