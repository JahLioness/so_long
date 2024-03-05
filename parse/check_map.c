/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:00:22 by ede-cola          #+#    #+#             */
/*   Updated: 2024/02/28 18:14:56 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_map_char(char *map)
{
	int		fd;
	int		i;
	char	*line;

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
			if (line[i] != '1' && line[i] != '0' && line[i] != 'C'
				&& line[i] != 'E' && line[i] != 'P' && line[i] != '\n'
				&& line[i] != 'V')
				ft_error_and_free(line, fd, 0);
		free(line);
		line = get_next_line(fd, 0);
	}
	free(line);
	close(fd);
}

void	ft_check_map_wall_loop(char *line, size_t i, char *map, int fd)
{
	size_t	j;

	j = 0;
	while (line[j])
	{
		if (i == 0 && line[j] != '1' && j != ft_strlen(line) - 1)
			ft_error_and_free(line, fd, 0);
		else if (i == ft_map_len(map) - 1 && (line[j] != '1'
				&& line[j] != '\n'))
			ft_error_and_free(line, fd, 0);
		else if (line[0] != '1' || line[ft_strlen(line) - 2] != '1')
			ft_error_and_free(line, fd, 0);
		j++;
	}
}

int	ft_check_map_wall(char *map)
{
	size_t	i;
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_error(1);
	line = get_next_line(fd, 0);
	if (!line)
		ft_error_and_free(line, fd, 3);
	i = 0;
	while (line)
	{
		ft_check_map_wall_loop(line, i, map, fd);
		free(line);
		line = get_next_line(fd, 0);
		i++;
	}
	return (free(line), close(fd), 1);
}

int	ft_check_map_is_rectangle(char *map)
{
	int		fd;
	size_t	i;
	size_t	len;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_error(1);
	line = get_next_line(fd, 0);
	if (!line)
		ft_error_and_free(line, fd, 3);
	len = ft_strlen(line);
	i = 0;
	while (line)
	{
		if (i == ft_map_len(map) - 1 && ft_strlen(line) != (len - 1))
			ft_error_and_free(line, fd, 0);
		else if (i != ft_map_len(map) - 1 && ft_strlen(line) != len)
			ft_error_and_free(line, fd, 0);
		free(line);
		line = get_next_line(fd, 0);
		i++;
	}
	return (free(line), close(fd), 0);
}

void	ft_check_map(char *map)
{
	ft_check_map_char(map);
	ft_check_map_is_rectangle(map);
	ft_check_map_wall(map);
	ft_check_map_player(map);
	ft_check_map_exit(map);
	if (!ft_check_map_collectible(map))
		ft_error(0);
}
