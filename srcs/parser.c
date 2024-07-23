/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:05:32 by tbabou            #+#    #+#             */
/*   Updated: 2024/07/23 15:11:31 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_arr_length(char *line)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i] != NULL)
		i++;
	ft_freesplit(split);
	return (i - 1);
}

char	**init_parsing(char *file_name)
{
	char	**parsed_map;
	int		fd;
	int		i;
	char	*current_line;

	i = 0;
	fd = open(file_name, O_RDONLY);
	current_line = get_next_line(fd);
	while (current_line != NULL && current_line[0] != '\n')
	{
		if (i == 0)
		{
			parsed_map = malloc(sizeof(char *) * (get_arr_length(current_line)
						+ 1));
			parsed_map[get_arr_length(current_line)] = NULL;
		}
		parsed_map[i] = ft_strdup(current_line);
		free(current_line);
		current_line = get_next_line(fd);
		i++;
	}
	free(current_line);
	return (parsed_map);
}

int	*map_checker(char **map)
{
	int	*map_size;
	int	first_line;
	int	current_line;
	int	y;

	map_size = malloc(sizeof(int) * 2);
	current_line = 0;
	y = 0;
	first_line = get_arr_length(map[y]);
	while (map[y] != NULL)
	{
		current_line = get_arr_length(map[y]);
		if (current_line != first_line
			&& current_line != 0)
			return (NULL);
		y++;
	}
	map_size[0] = first_line;
	map_size[1] = y;
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
