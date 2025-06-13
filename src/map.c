/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:38:03 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/13 16:13:34 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Validates the structure and content of the map.
 *
 * This function performs a series of checks to ensure the map is valid:
 * - It exists and is not empty.
 * - It is rectangular (each row has the same length).
 * - It is surrounded by walls.
 * - It contains only allowed characters.
 * - It contains the required elements (1 player, ≥1 exit, ≥1 collectible).
 * - It has a valid path to all collectibles and to the exit.
 *
 * @param map The map as a NULL-terminated array of strings.
 * @return int 0 if the map is valid, 1 otherwise.
 */
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

/**
 * @brief Counts the number of lines in a file.
 *
 * Opens the given file and counts how many lines it contains by
 * repeatedly calling get_next_line and freeing the result.
 *
 * @param file Path to the file.
 * @return The number of lines in the file, or -1 if the file cannot be opened.
 */
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

/**
 * @brief Reads a line from the file and trims the newline character.
 *
 * This function uses get_next_line to read one line from the file.
 * It then trims the trailing newline character using ft_strtrim.
 * The original line is freed, and the trimmed result is returned.
 *
 * @param fd The file descriptor to read from.
 * @return A trimmed string without the newline character,
 * or NULL on failure or EOF.
 */
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

/**
 * @brief Reads the map from the given file and stores it as a string array.
 *
 * Each line of the file is read, trimmed of newline characters, and stored
 * in a dynamically allocated array. The final array is NULL-terminated.
 *
 * @param file Path to the map file.
 * @return A NULL-terminated array of strings representing the map,
 * or NULL on error.
 */
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

/**
 * @brief Calculates the dimensions of the
 * map and stores them in the game struct.
 *
 * This function counts the number of rows in the map and determines the number
 * of columns by measuring the length of the first row. The results are stored
 * in the game->map_row and game->map_col fields.
 *
 * @param game Pointer to the game structure containing the map.
 */
void	ft_map_size(t_game *game)
{
	int	row;

	row = 0;
	while (game->map[row])
		row++;
	game->map_row = row;
	game->map_col = ft_strlen(game->map[0]);
}
