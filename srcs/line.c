/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:39:58 by tbabou            #+#    #+#             */
/*   Updated: 2024/08/16 16:08:08 by tbabou           ###   ########.fr       */
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

void	my_pixel_put_img(t_fdf *fdf, int x, int y)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= fdf->win_width || y >= fdf->win_height)
		return ;
	dst = fdf->addr + (y * fdf->ll + x * (fdf->bpp / 8));
	*(unsigned int *)dst = 0xFFFFFF;
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
		my_pixel_put_img(fdf, line.x0, line.y0);
		if (line.x0 == end[0] && line.y0 == end[1])
			break ;
		e2 = 2 * line.err;
		update_coordinates(e2, &line);
	}
	free(start);
	free(end);
}
