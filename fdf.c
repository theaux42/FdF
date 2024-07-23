/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:02:25 by tbabou            #+#    #+#             */
/*   Updated: 2024/07/22 14:40:20 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void change_z_value(t_fdf *fdf, int key)
{
	if (key == PAGE_UP)
		fdf->z += 2;
	else if (key == PAGE_DOWN)
		fdf->z -= 2;
}

int	on_key_press(int key, t_fdf *fdf)
{
	ft_printf("key: %d\n", key);
	if (key == ESC)
		free_mlx(fdf);
	else if (key == LEFT || key == RIGHT || key == UP || key == DOWN)
		if (fdf->is_iso)
			iso_movement(fdf, key);
		else
			para_movement(fdf, key);
	else if (key == ZOOM || key == DEZOOM)
		zoom_handler(fdf, key);
	else if (key == W || key == A || key == S || key == D)
		edit_start_value(fdf, key);
	else if (key == SPACE)
		switch_projection(fdf);
	else if (key == PAGE_UP || key == PAGE_DOWN)
		change_z_value(fdf, key);
	redraw(fdf);
	return (0);
}

int	*projection_handler(t_fdf *fdf, int x, int y, int z)
{
	int	*coord;
	coord = malloc(sizeof(int) * 2);
	if (fdf->is_iso)
	{		
		coord[0] = (x - y) * cos(0.523599);
		coord[1] = -z + (x + y) * sin(0.523599);
	}
	else
	{
		coord[0] = x;
		coord[1] = y;
	}
	return (coord);
}

int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
		return (ft_printf("Usage: %s <map>\n", av[0]), 1);
	init_everything(av[1], &fdf);
	mlx_key_hook(fdf.win, on_key_press, &fdf);
	// mlx_hook(fdf.win, 17, 1L << 17, free_mlx, &fdf);
	redraw(&fdf);
	// mlx_string_put(fdf.mlx, fdf.win,10, 10, 0xFFFFFF, "Press SPACE to switch projection");
	mlx_loop(fdf.mlx);
}
