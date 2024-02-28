/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:06:41 by ede-cola          #+#    #+#             */
/*   Updated: 2024/02/28 16:06:26 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_map_len(char *map)
{
	int		fd;
	size_t	len;
	char	*line;

	len = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd, 0);
	if (!line)
		ft_error_and_free(line, fd, 3);
	while (line)
	{
		free(line);
		line = get_next_line(fd, 0);
		len++;
	}
	return (free(line), close(fd), len);
}

size_t	ft_tab_len(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	*ft_dup_before_nl(char *s1)
{
	char	*ret;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s1[len] && s1[len] != '\n')
		len++;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	while (s1[i] && i < len)
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	**ft_dup_map(char **map_tab)
{
	char	**map_dup;
	int		i;

	map_dup = ft_calloc(ft_tab_len(map_tab) + 1, sizeof(char *));
	if (!map_dup)
		return (NULL);
	i = -1;
	while (map_tab[++i])
	{
		map_dup[i] = ft_strdup(map_tab[i]);
		if (!map_dup[i])
			return (ft_free_split(i, map_dup), NULL);
	}
	return (map_dup);
}
