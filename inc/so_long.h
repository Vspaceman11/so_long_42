/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:47:46 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/10 15:23:55 by vpushkar         ###   ########.fr       */
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
# define TOP 1 // 0001
# define RIGHT 2 // 0010
# define BOTTOM 4 // 0100
# define LEFT 8 // 1000


// ========== STRUCTURES ==========

typedef struct s_textures
{
	mlx_texture_t	*player_texture;
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*floor_texture;
	// mlx_texture_t	*floor_tx_c;
	// mlx_texture_t	*floor_tx_tl_w;
	// mlx_texture_t	*floor_tx_tl_f;
	// mlx_texture_t	*floor_tx_tr_w;
	// mlx_texture_t	*floor_tx_tr_f;
	// mlx_texture_t	*floor_tx_bl_w;
	// mlx_texture_t	*floor_tx_bl_f;
	// mlx_texture_t	*floor_tx_br_w;
	// mlx_texture_t	*floor_tx_br_f;
	// mlx_texture_t	*floor_tx_top;
	// mlx_texture_t	*floor_tx_b;
	// mlx_texture_t	*floor_tx_l;
	// mlx_texture_t	*floor_tx_r;
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
	t_textures		textures;
	char			**map;
	int				map_row;
	int				map_col;
	int				player_x;
	int				player_y;
	int				player_moves;
	int				player_instance_idx;
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
int		ft_is_path_valid(char **map);
int		ft_check_remaining(char **map);
int		ft_find_player(char **map, int *x, int *y);

// game.c
void	ft_game_init(t_game *game);
// void	ft_load_textures(t_game *game);
// void	ft_hook_controls(t_game *game);

// hooks.c
void	ft_handle_input(void *param);
void	ft_player_move(t_game *game, int dx, int dy);

// render.c
void			ft_render_map(t_game *game);
// void			init_textures(t_game *game);
// int				get_tile_mask(t_game *game, int row, int col);
// mlx_texture_t	*get_ground_texture(t_game *game, int mask);
// void			delete_tx(t_textures *tx);

// utils.c (если есть)
// void	print_error(const char *msg);
// void	free_split(char **split);

#endif
