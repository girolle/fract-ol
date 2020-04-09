/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 19:21:55 by rczarfun          #+#    #+#             */
/*   Updated: 2020/03/29 15:59:07 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	exit_func(t_fractol *f)
{
	free(f->mlx);
	free(f->window);
	free(f->image);
	free(f->img_data);
	free(f);
	exit(1);
}

int		usage(int ac, char **av, t_fractol *f)
{
	int	a;

	if (ac != 2)
	{
		ft_putstr("Usage: ./fractol [parameter]");
		return (0);
	}
	a = ft_atoi(av[1]);
	if ((int)ft_strlen(av[1]) == 1 && (a >= 1 && a <= 8))
	{
		f->type = a;
		return (1);
	}
	ft_putstr("Usage:\t./fractol 1 (for Mandelbrot set)");
	ft_putstr("\n\t./fractol 2 (for Julia set)");
	ft_putstr("\n\t./fractol 3..8 (for other sets)");
	return (0);
}

void	fractol_init(t_fractol *f, t_img img)
{
	f->mlx = mlx_init();
	f->w_size = SCALE * 4;
	f->window = mlx_new_window(f->mlx, f->w_size, f->w_size, "FRACT'OL");
	f->image = mlx_new_image(f->mlx, f->w_size, f->w_size);
	f->img_data = mlx_get_data_addr(f->image, \
		&(img.bpp), &(img.size_line), &(img.endian));
	f->max_iter = MAX_ITER;
	f->radius = 2.;
	f->m_hook = 1;
	f->shift = c_init(f->w_size / 2, f->w_size / 2);
	f->scale = SCALE;
	f->color = 29;
}

int		main(int argc, char **argv)
{
	t_fractol	*f;
	t_img		img;

	img.bpp = 32;
	img.size_line = 16 * SCALE;
	img.endian = 0;
	if (!(f = (t_fractol *)ft_memalloc(sizeof(t_fractol))))
		return (0);
	if (usage(argc, argv, f))
	{
		fractol_init(f, img);
		draw_fractol(f);
		set_hooks(f);
		mlx_loop(f->mlx);
	}
	return (0);
}
