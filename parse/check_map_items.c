/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_items.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:50:38 by ede-cola          #+#    #+#             */
/*   Updated: 2024/02/28 16:05:11 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_map_player(char *map)
{
	int		fd;
	int		i;
	int		player;
	char	*line;

	player = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_error(1);
	line = get_next_line(fd, 0);
	if (!line)
		ft_error_and_free(line, fd, 3);
	while (line)
	{
		i = -1;
		while (line[++i])
			if (line[i] == 'P')
				player++;
		free(line);
		line = get_next_line(fd, 0);
	}
	free(line);
	close(fd);
	if (player != 1)
		ft_error(0);
}

void	ft_check_map_exit(char *map)
{
	int		fd;
	int		i;
	int		exit;
	char	*line;

	exit = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_error(1);
	line = get_next_line(fd, 0);
	if (!line)
		ft_error_and_free(line, fd, 3);
	while (line)
	{
		i = -1;
		while (line[++i])
			if (line[i] == 'E')
				exit++;
		free(line);
		line = get_next_line(fd, 0);
	}
	free(line);
	close(fd);
	if (exit != 1)
		ft_error(0);
}

int	ft_check_map_collectible(char *map)
{
	int		fd;
	int		i;
	int		collectible;
	char	*line;

	collectible = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_error(1);
	line = get_next_line(fd, 0);
	if (!line)
		ft_error_and_free(line, fd, 3);
	while (line)
	{
		i = -1;
		while (line[++i])
			if (line[i] == 'C')
				collectible++;
		free(line);
		line = get_next_line(fd, 0);
	}
	return (free(line), close(fd), collectible);
}

int	ft_check_ennemies(char *map)
{
	int		fd;
	int		i;
	int		ennemies;
	char	*line;

	ennemies = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_error(1);
	line = get_next_line(fd, 0);
	if (!line)
		ft_error_and_free(line, fd, 3);
	while (line)
	{
		i = -1;
		while (line[++i])
			if (line[i] == 'V')
				ennemies++;
		free(line);
		line = get_next_line(fd, 0);
	}
	return (free(line), close(fd), ennemies);
}
