/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:05:32 by tbabou            #+#    #+#             */
/*   Updated: 2024/07/21 18:37:26 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_arr_length(char *line)
{
	int	i;

	i = 1;
	while (*line)
	{
		if (*line == ' ')
			i++;
		line++;
	}
	return (i);
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
	while (current_line != NULL)
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
