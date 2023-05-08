/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjeon <seonjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:59:18 by seonjeon          #+#    #+#             */
/*   Updated: 2023/05/03 15:59:42 by seonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	dda_init(t_rbox *rbox)
{
	rbox->map_x = (int) rbox->pos.x;
	rbox->map_y = (int) rbox->pos.y;
	rbox->delta.x = fabs(1 / rbox->ray.x);
	rbox->delta.y = fabs(1 / rbox->ray.y);
	if (rbox->ray.x < 0)
	{
		rbox->step.x = -1;
		rbox->side.x = (rbox->pos.x - rbox->map_x) * rbox->delta.x;
	}
	else
	{
		rbox->step.x = 1;
		rbox->side.x = (rbox->map_x + 1 - rbox->pos.x) * rbox->delta.x;
	}
	if (rbox->ray.y < 0)
	{
		rbox->step.y = -1;
		rbox->side.y = (rbox->pos.y - rbox->map_y) * rbox->delta.y;
	}
	else
	{
		rbox->step.y = 1;
		rbox->side.y = (rbox->map_y + 1 - rbox->pos.y) * rbox->delta.y;
	}
}

double	dda(t_rbox *rbox, int *side)
{
	dda_init(rbox);
	while (1)
	{
		if (rbox->side.x < rbox->side.y)
		{
			rbox->side.x += rbox->delta.x;
			rbox->map_x += rbox->step.x;
			*side = 0;
		}
		else
		{
			rbox->side.y += rbox->delta.y;
			rbox->map_y += rbox->step.y;
			*side = 1;
		}
		if (rbox->box->map[rbox->map_x][rbox->map_y] > 0)
			break ;
	}
	if (*side == 0)
		return ((rbox->map_x - rbox->pos.x + (1 - rbox->step.x) / 2) / \
			rbox->ray.x);
	return ((rbox->map_y - rbox->pos.y + (1 - rbox->step.y) / 2) / rbox->ray.y);
}
