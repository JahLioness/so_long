/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:55:59 by ede-cola          #+#    #+#             */
/*   Updated: 2024/02/28 15:55:25 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_data(t_mlx *data)
{
	if (data->map->map_tab)
		ft_free_split(data->map->height, data->map->map_tab);
	if (data->map)
		free(data->map);
	if (data->player)
		free(data->player);
	if (data->vilain)
		free(data->vilain);
	if (data->exit)
		free(data->exit);
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
	}
	if (data->mlx)
		free(data->mlx);
	if (data)
		free(data);
	ft_error(2);
}

void	ft_free_img(t_mlx *data, int i)
{
	while (i >= 0)
	{
		if (data->img[i])
		{
			mlx_destroy_image(data->mlx, data->img[i]->img);
			free(data->img[i]);
		}
		i--;
	}
}

int	ft_init_data_img(t_mlx *data)
{
	data->img[0] = ft_init_img(data, "./assets/textures/wall.xpm");
	if (!data->img[0])
		return (ft_free_img(data, 0), ft_free_data(data), 0);
	data->img[1] = ft_init_img(data, "./assets/textures/floor.xpm");
	if (!data->img[1])
		return (ft_free_img(data, 1), ft_free_data(data), 0);
	data->img[2] = ft_init_img(data,
			"./assets/collectible/sukuna_finger_floor.xpm");
	if (!data->img[2])
		return (ft_free_img(data, 2), ft_free_data(data), 0);
	data->img[3] = ft_init_img(data, "./assets/perso/yuji_floor.xpm");
	if (!data->img[3])
		return (ft_free_img(data, 3), ft_free_data(data), 0);
	data->img[4] = ft_init_img(data, "./assets/textures/portal_inactivate.xpm");
	if (!data->img[4])
		return (ft_free_img(data, 4), ft_free_data(data), 0);
	data->img[5] = ft_init_img(data, "./assets/perso/fleau.xpm");
	if (!data->img[5])
		return (ft_free_img(data, 5), ft_free_data(data), 0);
	data->img[6] = ft_init_img(data, "./assets/screen/game_over_zip.xpm");
	if (!data->img[6])
		return (ft_free_img(data, 6), ft_free_data(data), 0);
	return (1);
}

int	ft_init_data_2(t_mlx *data, char *map, char **map_tab)
{
	data->player = ft_init_element(map_tab, 'P');
	if (!data->player)
		return (ft_free_data(data), 0);
	if (ft_check_ennemies(map))
	{
		data->vilain = ft_init_element(map_tab, 'V');
		if (!data->vilain)
			return (ft_free_data(data), 0);
	}
	data->exit = ft_init_element(map_tab, 'E');
	if (!data->exit)
		return (ft_free_data(data), 0);
	return (1);
}

t_mlx	*ft_init_data(char *map, char **map_tab)
{
	t_mlx	*data;

	data = ft_calloc(1, sizeof(t_mlx));
	if (!data)
		return (NULL);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (ft_free_data(data), NULL);
	data->map = ft_init_map(map_tab, map);
	if (!data->map)
		return (ft_free_data(data), NULL);
	data->win = mlx_new_window(data->mlx, data->map->width * 60,
			data->map->height * 60, "so_long");
	if (!data->win)
		return (ft_free_data(data), NULL);
	ft_init_data_2(data, map, map_tab);
	ft_init_data_img(data);
	return (data);
}
