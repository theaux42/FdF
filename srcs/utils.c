/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:57:08 by tbabou            #+#    #+#             */
/*   Updated: 2024/07/22 01:23:01 by tbabou           ###   ########.fr       */
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
	exit(0);
}

int	choose_color(int z)
{
	if (z == 0)
		return (0xFFFFFF);
	else if (z > 0)
		return (0xFF0000);
	else
		return (0x0000FF);
}

int map_width(t_fdf *fdf)
{
    char *first_line;
    char **split;
    int i;
    first_line = fdf->map[0];
    split = ft_split(first_line, ' ');
    i = 0;
    while (split[i] != NULL)
        i++;
    ft_freesplit(split);
    ft_printf("fdf->map[0]: %d\n", i);
    ft_printf("fdf->map[0]: %d\n", i * (10 + fdf->scale));
    return (i * (10 + fdf->scale));
    
}

int map_height(t_fdf *fdf)
{
    int i;
    i = 0;
    while (fdf->map[i] != NULL)
        i++;
    ft_printf("fdf->map[0]: %d\n", i * (10 + fdf->scale));
    return (i * (10 + fdf->scale));
}


void	init_everything(char *map, t_fdf *fdf)
{
	fdf->win_width = 1200;
	fdf->win_height = 800;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_width, fdf->win_height, "fdf");
	fdf->map = init_parsing(map);
	fdf->x = 0;
	fdf->y = 0;
    fdf->map_width = 18;
    fdf->map_height = 10;
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
