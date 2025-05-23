/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:56:07 by vpushkar          #+#    #+#             */
/*   Updated: 2025/05/23 17:56:08 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_valid_rectangular(char **map)
{
	size_t	width;
	int		row;

	row = 1;
	width = ft_strlen(map[0]);
	while (map[row])
	{
		if (ft_strlen(map[row]) != width)
			return (0);
		row++;
	}
	return (1);
}

int	ft_is_surrended_by_walls(char **map)
{
	int	width;
	int	height;
	int	i;

	height = 0;
	while (map[height])
		height++;
	width = ft_strlen(map[0]);
	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_has_valid_characters(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != '\n'
				&& map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_has_required_elements(char **map)
{
	int	i;
	int	j;
	int	p_count;
	int	e_count;
	int	c_count;

	i = 0;
	j = 0;
	p_count = 0;
	e_count = 0;
	c_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			p_count += (map[i][j] == 'P');
			e_count += (map[i][j] == 'E');
			c_count += (map[i][j] == 'C');
			j++;
		}
		i++;
	}
	return (p_count == 1 && e_count == 1 && c_count >= 1);
}

void	ft_map_size(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			x++;
			game->map_row = x;
		}
		y++;
		game->map_col = y;
	}
}
