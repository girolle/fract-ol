/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 18:51:37 by rczarfun          #+#    #+#             */
/*   Updated: 2020/03/29 19:41:41 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"
# define MAX_ITER 40
# define SCALE 150

typedef struct	s_complex
{
	int		re;
	int		im;
}				t_complex;

typedef struct	s_d_complex
{
	double		re;
	double		im;
}				t_d_complex;

typedef struct	s_dot
{
	t_complex	cord;
	char		red;
	char		green;
	char		blue;
}				t_dot;

typedef struct	s_fractol
{
	int			type;
	int			scale;
	t_complex	shift;
	int			max_iter;
	double		radius;
	void		*mlx;
	void		*window;
	void		*image;
	char		*img_data;
	int			w_size;
	t_d_complex	point;
	int			m_hook;
	int			color;
}				t_fractol;

typedef struct	s_img
{
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

t_complex		c_init(int re, int im);
t_d_complex		cd_init(double re, double im);
t_d_complex		cd_plus(t_d_complex a, t_d_complex b);
t_d_complex		cd_squared(t_d_complex c);
double			cd_sq_radius(t_d_complex c);
void			scale_func(t_fractol *f, int key, int x, int y);
int				key_hook(int key, t_fractol *f);
int				mouse_press_hook(int button, int x, int y, t_fractol *f);
int				motion_hook(int x, int y, t_fractol *f);
void			set_hooks(t_fractol *f);
void			get_color(int iter, int max_iter, t_dot *d, t_fractol *f);
void			draw_fractol(t_fractol *f);
t_dot			m_dot(t_complex c, t_fractol *f);
t_dot			j_dot(t_complex c, t_fractol *f);
t_dot			n3_dot(t_complex c, t_fractol *f);
t_dot			n4_dot(t_complex c, t_fractol *f);
t_dot			n5_dot(t_complex c, t_fractol *f);
t_dot			n6_dot(t_complex c, t_fractol *f);
int				usage(int ac, char **av, t_fractol *f);
t_dot			find_dot(t_complex c, t_fractol *f);
void			exit_func(t_fractol *f);
void			fractol_init(t_fractol *f, t_img img);
#endif
