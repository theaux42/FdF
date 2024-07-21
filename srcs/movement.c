/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:31:30 by tbabou            #+#    #+#             */
/*   Updated: 2024/07/21 17:46:48 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	movement_handler(t_fdf *fdf, int direction)
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

void	zoom_handler(t_fdf *fdf, int direction)
{
    ft_printf("fdf->scale: %d\n", fdf->scale);
	if (direction == ZOOM)
		fdf->scale += 10;
	else if (direction == DEZOOM)
		fdf->scale -= 10;
}
