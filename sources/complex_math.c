/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 19:05:19 by rczarfun          #+#    #+#             */
/*   Updated: 2020/03/26 19:56:07 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	c_init(int re, int im)
{
	t_complex	c;

	c.re = re;
	c.im = im;
	return (c);
}

t_d_complex	cd_init(double re, double im)
{
	t_d_complex	c;

	c.re = re;
	c.im = im;
	return (c);
}

t_d_complex	cd_plus(t_d_complex a, t_d_complex b)
{
	t_d_complex	c;

	c.re = a.re + b.re;
	c.im = a.im + b.im;
	return (c);
}

t_d_complex	cd_squared(t_d_complex cd)
{
	t_d_complex	tmp;

	tmp = cd;
	cd.re = tmp.re * tmp.re - tmp.im * tmp.im;
	cd.im = 2 * tmp.re * tmp.im;
	return (cd);
}

double		cd_sq_radius(t_d_complex cd)
{
	double	r;

	r = cd.re * cd.re + cd.im * cd.im;
	return (r);
}
