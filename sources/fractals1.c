/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 19:44:20 by rczarfun          #+#    #+#             */
/*   Updated: 2020/03/29 19:46:40 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_dot	n4_dot(t_complex c, t_fractol *f)
{
	t_dot		d;
	t_d_complex	z;
	t_d_complex	cd;
	int			i;

	d.cord = c;
	cd.re = (double)c.re / f->scale;
	cd.im = (double)c.im / f->scale;
	z.re = cd.re;
	z.im = cd.im;
	i = 1;
	while ((i < f->max_iter) && (cd_sq_radius(z) <= f->radius * f->radius))
	{
		z = cd_squared(z);
		z.re += f->point.im;
		z.im += cd.re;
		z.re -= fabs(f->point.re);
		i++;
	}
	get_color(i, f->max_iter, &d, f);
	return (d);
}

t_dot	n5_dot(t_complex c, t_fractol *f)
{
	t_dot		d;
	t_d_complex	z;
	t_d_complex	cd;
	int			i;

	d.cord = c;
	cd.re = (double)c.re / f->scale;
	cd.im = (double)c.im / f->scale;
	z.re = cd.re;
	z.im = cd.im;
	i = 1;
	while ((i < f->max_iter) && (cd_sq_radius(z) <= f->radius * f->radius))
	{
		z = cd_plus(cd_squared(z), cd_squared(f->point));
		z.re -= fabs(f->point.re);
		z.im -= fabs(f->point.im);
		i++;
	}
	get_color(i, f->max_iter, &d, f);
	return (d);
}

t_dot	n6_dot(t_complex c, t_fractol *f)
{
	t_dot		d;
	t_d_complex	z;
	t_d_complex	cd;
	int			i;

	d.cord = c;
	cd.re = (double)c.re / f->scale / 2;
	cd.im = (double)c.im / f->scale / 2;
	z.re = cd.re * 2;
	z.im = cd.im * 2;
	i = 1;
	while ((i < f->max_iter) && (cd_sq_radius(z) <= f->radius * f->radius))
	{
		z = cd_squared(z);
		z.im -= cd_sq_radius(cd) + 1;
		z.re -= cd_sq_radius(z);
		z.re += f->point.re - 1;
		z.im += fabs(f->point.im);
		i++;
	}
	get_color(i, f->max_iter, &d, f);
	return (d);
}
