/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:38:54 by vpushkar          #+#    #+#             */
/*   Updated: 2025/05/16 16:51:36 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "libft_extended/inc/libft.h"
# include "libft_extended/inc/ft_printf.h"
# include "libft_extended/inc/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>

int	ft_is_valid_rectangular(char **map);
int	ft_is_surrended_by_walls(char **map);
int	ft_has_valid_characters(char **map);
int	ft_has_required_elements(char **map);

#endif
