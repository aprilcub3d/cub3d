/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:43:52 by seonjeon          #+#    #+#             */
/*   Updated: 2023/05/08 16:56:47 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include "cub3d.h"

# define W_WIDTH    670
# define W_HEIGHT   540
# define T_WIDTH	64
# define T_HEIGHT	64

# define ON_KEYDOWN	2
# define ON_KEYUP	3
# define ON_DESTROY	17

# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_LEFT	123
# define KEY_RIGHT	124

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_box {
	int		**map;
	int		m_width;
	int		m_height;
	void	*mlx;
	void	*win;
	void	*img;
	int		*addr;
	int		bpp;
	int		llen;
	int		endian;
	int		i_width;
	int		i_height;
}	t_box;

typedef struct s_rbox {
	t_box	*box;
	t_point	pos;
	t_point	dir;
	t_point	plane;
	t_point	ray;
	int		map_x;
	int		map_y;
	t_point	side;
	t_point	step;
	t_point	delta;
	int		buf[W_HEIGHT][W_WIDTH];
	int		**texture;
	int		re_buf;
	int		ceiling;
	int		floor;
}	t_rbox;

typedef struct s_tex {
	int		line_height;
	int		line_start;
	int		line_end;
	double	wall_x;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;
	int		tex_num;
}	t_tex;

//window.c
int		main_loop(t_rbox *rbox);
void	raycasting(t_rbox *rbox);
void	free_rbox(t_rbox *rbox);
int		make_window(t_map *cub);
//keyhook.c
int		exit_hook(t_rbox *rbox);
int		key_press(int keycode, t_rbox *rbox);

//init.c
void	init_point(t_rbox *rbox, t_map *cub);
void	init_buf(t_rbox *rbox);
int		init_texture(t_rbox *rbox, t_map *cub);
int		set_texture(t_box *box, int *texture, char *path);
int		get_color(int color[3]);

//draw.c
int		get_tex_num(t_rbox *rbox, int side);
void	draw_line(t_rbox *rbox, double dist, int x, int side);
void	draw(t_rbox *rbox);

//dda.c
void	dda_init(t_rbox *rbox);
double	dda(t_rbox *rbox, int *side);

//minimap.c
void	draw_minimap(t_rbox *rbox);

//free.c
int		free_path(t_map *cub);
int		free_texture(int **t);
#endif
