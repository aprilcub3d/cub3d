/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjeon <seonjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:59:34 by seonjeon          #+#    #+#             */
/*   Updated: 2023/05/03 19:20:06 by seonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	draw_minimap_wall(t_rbox *rbox, int i, int j, int dist)
{
	int	x;
	int	y;

	y = 0;
	while (y < dist)
	{
		x = 0;
		while (x < dist)
		{
			rbox->buf[j + y][i + x] = 0xFFFFFF;
			x++;
		}
		y++;
	}
}

void	draw_minimap_pos(t_rbox *rbox, int dist)
{
	int	x;
	int	y;
	int	pos_x;
	int	pos_y;

	y = 0;
	pos_x = rbox->pos.y;
	pos_y = rbox->pos.x;
	while (y < dist)
	{
		x = 0;
		while (x < dist)
		{
			rbox->buf[pos_y * (dist + 1) + y] \
				[pos_x * (dist + 1) + x] = 0x00FF00;
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_rbox *rbox)
{
	int	dist;
	int	cnt_x;
	int	cnt_y;
	int	x;
	int	y;

	dist = 4;
	y = 0;
	cnt_y = 0;
	while (y < rbox->box->m_height)
	{
		x = 0;
		cnt_x = 0;
		while (x < rbox->box->m_width)
		{
			if (rbox->box->map[y][x])
				draw_minimap_wall(rbox, x + cnt_x, y + cnt_y, dist);
			cnt_x += dist;
			x++;
		}
		y++;
		cnt_y += dist;
	}
	draw_minimap_pos(rbox, dist);
}
