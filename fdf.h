/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:02:43 by tbabou            #+#    #+#             */
/*   Updated: 2024/07/21 18:08:52 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <stdio.h>
# include <math.h>

// Keys
# define ESC 65307

# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364

# define ZOOM 65365
# define DEZOOM 65366

typedef struct s_point
{
    int value;
}	t_point;

typedef struct s_fdf
{
    char     **map;
    void	*mlx;
    void	*win;
    int		width;
    int		height;
    int     scale;
	int		start_x;
	int		start_y;
    int     x;
    int     y;
    int     z;
    
}	t_fdf;


int	get_arr_length(char *line);
int	draw_point(t_fdf *fdf);
int	*isometric_projection(int x, int y, int z);
int choose_color(int z);
char **init_parsing(char *file_name);
int choose_color(int z);
void init_everything(char *map, t_fdf *fdf);
void movement_handler(t_fdf *fdf, int direction);
void zoom_handler(t_fdf *fdf, int direction);
void free_map(char **map);
void free_mlx(t_fdf *fdf);
void redraw(t_fdf *fdf);

#endif
