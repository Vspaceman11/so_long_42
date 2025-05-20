/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:37:38 by vpushkar          #+#    #+#             */
/*   Updated: 2025/05/20 16:50:09 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOD_FILL_H
# define FLOOD_FILL_H

# include "libft_extended/inc/libft.h"
# include "libft_extended/inc/ft_printf.h"
# include "libft_extended/inc/get_next_line.h"
# include "map.h"
# include <fcntl.h>
# include <stdio.h>

char	**ft_copy_map(char **map);
void	ft_free_map(char **map);
void	ft_flood_fill(char **map, int x, int y);
#endif
