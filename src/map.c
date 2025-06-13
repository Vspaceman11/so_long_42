/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:38:03 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/13 14:49:38 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_validate_map(char **map)
{
	if (!map || !map[0])
		return (perror("Map does not exist "), 1);
	if (!ft_is_valid_rectangular(map))
		return (perror("Map is not rectangulat "), 1);
	if (!ft_is_surrended_by_walls(map))
		return (perror("Map is not surrended by walls "), 1);
	if (!ft_has_valid_characters(map))
		return (perror("Map has invalid characters "), 1);
	if (!ft_has_required_elements(map))
		return (perror("Map doesn't have required elements or more then 1"), 1);
	if (!ft_is_path_valid(map))
		return (perror("Cannot reach exit or collectibles "), 1);
	return (0);
}

int	ft_line_counter(const char *file)
{
	int		fd;
	int		lines_count;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	lines_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		lines_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines_count);
}

char	*ft_read_line_map(int fd)
{
	char	*line;
	char	*trimmed;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	trimmed = ft_strtrim(line, "\n");
	free(line);
	if (!trimmed)
		return (NULL);
	return (trimmed);
}

char	**ft_read_map(const char *file)
{
	int		fd;
	int		line_counts;
	int		row;
	char	**map;

	line_counts = ft_line_counter(file);
	if (line_counts < 1)
		return (NULL);
	map = malloc(sizeof(char *) * (line_counts + 1));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (free(map), NULL);
	row = 0;
	while (row < line_counts)
	{
		map[row] = ft_read_line_map(fd);
		if (!map[row])
			return (ft_free_map(map), perror("Trim failed"), NULL);
		row++;
	}
	map[row] = NULL;
	close(fd);
	return (map);
}

void	ft_map_size(t_game *game)
{
	int	row;

	row = 0;
	while (game->map[row])
		row++;
	game->map_row = row;
	game->map_col = ft_strlen(game->map[0]);
}
