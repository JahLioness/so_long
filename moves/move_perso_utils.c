/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_perso_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:28:57 by ede-cola          #+#    #+#             */
/*   Updated: 2024/02/12 11:33:00 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_is_perso_on_exit(t_mlx **data, int left)
{
	if (left)
	{
		(*data)->img[3] = ft_init_img(*data,
				"./assets/perso/yuji_revert_portal.xpm");
		if (!(*data)->img[3])
			ft_on_destroy(*data);
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			(*data)->img[3]->img, (*data)->player->x * 60, (*data)->player->y
			* 60);
	}
	else
	{
		(*data)->img[3] = ft_init_img(*data,
				"./assets/perso/yuji_portal_inactivate.xpm");
		if (!(*data)->img[3])
			ft_on_destroy(*data);
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			(*data)->img[3]->img, (*data)->player->x * 60, (*data)->player->y
			* 60);
	}
}

void	ft_check_collectible_right_top_bot(t_mlx **data)
{
	if ((*data)->map->collectible == 0)
	{
		(*data)->img[3] = ft_init_img(*data, "./assets/perso/sukuna_floor.xpm");
		if (!(*data)->img[3])
			ft_on_destroy(*data);
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			(*data)->img[3]->img, (*data)->player->x * 60, (*data)->player->y
			* 60);
	}
	else if ((*data)->player->x == (*data)->exit->x
		&& (*data)->player->y == (*data)->exit->y)
		ft_is_perso_on_exit(data, 0);
	else
	{
		(*data)->img[3] = ft_init_img(*data, "./assets/perso/yuji_floor.xpm");
		if (!(*data)->img[3])
			ft_on_destroy(*data);
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			(*data)->img[3]->img, ((*data)->player->x * 60), ((*data)->player->y
				* 60));
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			(*data)->img[4]->img, ((*data)->exit->x * 60), ((*data)->exit->y
				* 60));
	}
}

void	ft_check_collectible_left(t_mlx **data)
{
	if ((*data)->map->collectible == 0)
		(*data)->img[3] = ft_init_img((*data),
				"./assets/perso/sukuna_frevert.xpm");
	else if ((*data)->player->x == (*data)->exit->x
		&& (*data)->player->y == (*data)->exit->y)
		ft_is_perso_on_exit(data, 1);
	else
		(*data)->img[3] = ft_init_img((*data),
				"./assets/perso/yuji_frevert.xpm");
	if (!(*data)->img[3])
		ft_on_destroy(*data);
	mlx_put_image_to_window((*data)->mlx, (*data)->win,
		(*data)->img[3]->img, (*data)->player->x * 60, (*data)->player->y
		* 60);
}

void	ft_check_exit(t_mlx **data)
{
	if ((*data)->map->collectible == 0)
		(*data)->exit->c = 1;
	if ((*data)->exit->c == 1)
	{
		mlx_destroy_image((*data)->mlx, (*data)->img[4]->img);
		free((*data)->img[4]);
		(*data)->img[4] = ft_init_img((*data),
				"./assets/textures/portal_darken.xpm");
		if (!(*data)->img[4])
			ft_on_destroy(*data);
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			(*data)->img[4]->img, (*data)->exit->x * 60, (*data)->exit->y * 60);
	}
	if ((*data)->player->x == (*data)->exit->x
		&& (*data)->player->y == (*data)->exit->y && (*data)->exit->c == 1)
		ft_on_destroy((*data));
}
