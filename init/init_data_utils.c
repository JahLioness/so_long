/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:53:57 by ede-cola          #+#    #+#             */
/*   Updated: 2024/02/09 11:56:40 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_collectible_count(char **map_tab)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (map_tab[++i])
	{
		j = -1;
		while (map_tab[i][++j])
			if (map_tab[i][j] == 'C')
				count++;
	}
	return (count);
}

t_element	*ft_init_element(char **map_tab, char type)
{
	t_element	*element;
	int			i;
	int			j;

	element = ft_calloc(1, sizeof(t_element));
	if (!element)
		return (NULL);
	element->c = 0;
	if (type == 'P' || type == 'V')
		element->c = 1;
	i = -1;
	while (map_tab[++i])
	{
		j = -1;
		while (map_tab[i][++j])
		{
			if (map_tab[i][j] == type)
			{
				element->x = j;
				element->y = i;
				return (element);
			}
		}
	}
	return (free(element), NULL);
}

t_map	*ft_init_map(char **map_tab, char *map)
{
	t_map	*map_data;

	map_data = ft_calloc(1, sizeof(t_map));
	if (!map_data)
		return (NULL);
	map_data->map_tab = map_tab;
	map_data->width = ft_strlen(map_tab[0]);
	map_data->height = ft_map_len(map);
	map_data->collectible = ft_collectible_count(map_tab);
	map_data->nb_move = 0;
	return (map_data);
}

t_img	*ft_init_img(t_mlx *data, char *path)
{
	t_img	*img;

	img = ft_calloc(1, sizeof(t_img));
	if (!img)
		return (NULL);
	img->img = mlx_xpm_file_to_image(data->mlx, path, &img->width,
			&img->height);
	if (!img->img)
		return (free(img), NULL);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len,
			&img->endian);
	if (!img->addr)
		return (free(img->img), free(img), NULL);
	return (img);
}
