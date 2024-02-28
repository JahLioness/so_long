/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:19:38 by ede-cola          #+#    #+#             */
/*   Updated: 2024/02/28 15:55:58 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_size	*ft_init_size(char *line, void *mlx)
{
	t_size	*size;

	size = ft_calloc(1, sizeof(t_size));
	if (!size)
		return (NULL);
	size->height_len = 0;
	size->line_len = ft_strlen(line);
	mlx_get_screen_size(mlx, &size->screen_width, &size->screen_height);
	return (size);
}

int	ft_check_map_size(char *map)
{
	int		fd;
	void	*mlx;
	char	*line;
	t_size	*size;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd, 0);
	mlx = mlx_init();
	size = ft_init_size(line, mlx);
	if (!size)
		return (free(mlx), free(line), close(fd), 0);
	while (line)
	{
		size->height_len++;
		free(line);
		line = get_next_line(fd, 0);
	}
	if ((size->line_len * 60) > size->screen_width || (size->height_len
			* 60) > size->screen_height)
		return (free(size), free(line), close(fd), mlx_destroy_display(mlx),
			free(mlx), 0);
	return (free(size), free(line), close(fd), mlx_destroy_display(mlx),
		free(mlx), 1);
}

char	**ft_parse_map(char *map)
{
	char	**map_tab;
	char	*line;
	int		fd;
	int		i;

	ft_check_map(map);
	map_tab = ft_calloc((ft_map_len(map) + 1), sizeof(char *));
	if (!map_tab)
		ft_error(2);
	i = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_error(1);
	line = get_next_line(fd, 0);
	while (line)
	{
		map_tab[i] = ft_dup_before_nl(line);
		if (!map_tab[i])
			return (ft_free_split(i, map_tab), free(line), close(fd), NULL);
		free(line);
		line = get_next_line(fd, 0);
		i++;
	}
	map_tab[i] = NULL;
	return (free(line), close(fd), map_tab);
}
