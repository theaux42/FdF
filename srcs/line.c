/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:39:58 by tbabou            #+#    #+#             */
/*   Updated: 2024/07/26 13:46:18 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	update_coordinates(int e2, t_line *line)
{
	if (e2 >= line->dy)
	{
		line->err += line->dy;
		line->x0 += line->sx;
	}
	if (e2 <= line->dx)
	{
		line->err += line->dx;
		line->y0 += line->sy;
	}
}

void	drawline(t_fdf *fdf, int *start, int *end)
{
	t_line	line;
	int		e2;

	line.dx = abs(end[0] - start[0]);
	line.sx = 1;
	line.sy = 1;
	line.dy = -abs(end[1] - start[1]);
	if (start[0] > end[0])
		line.sx = -1;
	if (start[1] > end[1])
		line.sy = -1;
	line.err = line.dx + line.dy;
	line.x0 = start[0];
	line.y0 = start[1];
	while (1)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, line.x0, line.y0, 0xFFFFFF);
		if (line.x0 == end[0] && line.y0 == end[1])
			break ;
		e2 = 2 * line.err;
		update_coordinates(e2, &line);
	}
	free(start);
	free(end);
}
