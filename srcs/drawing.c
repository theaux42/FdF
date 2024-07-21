/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:38:34 by tbabou            #+#    #+#             */
/*   Updated: 2024/07/21 18:10:36 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	draw_point(t_fdf *fdf)
{
	int		*coord;
	int		i;
	int		x;
	int		y;
	int		x1;
	int		y1;
	char	**split;
	int		j;

	i = 0;
	x = 300;
	y = 150;
	x1 = 0;
	y1 = 0;
	while (fdf->map[i] != NULL)
	{
		y1 += 10;
		split = ft_split(fdf->map[i], ' ');
		j = 0;
		while (split[j] != NULL)
		{
			coord = isometric_projection(x + x1 + fdf->x, y + y1 + fdf->y,
					ft_atoi(split[j + fdf->z]));
			mlx_pixel_put(fdf->mlx, fdf->win, coord[0], coord[1],
				choose_color(ft_atoi(split[j])));
			free(coord);
			x1 += 10;
			j++;
		}
		x1 = 0;
		j = 0;
		while (split[j] != NULL)
		{
			free(split[j]);
			j++;
		}
		free(split);
		i++;
	}
	return (0);
}

void	redraw(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_point(fdf);
}