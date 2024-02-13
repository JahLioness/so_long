/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:35:49 by ede-cola          #+#    #+#             */
/*   Updated: 2024/02/12 19:55:47 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_deal_display(t_mlx *data, int i, int j)
{
	if (data->map->map_tab[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img[0]->img, (j
				* 60), (i * 60));
	else if (data->map->map_tab[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img[1]->img, (j
				* 60), (i * 60));
	else if (data->map->map_tab[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img[2]->img, (j
				* 60), (i * 60));
	else if (data->map->map_tab[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->img[3]->img, (j
				* 60), (i * 60));
	else if (data->map->map_tab[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img[4]->img, (j
				* 60), (i * 60));
	else if (data->map->map_tab[i][j] == 'V')
		mlx_put_image_to_window(data->mlx, data->win, data->img[5]->img, (j
				* 60), (i * 60));
}

void	ft_start_display(t_mlx *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map->map_tab[++i])
	{
		j = -1;
		while (data->map->map_tab[i][++j])
			ft_deal_display(data, i, j);
	}
}

void	ft_display_map(t_mlx *data)
{
	ft_loading(data);
	ft_start_display(data);
	mlx_hook(data->win, KeyPress, KeyPressMask, &ft_move_player, &data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, &ft_on_destroy,
		data);
	mlx_loop_hook(data->mlx, &ft_is_dead, &data);
	mlx_loop(data->mlx);
}
