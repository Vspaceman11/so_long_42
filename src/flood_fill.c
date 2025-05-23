/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:36:43 by vpushkar          #+#    #+#             */
/*   Updated: 2025/05/23 14:59:04 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_copy_map(char **map)
{
	char	**map_cpy;
	int		i;

	i = 0;
	while (map[i])
		i++;
	map_cpy = malloc(sizeof(char *) * (i + 1));
	if (!map_cpy)
		return (NULL);
	map_cpy[i] = NULL;
	i = 0;
	while (map[i])
	{
		map_cpy[i] = ft_strdup(map[i]);
		if (!map_cpy[i])
			{
				while (--i >= 0)
					free(map_cpy[i]);
				free(map_cpy);
				return (NULL);
			}
		i++;
	}
	return (map_cpy);
}
void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}


void	ft_flood_fill(char **map, int row, int col)
{
	if (map[row][col] == '1' || map[row][col] == 'F')
		return ;
	map[row][col] = 'F';

	ft_flood_fill(map, row + 1, col);
	ft_flood_fill(map, row - 1, col);
	ft_flood_fill(map, row, col + 1);
	ft_flood_fill(map, row, col - 1);
}
