/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:38:54 by vpushkar          #+#    #+#             */
/*   Updated: 2025/05/22 15:14:13 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>

int		ft_is_valid_rectangular(char **map);
int		ft_is_surrended_by_walls(char **map);
int		ft_has_valid_characters(char **map);
int		ft_has_required_elements(char **map);
int		ft_validate_map(char **map);
int		ft_line_counter(const char *file);
char	*ft_read_line_map(int fd);
char	**ft_read_map(const char *file);

#endif
