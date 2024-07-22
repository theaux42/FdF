/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:39:58 by tbabou            #+#    #+#             */
/*   Updated: 2024/07/21 21:32:54 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void update_coordinates(int e2, t_line *line)
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

void plotLine(t_fdf *fdf, int x0, int y0, int x1, int y1)
{
    t_line line;
    int e2;

    line.dx = abs(x1 - x0);
    line.sx = x0 < x1 ? 1 : -1;
    line.dy = -abs(y1 - y0);
    line.sy = y0 < y1 ? 1 : -1;
    line.err = line.dx + line.dy;
    line.x0 = x0;
    line.y0 = y0;

    while (1)
    {
        mlx_pixel_put(fdf->mlx, fdf->win, line.x0, line.y0, 0xFFFFFF);
        if (line.x0 == x1 && line.y0 == y1)
            break ;
        e2 = 2 * line.err;
        update_coordinates(e2, &line);
    }
}

void	draw_line(t_fdf *data, int x1, int y1, int x2, int y2)
{
	int dx, dy, p, x, y;
	dx = x2 - x1;
	dy = y2 - y1;
	x = x1;
	y = y1;
	p = 2 * dy - dx;
	while (x < x2)
	{
		if (p >= 0)
		{
			mlx_pixel_put(data->mlx, data->win, x, y, 0xFFFFFF);
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			mlx_pixel_put(data->mlx, data->win, x, y, 0xFFFFFF);
			p = p + 2 * dy;
		}
		x = x + 1;
	}
}
