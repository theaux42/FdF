/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:57:08 by tbabou            #+#    #+#             */
/*   Updated: 2024/07/23 15:21:30 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	free_mlx(t_fdf *fdf)
{
	//draw a 
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	if (fdf->map != NULL)
		free_map(fdf->map);
	exit(0);
}

void	init_everything(char *map, t_fdf *fdf)
{
	fdf->map = init_parsing(map);
	fdf->map_size = map_checker(fdf->map);
	if (fdf->map == NULL || fdf->map_size == NULL)
		exit(1);
	fdf->win_width = 1200;
	fdf->win_height = 800;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_width, fdf->win_height, "fdf");
	fdf->x = 0;
	fdf->y = 0;
	fdf->z = 0;
	fdf->is_iso = 1;
	fdf->start_x = 660;
	fdf->start_y = 0;
    ft_printf("fdf->start_x: %d\n", fdf->start_x);
    ft_printf("fdf->start_y: %d\n", fdf->start_y);
	fdf->scale = 0;
	if (fdf->map == NULL)
		free_mlx(fdf);
	ft_printf("Ready to go!\n");
}
