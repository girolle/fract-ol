/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 19:21:55 by rczarfun          #+#    #+#             */
/*   Updated: 2020/03/29 19:40:25 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_color(int iter, int max_iter, t_dot *d, t_fractol *f)
{
	double	t;
	double	c;

	c = (double)(f->color - 17) / 12.;
	t = (double)iter / (double)max_iter;
	d->red = (int)((9 * (1 - t) * pow(t, 3) + (1 - c) * 13) * 255) % 255;
	d->green = (int)((15 * pow((1 - t), 2) * pow(t, 2) + 9 * c) * 255) % 255;
	d->blue = (int)((8.5 * pow((1 - t), 3) * t + 7 * c) * 255) % 255;
}

void	new_pixel_put(t_fractol *f, t_dot d)
{
	int p;

	p = 4 * (d.cord.re + f->shift.re + \
		(d.cord.im + f->shift.im) * f->w_size);
	f->img_data[p] = d.red;
	f->img_data[p + 1] = d.green;
	f->img_data[p + 2] = d.blue;
}

void	draw_fractol(t_fractol *f)
{
	int			x;
	int			y;
	t_dot		d;

	x = -f->shift.re;
	while (x < (f->w_size - f->shift.re))
	{
		y = -f->shift.im;
		while (y < (f->w_size - f->shift.im))
		{
			if ((x + f->shift.re) >= 0 && (x + f->shift.re) < f->w_size \
				&& ((y + f->shift.im) >= 0 && (y + f->shift.im) < f->w_size))
			{
				d.cord = c_init(x, y);
				d = find_dot(d.cord, f);
				new_pixel_put(f, d);
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(f->mlx, f->window, f->image, 0, 0);
}

t_dot	find_dot(t_complex c, t_fractol *f)
{
	if (f->type == 1)
		return (m_dot(c, f));
	if (f->type == 2)
		return (j_dot(c, f));
	if (f->type == 3)
		return (n3_dot(c, f));
	if (f->type == 4)
		return (n4_dot(c, f));
	if (f->type == 5)
		return (n5_dot(c, f));
	return (n6_dot(c, f));
}
