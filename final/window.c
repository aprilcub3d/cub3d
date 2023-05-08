/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:59:38 by seonjeon          #+#    #+#             */
/*   Updated: 2023/05/08 17:08:59 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	main_loop(t_rbox *rbox)
{
	raycasting(rbox);
	return (0);
}

void	raycasting(t_rbox *rbox)
{
	int		x;
	double	cam_x;
	double	dist;
	int		side;

	if (rbox->re_buf)
		init_buf(rbox);
	x = 0;
	while (x < W_WIDTH)
	{
		side = 0;
		cam_x = 2 * x / (double)W_WIDTH - 1;
		rbox->ray.x = rbox->dir.x + rbox->plane.x * cam_x;
		rbox->ray.y = rbox->dir.y + rbox->plane.y * cam_x;
		dist = dda(rbox, &side);
		draw_line(rbox, dist, x, side);
		x++;
	}
	draw_minimap(rbox);
	draw(rbox);
}

int	init_rbox(t_rbox *rbox, t_box *box, t_map *cub)
{
	rbox->box = box;
	box->map = cub->map;
	box->m_width = cub->map_width;
	box->m_height = cub->map_height;
	box->mlx = mlx_init();
	init_point(rbox, cub);
	rbox->box->map[cub->position[0]][cub->position[1]] = 0;
	rbox->re_buf = 0;
	rbox->ceiling = get_color(cub->ceiling_color);
	rbox->floor = get_color(cub->floor_color);
	init_buf(rbox);
	if (init_texture(rbox, cub) == -1)
	{
		printf("Texture Error\n");
		free(rbox->box);
		free(rbox);
		return (1);
	}
	return (0);
}

int	make_window(t_map *cub)
{
	t_box	*box;
	t_rbox	*rbox;

	box = (t_box *)malloc(sizeof(t_box));
	if (!box)
		return (1);
	rbox = (t_rbox *)malloc(sizeof(t_rbox));
	if (!rbox)
	{
		free(box);
		return (1);
	}
	if (init_rbox(rbox, box, cub))
		return (1);
	box->win = mlx_new_window(box->mlx, W_WIDTH, W_HEIGHT, "CUB3D");
	box->img = mlx_new_image(box->mlx, W_WIDTH, W_HEIGHT);
	box->addr = (int *)mlx_get_data_addr(box->img, &box->bpp, \
			&box->llen, &box->endian);
	mlx_loop_hook(box->mlx, &main_loop, rbox);
	mlx_hook(box->win, ON_DESTROY, 0, exit_hook, rbox);
	mlx_hook(box->win, ON_KEYDOWN, 0, &key_press, rbox);
	mlx_loop(box->mlx);
	return (0);
}
