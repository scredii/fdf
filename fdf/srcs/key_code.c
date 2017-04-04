/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_code.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:21:26 by abourgeu          #+#    #+#             */
/*   Updated: 2017/03/01 23:48:26 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_get_color(t_graph *draw)
{
	if (ALT <= 0)
		draw->color = 0xFFFF00;
	if (ALT > 0)
		draw->color = 0x00FFFF;
}

void	move_map(int move, t_env *e)
{
	t_recup		*map;
	t_graph		*draw;

	map = e->map;
	draw = e->draw;
	mlx_destroy_image(MLX, IMG);
	if (move == 123)
		OFFSET_X -= 10;
	if (move == 124)
		OFFSET_X += 10;
	if (move == 125)
		OFFSET_Y += 10;
	if (move == 126)
		OFFSET_Y -= 10;
	send_coord(draw, map);
}

void	zoom(int zoom, t_env *e)
{
	t_recup		*map;
	t_graph		*draw;

	map = e->map;
	draw = e->draw;
	mlx_destroy_image(MLX, IMG);
	if (zoom == 69 || zoom == 24)
		MARGE *= 1.5;
	if (zoom == 47)
		ZH += 1;
	if (zoom == 43)
		ZH -= 1;
	if (zoom == 51)
		ZH = 1;
	if (zoom == 78 || zoom == 27)
		MARGE *= 0.6;
	send_coord(draw, map);
}

int		event(int key, t_env *e)
{
	if (key == 53)
		exit(write(1, "Program close.\n", 15));
	move_map(key, e);
	zoom(key, e);
	return (0);
}
