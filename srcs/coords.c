/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:21:59 by tbabou            #+#    #+#             */
/*   Updated: 2024/08/16 12:23:42 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_x(t_fdf *fdf, int x)
{
	return (fdf->start_x + fdf->x + (x * (BASE_SCALE + fdf->scale)));
}

int	get_y(t_fdf *fdf, int y, int scale)
{
	if (scale == 1)
		return (fdf->start_y + fdf->y + ((y + 1) * (BASE_SCALE + fdf->scale)));
	else
		return (fdf->start_y + y + fdf->y);
}

int	*projection(t_fdf *fdf, int x, int y, int z)
{
	int	*coord;

	coord = malloc(sizeof(int) * 2);
	if (!coord)
		malloc_exit(fdf);
	coord[0] = (x - y) * cos(0.523599);
	coord[1] = -z + (x + y) * sin(0.523599);
	return (coord);
}
