/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:38:34 by tbabou            #+#    #+#             */
/*   Updated: 2024/08/14 16:41:54 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	draw_point(t_fdf *fdf)
{
	int		i;
	int		y1;
	char	**split;

	i = 0;
	y1 = 0;
	while (fdf->map[i] != NULL)
	{
		y1 += BASE_SCALE + fdf->scale;
		split = ft_split(fdf->map[i], ' ');
		if (split == NULL)
			malloc_exit(fdf);
		draw_horizontal(fdf, split, y1);
		ft_freesplit(split);
		split = NULL;
		i++;
	}
	draw_vertical(fdf);
	return (0);
}

void	draw_vertical_line(t_fdf *fdf, int horizontal, int x1, int z1)
{
	int		vertical;
	char	**split;
	int		*coords1;
	int		*coords2;

	vertical = 0;
	while (vertical <= fdf->map_size[1] - 2)
	{
		split = ft_split(fdf->map[vertical], ' ');
		if (split == NULL)
			free_mlx(fdf);
		coords1 = projection(get_x(fdf, x1), get_y(fdf, vertical, 1),
				ft_atoi(split[horizontal]) * z1);
		ft_freesplit(split);
		split = ft_split(fdf->map[vertical + 1], ' ');
		if (split == NULL)
			free_mlx(fdf);
		coords2 = projection(get_x(fdf, x1), get_y(fdf, vertical + 1, 1),
				ft_atoi(split[horizontal]) * z1);
		drawline(fdf, coords1, coords2);
		ft_freesplit(split);
		split = NULL;
		vertical++;
	}
}

void	draw_vertical(t_fdf *fdf)
{
	int	horizontal;
	int	x1;
	int	z1;

	x1 = 0;
	z1 = fdf->z + BASE_SCALE + fdf->scale;
	horizontal = 0;
	while (horizontal <= fdf->map_size[0])
	{
		draw_vertical_line(fdf, horizontal, x1, z1);
		horizontal++;
		x1++;
	}
}

void	redraw(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_point(fdf);
}

void	draw_horizontal(t_fdf *fdf, char **split, int y1)
{
	int	*coords1;
	int	*coords2;
	int	i;
	int	z1;

	z1 = fdf->z + BASE_SCALE + fdf->scale;
	i = 0;
	while (split[i + 1] != NULL)
	{
		coords1 = projection(get_x(fdf, i), get_y(fdf, y1, 0), ft_atoi(split[i])
				* z1);
		coords2 = projection(get_x(fdf, i + 1), get_y(fdf, y1, 0),
				ft_atoi(split[i + 1]) * z1);
		drawline(fdf, coords1, coords2);
		i++;
	}
}
