/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:31:30 by tbabou            #+#    #+#             */
/*   Updated: 2024/07/22 03:53:42 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	iso_movement(t_fdf *fdf, int direction)
{
	if (direction == LEFT)
	{
		fdf->x -= 10;
		fdf->y += 10;
	}
	else if (direction == RIGHT)
	{
		fdf->x += 10;
		fdf->y -= 10;
	}
	else if (direction == UP)
	{
		fdf->y -= 10;
		fdf->x -= 10;
	}
	else if (direction == DOWN)
	{
		fdf->y += 10;
		fdf->x += 10;
	}
}

void	para_movement(t_fdf *fdf, int direction)
{
	if (direction == LEFT)
		fdf->x -= 10;
	else if (direction == RIGHT)
		fdf->x += 10;
	else if (direction == UP)
		fdf->y -= 10;
	else if (direction == DOWN)
		fdf->y += 10;
}

void	edit_start_value(t_fdf *fdf, int direction)
{
	if (direction == W)
		fdf->start_y -= 10;
	else if (direction == A)
		fdf->start_x -= 10;
	else if (direction == S)
		fdf->start_y += 10;
	else if (direction == D)
		fdf->start_x += 10;
	ft_printf("fdf->start_x: %d\n", fdf->start_x);
	ft_printf("fdf->start_y: %d\n", fdf->start_y);
}

void	zoom_handler(t_fdf *fdf, int direction)
{
	ft_printf("fdf->scale: %d\n", fdf->scale);
	if (direction == ZOOM)
		fdf->scale += 1;
	else if (direction == DEZOOM)
		fdf->scale -= 1;
}

void	switch_projection(t_fdf *fdf)
{
	fdf->is_iso = !fdf->is_iso;
	if (fdf->is_iso)
	{
		ft_printf("Projection: ISO\n");
		fdf->start_x = 660;
		fdf->start_y = 0;
	}
	else
	{
		ft_printf("Projection: PARALLEL\n");
		fdf->start_x = 500;
		fdf->start_y = 350;
	}
}
