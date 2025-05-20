/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:30:23 by vpushkar          #+#    #+#             */
/*   Updated: 2025/05/20 16:50:41 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/flood_fill.h"

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
	char **map_cpy;

	map_cpy = ft_copy_map(map);
	if (!map_cpy)
		return (0);

}

int ft_is_path_valid(char **map)
{

}
