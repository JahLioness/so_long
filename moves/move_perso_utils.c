/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_perso_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:28:57 by ede-cola          #+#    #+#             */
/*   Updated: 2024/03/26 21:57:47 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_is_perso_on_exit(t_mlx **data, int left)
{
	if (left)
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			(*data)->img[8]->img, (*data)->player->x * 60, (*data)->player->y
			* 60);
	else
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			(*data)->img[7]->img, (*data)->player->x * 60, (*data)->player->y
			* 60);
}

void	ft_check_collectible_right_top_bot(t_mlx **data)
{
	if ((*data)->map->collectible == 0)
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			(*data)->img[5]->img, (*data)->player->x * 60, (*data)->player->y
			* 60);
	else if ((*data)->player->x == (*data)->exit->x
		&& (*data)->player->y == (*data)->exit->y)
		ft_is_perso_on_exit(data, 0);
	else
	{
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			(*data)->img[3]->img, ((*data)->player->x * 60), ((*data)->player->y
				* 60));
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			(*data)->img[9]->img, ((*data)->exit->x * 60), ((*data)->exit->y
				* 60));
	}
}

void	ft_check_collectible_left(t_mlx **data)
{
	if ((*data)->map->collectible == 0)
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			(*data)->img[6]->img, (*data)->player->x * 60, (*data)->player->y
			* 60);
	else if ((*data)->player->x == (*data)->exit->x
		&& (*data)->player->y == (*data)->exit->y)
		ft_is_perso_on_exit(data, 1);
	else
	{
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			(*data)->img[4]->img, ((*data)->player->x * 60), ((*data)->player->y
				* 60));
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			(*data)->img[9]->img, ((*data)->exit->x * 60), ((*data)->exit->y
				* 60));
	}
}

void	ft_check_exit(t_mlx **data)
{
	if ((*data)->map->collectible == 0)
		(*data)->exit->c = 1;
	if ((*data)->exit->c == 1)
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			(*data)->img[12]->img, (*data)->exit->x * 60, (*data)->exit->y
			* 60);
	if ((*data)->player->x == (*data)->exit->x
		&& (*data)->player->y == (*data)->exit->y && (*data)->exit->c == 1)
		ft_on_destroy((*data));
}
