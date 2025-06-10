/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:52:55 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/10 14:33:08 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"

int	main(void)
{
	t_game	*game;
	char	**map;
	game = ft_calloc(1, sizeof(t_game));
	map = ft_read_map("maps/test.ber");
	if (!map)
	{
		fprintf(stderr, "Failed to read map.\n");
		return (1);
	}
	if (ft_validate_map(map))
	{
		return (1);
	}
	// ft_render_map(map);
	ft_game_init(game);
	return (0);
}
