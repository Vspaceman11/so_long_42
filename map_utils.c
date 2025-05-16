/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:56:07 by vpushkar          #+#    #+#             */
/*   Updated: 2025/05/16 17:54:53 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	ft_is_valid_rectangular(char **map)
{
	int	width;
	int	row;

	row = 1;
	width = ft_strlen(map[0]);
	while (map[row])
	{
		if (ft_strlen(map[row] != width))
			return (0);
		row++;
	}
	return(1);
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

}
int	ft_has_required_elements(char **map)
{

}
