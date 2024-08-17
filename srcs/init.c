/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:52:26 by tbabou            #+#    #+#             */
/*   Updated: 2024/08/17 14:57:03 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	set_values(t_fdf *fdf)
{
	fdf->map = NULL;
	fdf->map_size = NULL;
	fdf->mlx = NULL;
	fdf->win = NULL;
	fdf->img = NULL;
	fdf->win_width = 1200;
	fdf->win_height = 800;
	fdf->x = 0;
	fdf->y = 0;
	fdf->z = 0;
	fdf->map_height = 0;
	fdf->start_x = 660;
	fdf->start_y = 40;
	fdf->scale = 0;
}

void	init_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		malloc_exit(fdf);
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_width, fdf->win_height, "fdf");
	if (!fdf->win)
		malloc_exit(fdf);
	fdf->img = mlx_new_image(fdf->mlx, fdf->win_width, fdf->win_height);
	if (!fdf->img)
		malloc_exit(fdf);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->ll, &fdf->endian);
	if (!fdf->addr)
		malloc_exit(fdf);
}

void	init_everything(char *map, t_fdf *fdf)
{
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("%s[ERROR] The file %s does not exist.\n%s", RED, map, RESET);
		free_mlx(fdf);
	}
	close(fd);
	fdf->map = init_parsing(fdf, map);
	if (!fdf->map)
		malloc_exit(fdf);
	fdf->map_size = map_checker(fdf, fdf->map);
	if (!fdf->map_size || fdf->map_size[0] == 0 || fdf->map_size[1] == 0)
	{
		ft_printf("%s[ERROR] The map is invalid.\n%s", RED, RESET);
		free_mlx(fdf);
	}
	if (!fdf->map_size)
		malloc_exit(fdf);
	init_mlx(fdf);
}
