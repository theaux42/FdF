/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:38:34 by tbabou            #+#    #+#             */
/*   Updated: 2024/08/16 16:15:32 by tbabou           ###   ########.fr       */
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
	mlx_clear_window(fdf->mlx, fdf->win);
	if (fdf->img)
		mlx_destroy_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, fdf->win_width, fdf->win_height);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->ll, &fdf->endian);
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
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	return (0);
}

void	draw_vertical_line(t_fdf *fdf, char ***splits, int horizontal, int x1)
{
	int	vertical;
	int	*coords1;
	int	*coords2;
	int	z1;

	z1 = fdf->z + BASE_SCALE + fdf->scale;
	vertical = 0;
	while (vertical <= fdf->map_size[1] - 2)
	{
		coords1 = projection(fdf, get_x(fdf, x1), get_y(fdf, vertical, 1),
				ft_atoi(splits[vertical][horizontal]) * z1);
		coords2 = projection(fdf, get_x(fdf, x1), get_y(fdf, vertical + 1, 1),
				ft_atoi(splits[vertical + 1][horizontal]) * z1);
		drawline(fdf, coords1, coords2);
		vertical++;
	}
}

static char	***prepare_splits(t_fdf *fdf)
{
	int		i;
	char	***splits;

	splits = malloc(sizeof(char **) * fdf->map_size[1]);
	if (splits == NULL)
		malloc_exit(fdf);
	i = 0;
	while (i < fdf->map_size[1])
	{
		splits[i] = ft_split(fdf->map[i], ' ');
		if (splits[i] == NULL)
			malloc_exit(fdf);
		i++;
	}
	return (splits);
}

void	draw_vertical(t_fdf *fdf)
{
	int		horizontal;
	int		x1;
	char	***splits;

	splits = prepare_splits(fdf);
	x1 = 0;
	horizontal = 0;
	while (horizontal <= fdf->map_size[0])
	{
		draw_vertical_line(fdf, splits, horizontal, x1);
		horizontal++;
		x1++;
	}
	free_splits(splits, fdf->map_size[1]);
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
		coords1 = projection(fdf, get_x(fdf, i), get_y(fdf, y1, 0),
				ft_atoi(split[i]) * z1);
		coords2 = projection(fdf, get_x(fdf, i + 1), get_y(fdf, y1, 0),
				ft_atoi(split[i + 1]) * z1);
		drawline(fdf, coords1, coords2);
		i++;
	}
}
