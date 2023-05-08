/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjeon <seonjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:59:26 by seonjeon          #+#    #+#             */
/*   Updated: 2023/05/08 17:06:08 by seonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	init_point(t_rbox *rbox, t_map *cub)
{
	rbox->pos.x = cub->position[0];
	rbox->pos.y = cub->position[1];
	rbox->dir.x = 0;
	rbox->dir.y = 0;
	rbox->plane.x = 0;
	rbox->plane.y = 0.66;
	if (cub->direction == 'N')
		rbox->dir.x = -1;
	if (cub->direction == 'S')
	{
		rbox->dir.x = 1;
		rbox->plane.y = -0.66;
	}
	if (cub->direction == 'W')
	{
		rbox->dir.y = -1;
		rbox->plane.x = -0.66;
		rbox->plane.y = 0;
	}
	if (cub->direction == 'E')
	{
		rbox->dir.y = 1;
		rbox->plane.x = 0.66;
		rbox->plane.y = 0;
	}
}

int	get_color(int color[3])
{
	int	ret;

	ret = 0;
	ret |= color[0] << 16;
	ret |= (color[1] & 0xFF) << 8;
	ret |= (color[2] & 0xFF);
	return (ret);
}

void	init_buf(t_rbox *rbox)
{
	int	x;
	int	y;

	y = 0;
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			if (y < W_HEIGHT / 2)
				rbox->buf[y][x] = rbox->ceiling;
			else
				rbox->buf[y][x] = rbox->floor;
			x++;
		}
		y++;
	}
}

int	set_texture(t_box *box, int *texture, char *path)
{
	int	x;
	int	y;

	box->img = mlx_xpm_file_to_image(box->mlx, \
		path, &box->i_width, &box->i_height);
	if (!box->img)
		return (1);
	box->addr = (int *) mlx_get_data_addr(box->img, \
		&box->bpp, &box->llen, &box->endian);
	y = 0;
	while (y < T_HEIGHT)
	{
		x = 0;
		while (x < T_WIDTH)
		{
			texture[T_WIDTH * y + x] = box->addr[T_WIDTH * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(box->mlx, box->img);
	return (0);
}

int	init_texture(t_rbox *rbox, t_map *cub)
{
	int	i;
	int	tex_err;

	tex_err = 0;
	rbox->texture = (int **)malloc(sizeof(int *) * 4);
	if (!rbox->texture)
		return (-1);
	i = 0;
	while (i < 4)
	{
		rbox->texture[i] = (int *)malloc(sizeof(int) * (T_HEIGHT * T_WIDTH));
		if (!rbox->texture[i++])
			return (-1);
	}
	tex_err += set_texture(rbox->box, rbox->texture[0], cub->no_texture);
	tex_err += set_texture(rbox->box, rbox->texture[1], cub->so_texture);
	tex_err += set_texture(rbox->box, rbox->texture[2], cub->we_texture);
	tex_err += set_texture(rbox->box, rbox->texture[3], cub->ea_texture);
	free_path(cub);
	if (tex_err)
		return (free_texture(rbox->texture));
	return (0);
}
