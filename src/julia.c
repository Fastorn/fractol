/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 15:00:43 by abara             #+#    #+#             */
/*   Updated: 2016/09/12 14:49:22 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	draw_julia_helpa(t_winfo *winfo, int x, int y)
{
	double	a;

	winfo->fractal.cr = (WIDTH / 2);
	winfo->fractal.cr = winfo->a / winfo->fractal.cr;
	a = d_abs(winfo->fractal.x1 - winfo->fractal.x2) / 2;
	winfo->fractal.cr *= a;
	winfo->fractal.ci = (HEIGHT / 2);
	winfo->fractal.ci = winfo->b / winfo->fractal.ci;
	a = d_abs(winfo->fractal.y1 - winfo->fractal.y2) / 2;
	winfo->fractal.ci *= a;
	winfo->fractal.zr = x / winfo->fractal.zoomx + winfo->fractal.x1;
	winfo->fractal.zi = y / winfo->fractal.zoomy + winfo->fractal.y1;
}

static void	draw_julia_helpb(t_winfo *winfo)
{
	double	tmp;

	tmp = winfo->fractal.zr;
	winfo->fractal.zr = (winfo->fractal.zr * winfo->fractal.zr -
	winfo->fractal.zi * winfo->fractal.zi + winfo->fractal.cr);
	winfo->fractal.zi = 2 * tmp * winfo->fractal.zi +
	winfo->fractal.ci;
}

void		color_julia(t_winfo *winfo, int i, int x, int y)
{
	if (i != winfo->fractal.max && winfo->color == 0)
		put_pixel(winfo, x, y, set_color(i * (255 /
		winfo->fractal.max), 0, 0));
	else if (i != winfo->fractal.max && winfo->color == 1)
		put_pixel(winfo, x, y, set_color(i * (255 /
		winfo->fractal.max), (1500 / winfo->fractal.max) * i, 0));
}

void		draw_julia(t_winfo *winfo)
{
	int		i;
	int		x;
	int		y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_julia_helpa(winfo, x, y);
			i = 0;
			while ((winfo->fractal.zr * winfo->fractal.zr + winfo->fractal.zi
			* winfo->fractal.zi) < 4 && i < winfo->fractal.max)
			{
				draw_julia_helpb(winfo);
				i++;
			}
			color_julia(winfo, i, x, y);
			x++;
		}
		y++;
	}
}
