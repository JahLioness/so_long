/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:50:16 by ede-cola          #+#    #+#             */
/*   Updated: 2024/02/13 11:45:10 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_img(t_mlx *data, t_img *img)
{
	mlx_put_image_to_window(data->mlx, data->win, img->img, ((data->map->width
				* 60) - img->width) / 2, ((data->map->height * 60)
			- img->height) / 2);
	mlx_do_sync(data->mlx);
	sleep(1);
	mlx_destroy_image(data->mlx, img->img);
	free(img);
}

int	ft_loading(t_mlx *data)
{
	t_img	*img;

	img = ft_init_img(data, "./assets/screen/Loading1.xpm");
	ft_put_img(data, img);
	img = ft_init_img(data, "./assets/screen/Loading2.xpm");
	ft_put_img(data, img);
	img = ft_init_img(data, "./assets/screen/Loading3.xpm");
	ft_put_img(data, img);
	img = ft_init_img(data, "./assets/screen/Loading4.xpm");
	ft_put_img(data, img);
	img = ft_init_img(data, "./assets/screen/Loading5.xpm");
	ft_put_img(data, img);
	img = ft_init_img(data, "./assets/screen/Loading6.xpm");
	ft_put_img(data, img);
	return (1);
}
