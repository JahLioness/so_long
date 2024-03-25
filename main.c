/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:47:07 by ede-cola          #+#    #+#             */
/*   Updated: 2024/03/25 10:06:25 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av, char **envp)
{
	char	**map_tab;
	t_mlx	*data;

	if (ac != 2)
		return (ft_putstr_fd("Error : you must input ONE arg\n", 2), 0);
	if (!envp[0])
		return (ft_putstr_fd("Error : env variables needed\n", 2), 0);
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4)
		|| ft_check_one_extension(av[1]))
		return (ft_error(1), 0);
	if (ft_check_map_size(av[1]))
		return (ft_error(0), 0);
	map_tab = ft_parse_map(av[1]);
	if (!map_tab)
		return (0);
	ft_check_map_flood(map_tab);
	data = ft_init_data(av[1], map_tab);
	ft_loading(data);
	ft_display_map(data);
	if (map_tab)
		ft_free_split(ft_map_len(av[1]), map_tab);
	if (data)
		ft_on_destroy(data);
	return (0);
}
