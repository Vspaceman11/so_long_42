/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:47:46 by vpushkar          #+#    #+#             */
/*   Updated: 2025/05/23 17:39:07 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// ========== INCLUDES ==========
# include "MLX42/MLX42.h"
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

// ========== DEFINES ==========
# define TILE_SIZE 16
# define WIDTH 1024
# define HEIGHT 1024

// ========== STRUCTURES ==========

typedef struct s_textures
{
	mlx_texture_t	*player_texture;
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*floor_texture;
	mlx_texture_t	*collectible_texture;
	mlx_texture_t	*exit_texture;
}	t_textures;

typedef struct s_img
{
	mlx_image_t		*player_img;
	mlx_image_t		*wall_img;
	mlx_image_t		*floor_img;
	mlx_image_t		*collectible_img;
	mlx_image_t		*exit_img;
}	t_img;

typedef struct s_game
{
	mlx_t			*mlx;
	t_img			images;
	char			**map;
	int				map_row;
	int				map_col;
	int				player_x;
	int				player_y;
}	t_game;

// ========== FUNCTION PROTOTYPES ==========

// map.c
char	**ft_read_map(const char *file);
char	*ft_read_line_map(int fd);
int		ft_line_counter(const char *file);
int		ft_validate_map(char **map);
int		ft_is_valid_rectangular(char **map);
int		ft_is_surrended_by_walls(char **map);
int		ft_has_valid_characters(char **map);
int		ft_has_required_elements(char **map);
void	ft_map_size(t_game *game);



// flood_fill.c
void	ft_flood_fill(char **map, int row, int col);
void	ft_free_map(char **map);
char	**ft_copy_map(char **map);
int		ft_is_path_valid(char **map);
int		ft_check_remaining(char **map);
int		ft_find_player(char **map, int *x, int *y);

// game.c
void	ft_game_init(t_game *game);
// void	ft_load_textures(t_game *game);
// void	ft_hook_controls(t_game *game);

// render.c
void	ft_render_map(t_game *game);

// utils.c (если есть)
// void	print_error(const char *msg);
// void	free_split(char **split);

#endif
