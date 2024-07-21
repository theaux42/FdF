/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:57:08 by tbabou            #+#    #+#             */
/*   Updated: 2024/07/21 18:07:04 by tbabou           ###   ########.fr       */
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

void	init_everything(char *map, t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 500, 500, "fdf");
	fdf->x = 0;
	fdf->y = 0;
	fdf->z = 0;
    fdf->start_x = 250;
    fdf->start_y = 250;
	fdf->scale = 0;
	fdf->map = init_parsing(map);
	if (fdf->map == NULL)
		free_mlx(fdf);
	ft_printf("Ready to go!\n");
}
