/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:57:08 by tbabou            #+#    #+#             */
/*   Updated: 2024/07/28 02:10:34 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	free_mlx(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	if (fdf->map != NULL)
		free_map(fdf->map);
	if (fdf->map_size != NULL)
		free(fdf->map_size);
	exit(0);
}

void	set_values(t_fdf *fdf)
{
	fdf->win_width = 1200;
	fdf->win_height = 800;
	fdf->x = 0;
	fdf->y = 0;
	fdf->z = 0;
	fdf->is_iso = 1;
	fdf->start_x = 660;
	fdf->start_y = 0;
	fdf->scale = 0;
}

void	init_everything(char *map, t_fdf *fdf)
{
	set_values(fdf);
	fdf->map = init_parsing(map);
	fdf->map_size = map_checker(fdf->map);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_width, fdf->win_height, "fdf");
	if (fdf->map == NULL || fdf->map_size == NULL)
	{
		ft_printf("%s[ERROR] The map in invalid.\n%s", RED, RESET);
		free_mlx(fdf);
	}
}

void	choose_movement(t_fdf *fdf, int direction)
{
	if (fdf->is_iso)
		iso_movement(fdf, direction);
	else
		para_movement(fdf, direction);
}

void	malloc_exit(t_fdf *fdf)
{
	ft_printf("%s     __\n  _ / /\n (_) | \n", RED);
	ft_printf("   | | \n  _| | \n (_) | \n    \\_\\ \n%s", RESET);
	ft_printf("%s[ERROR] At some point a malloc failed.\n%s", RED, RESET);
	free_mlx(fdf);
}
