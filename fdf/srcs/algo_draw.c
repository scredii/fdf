/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 17:22:20 by abourgeu          #+#    #+#             */
/*   Updated: 2017/03/01 23:49:27 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	pixel(t_graph *draw, int xx, int yy)
{
	int color1;

	color1 = mlx_get_color_value(MLX, draw->color);
	if (1 < xx && xx < WIN_X && 1 < yy && yy < WIN_Y)
	{
		(draw->img->data + yy * draw->img->sizeline + 4 * xx)[0] = color1 >> 16;
		(draw->img->data + yy * draw->img->sizeline + 4 * xx)[1] = color1 >> 8;
		(draw->img->data + yy * draw->img->sizeline + 4 * xx)[2] = color1;
	}
}

void	line(t_graph *draw, int xori, int yori)
{
	draw->dx = abs(X_DIR - xori);
	draw->sx = xori < X_DIR ? 1 : -1;
	draw->dy = abs(Y_DIR - yori);
	draw->sy = yori < Y_DIR ? 1 : -1;
	draw->err = (draw->dx > draw->dy ? draw->dx : -draw->dy) / 2;
	while (1)
	{
		pixel(draw, xori, yori);
		if (xori == X_DIR && yori == Y_DIR)
			break ;
		draw->e2 = draw->err;
		if (draw->e2 > -draw->dx)
		{
			draw->err -= draw->dy;
			xori += draw->sx;
		}
		if (draw->e2 < draw->dy)
		{
			draw->err += draw->dx;
			yori += draw->sy;
		}
	}
}

void	proj(t_graph *draw, float x, float y, int z)
{
	int x_tmp;
	int	y_tmp;

	x_tmp = (x * 2) + OFFSET_X;
	y_tmp = y + (WIN_Y / MARGE) / 2 + OFFSET_Y;
	if (draw->which == 0)
	{
		draw->xx0 = ((x_tmp * MARGE) + (y_tmp * MARGE * 2) - 19 * 5 * MARGE);
		draw->yy0 = ((y_tmp * MARGE) - (x_tmp * MARGE / 2) - z * 1 * MARGE / 5);
	}
	else if (draw->which == 1)
	{
		draw->xx1 = ((x_tmp * MARGE) + (y_tmp * MARGE * 2) - 19 * 5 * MARGE);
		draw->yy1 = ((y_tmp * MARGE) - (x_tmp * MARGE / 2) - z * 1 * MARGE / 5);
	}
	else if (draw->which == 2)
	{
		draw->xx2 = ((x_tmp * MARGE) + (y_tmp * MARGE * 2) - 19 * 5 * MARGE);
		draw->yy2 = ((y_tmp * MARGE) - (x_tmp * MARGE / 2) - z * 1 * MARGE / 5);
	}
}

void	set_coord(t_graph *draw, t_recup *map, int xbase, int ybase)
{
	draw->x0 = xbase * MARGE;
	draw->x1 = (xbase + 1) * MARGE;
	draw->y0 = ybase * MARGE;
	draw->y1 = (ybase + 1) * MARGE;
	draw->which = 0;
	proj(draw, draw->y0, draw->x0, Z0);
	draw->which = 1;
	proj(draw, draw->y0, draw->x1, Z2);
	draw->which = 2;
	proj(draw, draw->y1, draw->x0, Z1);
	if (xbase < LINE - 1)
	{
		ft_get_color(draw);
		X_DIR = draw->xx1;
		Y_DIR = draw->yy1;
		line(draw, draw->xx0, draw->yy0);
	}
	if (ybase < COLLUMN - 1)
	{
		ft_get_color(draw);
		X_DIR = draw->xx2;
		Y_DIR = draw->yy2;
		line(draw, draw->xx0, draw->yy0);
	}
}

void	send_coord(t_graph *draw, t_recup *map)
{
	int		i;
	int		j;

	IMG = mlx_new_image(MLX, WIN_X, WIN_Y);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZELINE, &(ENDIAN));
	i = -1;
	while (++i < LINE)
	{
		j = -1;
		while (++j < COLLUMN)
		{
			if (i < LINE)
			{
				Z0 = map->coord[i][j] * 2;
				Z1 = (j < COLLUMN) ? map->coord[i][j + 1] * 2 : COORD * 2;
				Z2 = (i + 1 < LINE) ? map->coord[i + 1][j] * 2 : COORD * 2;
				Z0 *= ZH;
				Z1 *= ZH;
				Z2 *= ZH;
				set_coord(draw, map, i, j);
			}
		}
	}
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
}
