/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_perso.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:54:36 by ede-cola          #+#    #+#             */
/*   Updated: 2024/02/06 16:26:08 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move_player_right(t_mlx **data)
{
	int	x;
	int	y;

	x = (*data)->player->x;
	y = (*data)->player->y;
	if ((*data)->map->map_tab[y][x + 1] == '1')
		return ;
	mlx_destroy_image((*data)->mlx, (*data)->img[3]->img);
	free((*data)->img[3]);
	if ((*data)->player->x != (*data)->exit->x
		|| (*data)->player->y != (*data)->exit->y)
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			(*data)->img[1]->img, (*data)->player->x * 60, (*data)->player->y
			* 60);
	ft_data_move_right(data, x, y);
	ft_check_collectible_right_top_bot(data);
}

void	ft_move_player_left(t_mlx **data)
{
	int	x;
	int	y;

	x = (*data)->player->x;
	y = (*data)->player->y;
	if ((*data)->map->map_tab[y][x - 1] == '1')
		return ;
	mlx_destroy_image((*data)->mlx, (*data)->img[3]->img);
	free((*data)->img[3]);
	if ((*data)->player->x != (*data)->exit->x
		|| (*data)->player->y != (*data)->exit->y)
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			(*data)->img[1]->img, (*data)->player->x * 60, (*data)->player->y
			* 60);
	ft_data_move_left(data, x, y);
	ft_check_collectible_left(data);
}

void	ft_move_player_up(t_mlx **data)
{
	int	x;
	int	y;

	x = (*data)->player->x;
	y = (*data)->player->y;
	if ((*data)->map->map_tab[y - 1][x] == '1')
		return ;
	mlx_destroy_image((*data)->mlx, (*data)->img[3]->img);
	free((*data)->img[3]);
	if ((*data)->player->x != (*data)->exit->x
		|| (*data)->player->y != (*data)->exit->y)
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			(*data)->img[1]->img, (*data)->player->x * 60, (*data)->player->y
			* 60);
	ft_data_move_up(data, x, y);
	ft_check_collectible_right_top_bot(data);
}

void	ft_move_player_down(t_mlx **data)
{
	int	x;
	int	y;

	x = (*data)->player->x;
	y = (*data)->player->y;
	if ((*data)->map->map_tab[y + 1][x] == '1')
		return ;
	mlx_destroy_image((*data)->mlx, (*data)->img[3]->img);
	free((*data)->img[3]);
	if ((*data)->player->x != (*data)->exit->x
		|| (*data)->player->y != (*data)->exit->y)
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			(*data)->img[1]->img, (*data)->player->x * 60, (*data)->player->y
			* 60);
	ft_data_move_down(data, x, y);
	ft_check_collectible_right_top_bot(data);
}

int	ft_move_player(int keycode, t_mlx **data)
{
	char	*str;

	if (keycode == 119 || keycode == 65362)
		ft_move_player_up(data);
	if (keycode == 115 || keycode == 65364)
		ft_move_player_down(data);
	if (keycode == 97 || keycode == 65361)
		ft_move_player_left(data);
	if (keycode == 100 || keycode == 65363)
		ft_move_player_right(data);
	if (keycode == 65307)
		ft_on_destroy(*data);
	ft_check_exit(data);
	str = ft_itoa((*data)->map->nb_move);
	ft_printf("  \r  Nombre de mouvement : %d", (*data)->map->nb_move);
	mlx_put_image_to_window((*data)->mlx, (*data)->win, (*data)->img[0]->img, 1
		* 60, ((*data)->map->height - 1) * 60);
	mlx_string_put((*data)->mlx, (*data)->win, 30, ((*data)->map->height * 60)
		- 20, 0xFF000000, "Moves: ");
	mlx_string_put((*data)->mlx, (*data)->win, 100, ((*data)->map->height * 60)
		- 20, 0xFF000000, str);
	free(str);
	return (0);
}
