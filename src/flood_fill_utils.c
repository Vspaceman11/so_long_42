/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:30:23 by vpushkar          #+#    #+#             */
/*   Updated: 2025/05/22 15:52:48 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

int	ft_find_player(char **map, int *x, int *y)
{
	int	row;
	int	col;

	row = 0;
	if (!map || !x || !y)
		return (0);
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == 'P')
			{
				*x = row;
				*y = col;
				return (1);
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	ft_check_remaining(char **map)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == 'C' || map[row][col] == 'E')
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

int ft_is_path_valid(char **map)
{
	char	**map_cpy;
	int		row;
	int		col;

	map_cpy = ft_copy_map(map);
	if (!map_cpy)
		return (0);
	ft_find_player(map_cpy, &row, &col);
	ft_flood_fill(map_cpy, row, col);
	if (!ft_check_remaining(map_cpy))
		return (ft_free_map(map_cpy), 0);
	ft_free_map(map_cpy);
	return (1);
}
