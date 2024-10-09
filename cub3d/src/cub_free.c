/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:54:48 by kyeh              #+#    #+#             */
/*   Updated: 2024/10/09 17:15:14 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_free_texture(t_texdata *texture, void *mlx)
{
	if (texture->img[N])
		mlx_destroy_image(mlx, texture->img[N]);
	if (texture->img[S])
		mlx_destroy_image(mlx, texture->img[S]);
	if (texture->img[E])
		mlx_destroy_image(mlx, texture->img[E]);
	if (texture->img[W])
		mlx_destroy_image(mlx, texture->img[W]);
	if (texture->img[D])
		mlx_destroy_image(mlx, texture->img[D]);
	if (texture->path[N])
		free(texture->path[N]);
	if (texture->path[S])
		free(texture->path[S]);
	if (texture->path[E])
		free(texture->path[E]);
	if (texture->path[W])
		free(texture->path[W]);
	if (texture->path[D])
		free(texture->path[D]);
	free(texture);
}

static void	cub_free_frame(t_frame *frame, void *mlx)
{
	t_frame	*temp;

	while (frame)
	{
		temp = frame;
		mlx_destroy_image(mlx, frame->img);
		frame = frame->next;
		free(temp);
	}
}

in	cub_clean(t_data *data)
{
	if (data->texture)
		cub_free_texture(data->texture, data->mlx);
	if (data->frame)
		cub_free_frame(data->frame, data->mlx);
	if (data->image.img)
		mlx_destroy_image(data->mlx, data->image.img);
	if (data->minimap.img)
		mlx_destroy_image(data->mlx, data->minimap.img);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_array(data->map);
	close(data->map_fd);
	exit(SUCCESS);
}
