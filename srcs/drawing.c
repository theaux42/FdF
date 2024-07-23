/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:38:34 by tbabou            #+#    #+#             */
/*   Updated: 2024/07/23 15:35:13 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_horizontal(t_fdf *fdf, char **split, int y1);
void	draw_vertical(t_fdf *fdf);

void	draw_x_array(t_fdf *fdf, char **split, int y1)
{
	int	*coord;
	int	j;
	int	x1;
	int	z1;

	z1 = fdf->z + fdf->scale + BASE_SCALE;
	j = 0;
	x1 = 0;
	while (split[j] != NULL)
	{
		coord = projection_handler(fdf, fdf->start_x + x1 + fdf->x, fdf->start_y
				+ y1 + fdf->y, ft_atoi(split[j]) * z1);
		mlx_pixel_put(fdf->mlx, fdf->win, coord[0], coord[1],
			0x00FFFFFF);
		free(coord);
		x1 += BASE_SCALE + fdf->scale;
		j++;
	}
}

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
		draw_horizontal(fdf, split, y1);
		draw_x_array(fdf, split, y1);
		ft_freesplit(split);
		i++;
	}
	draw_vertical(fdf);
	return (0);
}

void	redraw(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	// draw_line_array(fdf, fdf->map[3]);
	draw_point(fdf);
}

int	*calculate_coords(t_fdf *fdf, int x, int y, char z)
{
	int	*coords;

	coords = projection_handler(fdf, fdf->start_x + x + fdf->x + fdf->scale
			+ BASE_SCALE, fdf->start_y + y + fdf->y + fdf->scale + BASE_SCALE, z * fdf->z
			+ fdf->scale + BASE_SCALE);
	return (coords);
}

void	draw_vertical(t_fdf *fdf)
{
	int		vertical;
	int		horizontal;
	char	**split;
	int		*coords1;
	int		*coords2;
	int		x1;
	int		z1;
	int		weird;

	weird = BASE_SCALE + fdf->scale;
	x1 = 0;
	z1 = fdf->z + fdf->scale + BASE_SCALE;
	for (horizontal = 0; horizontal <= fdf->map_size[0]; horizontal++)
	{
		vertical = 0;
		while (vertical <= fdf->map_size[1] - 2)
		{
			split = ft_split(fdf->map[vertical], ' ');
			coords1 = projection_handler(fdf, fdf->start_x + x1 + fdf->x,
					fdf->start_y + vertical * (BASE_SCALE + fdf->scale) + weird
					+ fdf->y, ft_atoi(split[horizontal]) * z1);
			ft_freesplit(split);
			split = ft_split(fdf->map[vertical + 1], ' ');
			coords2 = projection_handler(fdf, fdf->start_x + x1 + fdf->x,
					fdf->start_y + weird + (vertical + 1) * (BASE_SCALE + fdf->scale)
					+ fdf->y, ft_atoi(split[horizontal]) * z1);
			plotLine(fdf, coords1[0], coords1[1], coords2[0], coords2[1]);
			ft_freesplit(split);
			free(coords1);
			free(coords2);
			vertical++;
		}
		x1 += BASE_SCALE + fdf->scale;
	}
}

void	draw_horizontal(t_fdf *fdf, char **split, int y1)
{
	int	i;
	int	x1;
	int	*coords1;
	int	*coords2;
	int	z1;

	z1 = fdf->z + fdf->scale + BASE_SCALE;
	i = 0;
	x1 = 0;
	while (split[i + 1] != NULL)
	{
		coords1 = projection_handler(fdf, fdf->start_x + x1 + fdf->x,
				fdf->start_y + y1 + fdf->y, ft_atoi(split[i]) * z1);
		coords2 = projection_handler(fdf, fdf->start_x + x1 + fdf->x + BASE_SCALE
				+ fdf->scale, fdf->start_y + y1 + fdf->y, ft_atoi(split[i + 1])
				* z1);
		plotLine(fdf, coords1[0], coords1[1], coords2[0], coords2[1]);
		free(coords1);
		free(coords2);
		x1 += BASE_SCALE + fdf->scale;
		i++;
	}
}
