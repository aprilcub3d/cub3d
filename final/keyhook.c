/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjeon <seonjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:59:29 by seonjeon          #+#    #+#             */
/*   Updated: 2023/05/08 17:01:49 by seonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	exit_hook(t_rbox *rbox)
{
	mlx_destroy_window(rbox->box->mlx, rbox->box->win);
	exit(0);
	return (0);
}

void	key_ad(int keycode, t_rbox *rbox)
{
	double	move;
	double	rad;
	t_point	rot_dir;

	move = 0.05;
	rad = 1.5708;
	rot_dir.x = rbox->dir.x * cos(rad) - rbox->dir.y * sin(rad);
	rot_dir.y = rbox->dir.x * sin(rad) + rbox->dir.y * cos(rad);
	if (keycode == KEY_D)
	{
		rot_dir.x *= -1;
		rot_dir.y *= -1;
	}
	if (rbox->box->map[(int)(rbox->pos.x + rot_dir.x * move)] \
			[(int)rbox->pos.y] == 0)
		rbox->pos.x += rot_dir.x * move;
	if (rbox->box->map[(int)rbox->pos.x] \
			[(int)(rbox->pos.y + rot_dir.y * move)] == 0)
		rbox->pos.y += rot_dir.y * move;
}

void	key_ws(int keycode, t_rbox *rbox)
{
	double	move;

	move = 0.05;
	if (keycode == KEY_W)
	{
		if (rbox->box->map[(int)(rbox->pos.x + rbox->dir.x * move)] \
				[(int)rbox->pos.y] == 0)
			rbox->pos.x += rbox->dir.x * move;
		if (rbox->box->map[(int)rbox->pos.x] \
				[(int)(rbox->pos.y + rbox->dir.y * move)] == 0)
			rbox->pos.y += rbox->dir.y * move;
	}
	if (keycode == KEY_S)
	{
		if (rbox->box->map[(int)(rbox->pos.x - rbox->dir.x * move)] \
				[(int)rbox->pos.y] == 0)
			rbox->pos.x -= rbox->dir.x * move;
		if (rbox->box->map[(int) rbox->pos.x] \
				[(int)(rbox->pos.y - rbox->dir.y * move)] == 0)
			rbox->pos.y -= rbox->dir.y * move;
	}
}

void	key_dir(int keycode, t_rbox *rbox)
{
	double	prev_dir_x;
	double	prev_plane_x;
	double	rotate;

	rotate = 0.05;
	if (keycode == KEY_RIGHT)
		rotate *= -1;
	prev_dir_x = rbox->dir.x;
	rbox->dir.x = rbox->dir.x * cos(rotate) - rbox->dir.y * sin(rotate);
	rbox->dir.y = prev_dir_x * sin(rotate) + rbox->dir.y * cos(rotate);
	prev_plane_x = rbox->plane.x;
	rbox->plane.x = \
		rbox->plane.x * cos(rotate) - rbox->plane.y * sin(rotate);
	rbox->plane.y = \
		prev_plane_x * sin(rotate) + rbox->plane.y * cos(rotate);
}

int	key_press(int keycode, t_rbox *rbox)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(rbox->box->mlx, rbox->box->win);
		exit(0);
	}
	if (keycode == KEY_W || keycode == KEY_S)
		key_ws(keycode, rbox);
	if (keycode == KEY_A || keycode == KEY_D)
		key_ad(keycode, rbox);
	if (keycode == KEY_RIGHT || keycode == KEY_LEFT)
		key_dir(keycode, rbox);
	printf("pos (%f, %f)\n", rbox->pos.x, rbox->pos.y);
	mlx_clear_window(rbox->box->mlx, rbox->box->win);
	raycasting(rbox);
	return (0);
}
