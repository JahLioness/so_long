/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:50:32 by ede-cola          #+#    #+#             */
/*   Updated: 2024/02/09 13:10:57 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_on_destroy(t_mlx *data)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		mlx_destroy_image(data->mlx, data->img[i]->img);
		free(data->img[i]);
		i++;
	}
	ft_free_split(data->map->height, data->map->map_tab);
	free(data->map);
	free(data->player);
	free(data->exit);
	if (data->vilain)
		free(data->vilain);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	exit(EXIT_SUCCESS);
}

int	ft_is_dead(t_mlx **data)
{
	if ((*data)->player->c == 0)
	{
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			(*data)->img[6]->img, (((*data)->map->width * 60)
				- (*data)->img[6]->width) / 2, (((*data)->map->height * 60)
				- (*data)->img[6]->height) / 2);
		mlx_do_sync((*data)->mlx);
		sleep(2);
		ft_on_destroy(*data);
	}
	return (0);
}
