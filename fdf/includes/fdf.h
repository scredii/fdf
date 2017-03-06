/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:45:43 by abourgeu          #+#    #+#             */
/*   Updated: 2017/03/01 23:42:17 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"
# define WIDTH 1920
# define HEIGHT 1200
# define ALT draw->z1 + draw->z0
# define COORD map->coord[i][j]
# define LINE map->lignes
# define COLLUMN map->colones
# define WIN draw->img->win
# define MLX draw->img->mlx
# define IMG draw->img->image
# define DATA draw->img->data
# define SIZELINE draw->img->sizeline
# define ENDIAN draw->img->endian
# define BPP draw->img->bpp
# define WIN_X draw->win_size_x
# define WIN_Y draw->win_size_y
# define MARGE draw->marge
# define Z0 draw->z0
# define Z1 draw->z1
# define Z2 draw->z2
# define OFFSET_X draw->offset_x
# define OFFSET_Y draw->offset_y
# define X_DIR draw->x_dir
# define Y_DIR draw->y_dir
# define ZH map->zh

typedef	struct		s_recup
{
	char			**tab;
	char			**split;
	char			*line;
	int				**coord;
	int				lignes;
	int				colones;
	int				i;
	int				nb;
	int				count;
	int				zh;
}					t_recup;

typedef struct		s_img
{
	void			*mlx;
	void			*win;
	void			*image;
	int				bpp;
	int				endian;
	int				sizeline;
	char			*data;
}					t_img;

typedef struct		s_graph
{
	t_img			*img;
	int				x0;
	int				y0;
	int				z0;
	int				x1;
	int				y1;
	int				z1;
	int				xx0;
	int				yy0;
	int				xx1;
	int				yy1;
	int				xx2;
	int				yy2;
	int				z2;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
	int				tmp;
	float			marge;
	int				win_size_x;
	int				win_size_y;
	int				x_dir;
	int				y_dir;
	int				offset_x;
	int				offset_y;
	int				color;
	int				which;
}					t_graph;

typedef struct		s_env
{
	t_recup			*map;
	t_graph			*draw;
}					t_env;

int					check_arg(int ac);
int					check_open(int fd, char *file);
int					event(int key, t_env *e);
void				ft_get_color(t_graph *draw);
t_img				*img(t_graph *draw);
void				send_coord(t_graph *draw, t_recup *map);

#endif
