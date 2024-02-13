/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:57:17 by ede-cola          #+#    #+#             */
/*   Updated: 2024/02/05 10:54:11 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_data_move_right(t_mlx **data, int x, int y)
{
	if ((*data)->map->map_tab[y][x + 1] == 'C')
	{
		(*data)->map->map_tab[y][x] = '0';
		(*data)->map->map_tab[y][x + 1] = 'P';
		(*data)->player->x++;
		(*data)->map->collectible--;
	}
	else if ((*data)->map->map_tab[y][x + 1] == 'V')
		(*data)->player->c = 0;
	else
	{
		(*data)->map->map_tab[y][x] = '0';
		(*data)->map->map_tab[y][x + 1] = 'P';
		(*data)->player->x++;
	}
	(*data)->map->nb_move++;
}

void	ft_data_move_left(t_mlx **data, int x, int y)
{
	if ((*data)->map->map_tab[y][x - 1] == 'C')
	{
		(*data)->map->map_tab[y][x] = '0';
		(*data)->map->map_tab[y][x - 1] = 'P';
		(*data)->player->x--;
		(*data)->map->collectible--;
	}
	else if ((*data)->map->map_tab[y][x - 1] == 'V')
		(*data)->player->c = 0;
	else
	{
		(*data)->map->map_tab[y][x] = '0';
		(*data)->map->map_tab[y][x - 1] = 'P';
		(*data)->player->x--;
	}
	(*data)->map->nb_move++;
}

void	ft_data_move_up(t_mlx **data, int x, int y)
{
	if ((*data)->map->map_tab[y - 1][x] == 'C')
	{
		(*data)->map->map_tab[y][x] = '0';
		(*data)->map->map_tab[y - 1][x] = 'P';
		(*data)->player->y--;
		(*data)->map->collectible--;
	}
	else if ((*data)->map->map_tab[y - 1][x] == 'V')
		(*data)->player->c = 0;
	else
	{
		(*data)->map->map_tab[y][x] = '0';
		(*data)->map->map_tab[y - 1][x] = 'P';
		(*data)->player->y--;
	}
	(*data)->map->nb_move++;
}

void	ft_data_move_down(t_mlx **data, int x, int y)
{
	if ((*data)->map->map_tab[y + 1][x] == 'C')
	{
		(*data)->map->map_tab[y][x] = '0';
		(*data)->map->map_tab[y + 1][x] = 'P';
		(*data)->player->y++;
		(*data)->map->collectible--;
	}
	else if ((*data)->map->map_tab[y + 1][x] == 'V')
		(*data)->player->c = 0;
	else
	{
		(*data)->map->map_tab[y][x] = '0';
		(*data)->map->map_tab[y + 1][x] = 'P';
		(*data)->player->y++;
	}
	(*data)->map->nb_move++;
}
