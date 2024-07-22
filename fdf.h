/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:02:43 by tbabou            #+#    #+#             */
/*   Updated: 2024/07/22 01:22:26 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

// Keys
# define ESC 65307

# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364

# define ZOOM 65365
# define DEZOOM 65366

# define SPACE 32

# define W 119
# define A 97
# define S 115
# define D 100

typedef struct s_fdf
{
    char     **map;
    void	*mlx;
    void	*win;
    int		win_width;
    int		win_height;
	int		map_width;
	int		map_height;
	int    	is_iso;
    int     scale;
	int		start_x;
	int		start_y;
    int     x;
    int     y;
    int     z;
    
}	t_fdf;

typedef struct s_line
{
    int dx;
    int dy;
    int err;
    int x0;
    int y0;
    int sx;
    int sy;
}              t_line;

int	get_arr_length(char *line);
int	draw_point(t_fdf *fdf);
int	*projection_handler(t_fdf *fdf, int x, int y, int z);
int choose_color(int z);
char **init_parsing(char *file_name);
int choose_color(int z);
void init_everything(char *map, t_fdf *fdf);
void draw_x_array(t_fdf *fdf, char **split, int y1);
void edit_start_value(t_fdf *fdf, int direction);
void iso_movement(t_fdf *fdf, int direction);
void para_movement(t_fdf *fdf, int direction);
void zoom_handler(t_fdf *fdf, int direction);
void switch_projection(t_fdf *fdf);
void free_map(char **map);
int map_width(t_fdf *fdf);
int map_height(t_fdf *fdf);
void free_mlx(t_fdf *fdf);
void redraw(t_fdf *fdf);
// void draw_point_and_lines(t_fdf *fdf);

// GARBAGE CODE
void draw_map_line(t_fdf *fdf);
void draw_line_array(t_fdf *fdf, char *line);

// NEED TO BE REMOVED
void plotLine(t_fdf *fdf, int x1, int y1, int x2, int y2);
void draw_line(t_fdf *data, int x1, int y1, int x2, int y2);

#endif
