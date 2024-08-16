/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:05:32 by tbabou            #+#    #+#             */
/*   Updated: 2024/08/16 11:40:03 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_arr_length(char *line)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i] != NULL)
		i++;
	j = i;
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
	return (j - 1);
}

int	get_map_height(char *file_name)
{
	int		map_height;
	int		fd;
	char	*line;

	map_height = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL && line[0] != '\0' && line[0] != '\n')
	{
		map_height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (map_height + 1);
}

char	**init_parsing(t_fdf *fdf, char *file_name)
{
	char	**parsed_map;
	char	*line;
	int		fd;
	int		i;

	parsed_map = NULL;
	i = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL && line[0] != '\0' && line[0] != '\n')
	{
		if (i == 0)
			parsed_map = malloc(sizeof(char *) * (get_map_height(file_name)));
		parsed_map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	parsed_map[i] = NULL;
	fdf->map_height = i;
	free(line);
	close(fd);
	return (parsed_map);
}

int	*map_checker(t_fdf *fdf, char **map)
{
	int	*map_size;
	int	first_line;
	int	current_line;
	int	y;

	if (!map)
		return (NULL);
	map_size = malloc(sizeof(int) * 2);
	current_line = 0;
	first_line = get_arr_length(map[0]);
	y = 1;
	while (y < fdf->map_height)
	{
		if (map[y] == NULL || *map[y] == '\0')
			break ;
		current_line = get_arr_length(map[y]);
		if (current_line != first_line)
			return (NULL);
		y++;
	}
	map_size[0] = first_line;
	map_size[1] = fdf->map_height;
	return (map_size);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map != NULL)
	{
		while (map[i] != NULL)
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}
