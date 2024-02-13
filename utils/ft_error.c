/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:53:23 by ede-cola          #+#    #+#             */
/*   Updated: 2024/02/12 11:33:57 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_error_and_free(char *line, int fd)
{
	get_next_line(fd, 1);
	if (line)
		free(line);
	close(fd);
	ft_error();
}

void	ft_map_flood_error(char **map_dup, char **map_tab)
{
	ft_free_split(ft_tab_len(map_dup), map_dup);
	ft_free_split(ft_tab_len(map_tab), map_tab);
	ft_error();
}
