/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 19:21:55 by rczarfun          #+#    #+#             */
/*   Updated: 2020/03/29 00:23:11 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scale_func(t_fractol *f, int key, int x, int y)
{
	if (key == 126 || key == 5)
		if (f->max_iter <= 100)
		{
			f->scale *= 1.3;
			f->shift.re = (f->shift.re - x) * 1.3 + x;
			f->shift.im = (f->shift.im - y) * 1.3 + y;
			f->max_iter += 1;
		}
	if (key == 125 || key == 4)
		if (f->max_iter > 2)
		{
			f->scale /= 1.3;
			f->shift.re = (f->shift.re - x) / 1.3 + x;
			f->shift.im = (f->shift.im - y) / 1.3 + y;
			f->max_iter -= 1;
		}
}

int		key_hook(int key, t_fractol *f)
{
	if (key == 0)
		f->shift.re += 100;
	if (key == 2)
		f->shift.re -= 100;
	if (key == 13)
		f->shift.im += 100;
	if (key == 1)
		f->shift.im -= 100;
	if (key == 15)
	{
		f->max_iter = MAX_ITER;
		f->scale = SCALE;
		f->shift = c_init(f->w_size / 2, f->w_size / 2);
	}
	if (key == 125 || key == 126)
		scale_func(f, key, f->w_size / 2, f->w_size / 2);
	if (key >= 18 && key <= 29)
		f->color = key;
	if (key == 53)
		exit_func(f);
	draw_fractol(f);
	return (0);
}

int		mouse_press_hook(int button, int x, int y, t_fractol *f)
{
	if (button == 4 || button == 5)
		scale_func(f, button, x, y);
	if (button == 1)
		f->m_hook = !(f->m_hook);
	draw_fractol(f);
	x++;
	y++;
	return (0);
}

int		motion_hook(int x, int y, t_fractol *f)
{
	if (f->m_hook)
	{
		f->point.re = (double)(f->shift.re - f->w_size + x) / f->scale;
		f->point.im = (double)(f->shift.im - f->w_size + y) / f->scale;
		draw_fractol(f);
	}
	return (0);
}

void	set_hooks(t_fractol *f)
{
	mlx_do_key_autorepeatoff(f->mlx);
	mlx_hook(f->window, 2, 0, key_hook, f);
	mlx_hook(f->window, 4, 0, mouse_press_hook, f);
	mlx_hook(f->window, 6, 0, motion_hook, f);
}
