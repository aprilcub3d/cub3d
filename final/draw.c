/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjeon <seonjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:59:20 by seonjeon          #+#    #+#             */
/*   Updated: 2023/05/08 13:57:46 by seonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	get_tex_num(t_rbox *rbox, int side)
{
	if (side == 0)
	{
		if (rbox->ray.x < 0)
			return (0);
		return (1);
	}
	if (rbox->ray.y < 0)
		return (2);
	return (3);
}

void	get_line_height(t_tex *t, double dist)
{
	t->line_height = (int)(W_HEIGHT / dist);
	t->line_start = -t->line_height / 2 + W_HEIGHT / 2;
	if (t->line_start < 0)
		t->line_start = 0;
	t->line_end = t->line_height / 2 + W_HEIGHT / 2;
	if (t->line_end >= W_HEIGHT)
		t->line_end = W_HEIGHT - 1;
}

void	draw_line(t_rbox *rbox, double dist, int x, int side)
{
	t_tex	t;

	get_line_height(&t, dist);
	t.wall_x = rbox->pos.x + dist * rbox->ray.x;
	if (side == 0)
		t.wall_x = rbox->pos.y + dist * rbox->ray.y;
	t.wall_x -= floor(t.wall_x);
	t.tex_num = get_tex_num(rbox, side);
	t.tex_x = t.wall_x * T_WIDTH;
	if ((side == 0 && rbox->ray.x > 0) || (side == 1 && rbox->ray.y < 0))
		t.tex_x = T_WIDTH - t.tex_x - 1;
	t.step = 1.0 * T_HEIGHT / t.line_height;
	t.tex_pos = (t.line_start - W_HEIGHT / 2 + t.line_height / 2) * t.step;
	while (t.line_start <= t.line_end)
	{
		t.tex_y = (int) t.tex_pos & (T_HEIGHT - 1);
		rbox->buf[t.line_start][x] = \
			rbox->texture[t.tex_num][T_HEIGHT * t.tex_y + t.tex_x];
		t.tex_pos += t.step;
		rbox->re_buf = 1;
		t.line_start++;
	}
}

void	draw(t_rbox *rbox)
{
	int	x;
	int	y;

	y = 0;
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			rbox->box->addr[y * W_WIDTH + x] = rbox->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(rbox->box->mlx, \
		rbox->box->win, rbox->box->img, 0, 0);
}
