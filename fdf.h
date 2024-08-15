/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theaux <theaux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:02:43 by tbabou            #+#    #+#             */
/*   Updated: 2024/08/15 18:46:13 by theaux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

// Keys
# define ESC 65307

# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364

# define PAGE_UP 65365
# define PAGE_DOWN 65366

# define ZOOM 61
# define DEZOOM 45

# define SPACE 32

# define W 119
# define A 97
# define S 115
# define D 100

# define BASE_SCALE 15

typedef struct s_fdf
{
	char	**map;
	void	*mlx;
	void	*win;
	int		*map_size;
	int		win_width;
	int		win_height;
	int		scale;
	int		start_x;
	int		start_y;
	int		map_height;
	int		x;
	int		y;
	int		z;

}			t_fdf;

typedef struct s_line
{
	int		dx;
	int		dy;
	int		err;
	int		x0;
	int		y0;
	int		sx;
	int		sy;
}			t_line;

int			get_arr_length(char *line);
int			draw_point(t_fdf *fdf);
int			*projection(int x, int y, int z);
char		**init_parsing(t_fdf *fdf, char *file_name);
void		init_everything(char *map, t_fdf *fdf);
void		free_map(char **map);
void		free_mlx(t_fdf *fdf);
void		redraw(t_fdf *fdf);
int			*map_checker(t_fdf *fdf, char **map);
// IN TESTING
int			get_x(t_fdf *fdf, int x);
int			get_y(t_fdf *fdf, int y, int scale);

// DRAWING FUNCTIONS
void		draw_vertical(t_fdf *fdf);
void		draw_horizontal(t_fdf *fdf, char **split, int y1);

// MOVEMENT FUNCTIONS
void		iso_movement(t_fdf *fdf, int direction);
void		zoom_handler(t_fdf *fdf, int direction);
void		change_z_value(t_fdf *fdf, int key);

void		malloc_exit(t_fdf *fdf);

// NEED TO BE REMOVED
void		drawline(t_fdf *fdf, int *start, int *end);

#endif
