/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:43:38 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/08 22:05:17 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_colours(t_fractal *f)
{
	f->colour_range = (f->colour_range + 1) % 9;
	reinit_img(f);
}

void	reinit_img(t_fractal *f)
{
	if (f->mlx && f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->palette)
		free(f->palette);
	if (f->buf)
		f->buf = NULL;
	init_img(f);
}

void	init_img(t_fractal *f)
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buf;

	f->palette = ft_calloc((MAX_ITERATIONS + 1), sizeof(int));
	if (!(f->palette))
		free_everything(f);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!(f->img))
		free_everything(f);
	f->buf = mlx_get_data_addr(f->img, &pixel_bits, &line_bytes, &endian);
}
