/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:57:08 by tbabou            #+#    #+#             */
/*   Updated: 2024/08/16 15:52:44 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	free_mlx(t_fdf *fdf)
{
	if (fdf->mlx != NULL && fdf->win != NULL)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->img != NULL)
		mlx_destroy_image(fdf->mlx, fdf->img);
	if (fdf->mlx != NULL)
	{
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
	}
	if (fdf->map != NULL)
		free_map(fdf->map);
	if (fdf->map_size != NULL)
		free(fdf->map_size);
	exit(0);
}

void	free_splits(char ***splits, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_freesplit(splits[i]);
		i++;
	}
	free(splits);
}

void	malloc_exit(t_fdf *fdf)
{
	ft_printf("%s     __\n  _ / /\n (_) | \n", RED);
	ft_printf("   | | \n  _| | \n (_) | \n    \\_\\ \n%s", RESET);
	ft_printf("%s[ERROR] At some point a malloc failed.\n%s", RED, RESET);
	free_mlx(fdf);
}
