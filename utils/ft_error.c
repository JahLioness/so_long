/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:53:23 by ede-cola          #+#    #+#             */
/*   Updated: 2024/03/26 22:19:45 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(int flag)
{
	if (flag == 0)
		ft_putstr_fd("Error : Invalid Map\n", 2);
	else if (flag == 1)
		ft_putstr_fd("Error : Invalid File\n", 2);
	else if (flag == 2)
		ft_putstr_fd("Error : Data initialization failed\n", 2);
	else if (flag == 3)
		ft_putstr_fd("Error : Empty file\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_error_and_free(char *line, int fd, int flag)
{
	get_next_line(fd, 1);
	if (line)
		free(line);
	close(fd);
	ft_error(flag);
}

void	ft_map_flood_error(char **map_dup, char **map_tab)
{
	ft_free_split(ft_tab_len(map_dup), map_dup);
	ft_free_split(ft_tab_len(map_tab), map_tab);
	ft_error(0);
}

void	ft_map_size_error(char *line, int fd, void *mlx, int flag)
{
	free(line);
	close(fd);
	mlx_destroy_display(mlx);
	free(mlx);
	if (flag)
		ft_error(0);
}
