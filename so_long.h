/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:50:25 by ede-cola          #+#    #+#             */
/*   Updated: 2024/02/28 15:58:46 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <sys/types.h>

typedef struct s_size
{
	int			height_len;
	int			line_len;
	int			screen_width;
	int			screen_height;
}				t_size;

typedef struct s_element
{
	int				x;
	int				y;
	int				c;
}					t_element;

typedef struct s_map
{
	int				width;
	int				height;
	int				collectible;
	int				nb_move;
	char			**map_tab;
}					t_map;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				endian;
	int				bpp;
	int				line_len;
	int				width;
	int				height;
}					t_img;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	t_img			*img[7];
	t_map			*map;
	t_element		*vilain;
	t_element		*exit;
	t_element		*player;
}					t_mlx;

int					ft_check_one_extension(char *map);
void				ft_error_and_free(char *line, int fd, int flag);
void				ft_map_flood_error(char **map_dup, char **map_tab);
void				ft_error(int flag);
int					ft_on_destroy(t_mlx *data);
int					ft_is_dead(t_mlx **data);
void				ft_free_img(t_mlx *data, int i);
void				ft_free_data(t_mlx *data);
int					ft_loading(t_mlx *data);

size_t				ft_map_len(char *map);
size_t				ft_tab_len(char **tab);
char				**ft_dup_map(char **map_tab);
char				*ft_dup_before_nl(char *s1);

void				ft_check_map_player(char *map);
void				ft_check_map_exit(char *map);
int					ft_check_map_collectible(char *map);
int					ft_check_ennemies(char *map);
void				ft_check_map(char *map);
char				**ft_parse_map(char *map);
void				ft_check_map_flood(char **map_tab);
int					ft_check_map_size(char *map);

int					ft_collectible_count(char **map_tab);
t_element			*ft_init_element(char **map_tab, char type);
t_map				*ft_init_map(char **map_tab, char *map);
t_mlx				*ft_init_data(char *map, char **map_tab);
t_img				*ft_init_img(t_mlx *data, char *path);

void				ft_display_map(t_mlx *data);
void				ft_start_display(t_mlx *data);

void				ft_data_move_right(t_mlx **data, int x, int y);
void				ft_data_move_left(t_mlx **data, int x, int y);
void				ft_data_move_up(t_mlx **data, int x, int y);
void				ft_data_move_down(t_mlx **data, int x, int y);
int					ft_move_player(int keycode, t_mlx **data);
void				ft_check_collectible_right_top_bot(t_mlx **data);
void				ft_check_collectible_left(t_mlx **data);
void				ft_check_exit(t_mlx **data);

#endif