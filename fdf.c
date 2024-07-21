/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:02:25 by tbabou            #+#    #+#             */
/*   Updated: 2024/07/21 18:08:42 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	on_key_press(int key, t_fdf *fdf)
{
	ft_printf("Key pressed: %d\n", key);
	if (key == ESC)
		free_mlx(fdf);
	else if (key == LEFT || key == RIGHT || key == UP || key == DOWN)
		movement_handler(fdf, key);
	else if (key == ZOOM || key == DEZOOM)
		zoom_handler(fdf, key);
	redraw(fdf);
	return (0);
}

int	*isometric_projection(int x, int y, int z)
{
	int	*coord;

	coord = malloc(sizeof(int) * 2);
	coord[0] = (x - y) * cos(0.523599);
	coord[1] = -z + (x + y) * sin(0.523599);
	return (coord);
}

int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
		return (ft_printf("Usage: %s <map>\n", av[0]), 1);
	init_everything("maps/42.fdf", &fdf);
	mlx_key_hook(fdf.win, on_key_press, &fdf);
	// mlx_hook(fdf.win, 17, 1L << 17, free_mlx, &fdf);
	draw_point(&fdf);
	mlx_loop(fdf.mlx);
}
