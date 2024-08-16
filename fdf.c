/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:02:25 by tbabou            #+#    #+#             */
/*   Updated: 2024/08/16 15:28:59 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	on_key_press(int key, t_fdf *fdf)
{
	if (key == ESC)
		free_mlx(fdf);
	else if (key == LEFT || key == RIGHT || key == UP || key == DOWN)
		iso_movement(fdf, key);
	else if (key == ZOOM || key == DEZOOM)
		zoom_handler(fdf, key);
	else if (key == PAGE_UP || key == PAGE_DOWN)
		change_z_value(fdf, key);
	redraw(fdf);
	return (0);
}

void	redraw(t_fdf *fdf)
{
	draw_point(fdf);
}

int	free_mlx_wrapper(void *param)
{
	free_mlx((t_fdf *)param);
	return (0);
}

int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
		return (ft_printf("Usage: %s <map>\n", av[0]), 1);
	set_values(&fdf);
	init_everything(av[1], &fdf);
	mlx_hook(fdf.win, 17, 1L << 17, free_mlx_wrapper, &fdf);
	mlx_key_hook(fdf.win, on_key_press, &fdf);
	redraw(&fdf);
	mlx_loop(fdf.mlx);
}
