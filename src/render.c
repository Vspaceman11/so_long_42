/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:24:49 by vpushkar          #+#    #+#             */
/*   Updated: 2025/05/23 17:03:13 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		printf("%s", game->map[i]);
		free(game->map[i]);
		i++;
	}
	free(game->map);
}
