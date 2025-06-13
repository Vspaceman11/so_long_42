/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:47:46 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/13 15:57:57 by vpushkar         ###   ########.fr       */
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
# include <stdlib.h>

// ========== DEFINES ==========
# define TILE_SIZE 64

// ========== STRUCTURES ==========

typedef struct s_textures
{
	mlx_texture_t	*player_tx;
	mlx_texture_t	*wall_tx;
	mlx_texture_t	*floor_tx;
	mlx_texture_t	*coll_tx;
	mlx_texture_t	*exit_tx;
}	t_textures;

typedef struct s_img
{
	mlx_image_t		*player_img;
	mlx_image_t		*wall_img;
	mlx_image_t		*floor_img;
	mlx_image_t		*coll_img;
	mlx_image_t		*exit_img;
}	t_img;

typedef struct s_game
{
	mlx_t			*mlx;
	t_img			images;
	t_textures		textures;
	char			**map;
	int				map_row;
	int				map_col;
	int				player_x;
	int				player_y;
	int				player_moves;
	int				player_inst_idx;
	int				col_remaining;
	int				frame_count;
	int				input_cooldown;
}	t_game;

// ========== FUNCTION PROTOTYPES ==========

// map.c
char	**ft_read_map(const char *file);
char	*ft_read_line_map(int fd);
int		ft_line_counter(const char *file);
int		ft_validate_map(char **map);
void	ft_map_size(t_game *game);

// map_utils.c
int		ft_is_valid_rectangular(char **map);
int		ft_is_surrended_by_walls(char **map);
int		ft_has_valid_characters(char **map);
int		ft_has_required_elements(char **map);
int		ft_count_collectibles(char **map);

// flood_fill.c
void	ft_flood_fill(char **map, int row, int col);
void	ft_free_map(char **map);
char	**ft_copy_map(char **map);

// floo_fill_utils.c
int		ft_is_path_valid(char **map);
int		ft_check_remaining(char **map);
int		ft_find_player(char **map, int *x, int *y);

// game.c
void	ft_game_init(t_game *game);
void	ft_game_map_init(t_game *game);
void	ft_textures_load(t_game *game);
void	ft_images_create(t_game *game);

// input.c
void	ft_handle_input(void *param);
void	ft_player_move(t_game *game, int dx, int dy);

// render.c
void	ft_place_basic_tiles(t_game *game, char tile, int x, int y);
void	ft_place_special_tiles(t_game *game, char tile, int x, int y);
void	ft_place_tile(t_game *game, char tile, int x, int y);
void	ft_map_render(t_game *game);
void	ft_free_and_exit(t_game *game);

// exit.c
void	ft_free_images(t_game *game);
void	ft_exit_game(t_game *game);
void	ft_hook_close(void *param);

#endif
