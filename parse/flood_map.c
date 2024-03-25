/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:01:48 by ede-cola          #+#    #+#             */
/*   Updated: 2024/03/25 10:05:24 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	ft_flood_tile(char **map_tab, int i, int j)
{
	if (map_tab[i][j] == '0' || map_tab[i][j] == 'E' || map_tab[i][j] == 'C')
	{
		map_tab[i][j] = 'W';
		return (1);
	}
	return (0);
}

char	ft_flood_from_tile(char **map_tab, int i, int j)
{
	char	flood;

	flood = 0;
	flood += ft_flood_tile(map_tab, i, j + 1);
	flood += ft_flood_tile(map_tab, i, j - 1);
	flood += ft_flood_tile(map_tab, i + 1, j);
	flood += ft_flood_tile(map_tab, i - 1, j);
	return (flood);
}

char	ft_flood_map(char **map_tab)
{
	int		i;
	int		j;
	char	flood;

	flood = 0;
	i = -1;
	while (map_tab[++i])
	{
		j = -1;
		while (map_tab[i][++j])
		{
			if (map_tab[i][j] == 'W' || map_tab[i][j] == 'P')
				flood += ft_flood_from_tile(map_tab, i, j);
		}
	}
	return (flood);
}

int	ft_check_flooded(char **map_tab)
{
	int		i;
	int		j;

	i = -1;
	while (map_tab[++i])
	{
		j = -1;
		while (map_tab[i][++j])
		{
			if (map_tab[i][j] == 'C' || map_tab[i][j] == 'E')
				return (1);
		}
	}
	return (0);
}

void	ft_check_map_flood(char **map)
{
	char	**map_dup;
	char	check;

	map_dup = ft_dup_map(map);
	if (!map_dup)
		return ;
	check = 1;
	while (check)
		check = ft_flood_map(map_dup);
	if (ft_check_flooded(map_dup))
		ft_map_flood_error(map, map_dup);
	ft_free_split(ft_tab_len(map_dup), map_dup);
}
