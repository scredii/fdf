/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:16:44 by abourgeu          #+#    #+#             */
/*   Updated: 2017/03/01 12:08:11 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		conv_tab(t_recup *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->lignes)
	{
		map->split = ft_strsplit(map->tab[i], ' ');
		if (!(map->coord[i] = (int *)malloc(sizeof(int) * map->colones)))
			exit(write(1, "Malloc failed.\n", 15));
		j = 0;
		while (j < map->colones)
		{
			map->coord[i][j] = ft_atoi(map->split[j]);
			j++;
		}
		i++;
	}
	return (0);
}

int		recup_map(t_recup *map, int fd, char *av)
{
	char	**tmp;

	fd = open(av, O_RDONLY);
	map->i = 0;
	map->count = 0;
	while (get_next_line(fd, &map->line) != 0)
	{
		if (!(tmp = ft_strsplit(map->line, ' ')))
			return (0);
		map->nb = 0;
		while (tmp[map->nb])
			map->nb++;
		if (map->nb != map->colones && map->count++ != 0)
			return (0);
		map->colones = map->nb;
		if (!(map->tab[map->i] = (char *)malloc(sizeof(char)
				* ft_strlen(map->line))))
			return (0);
		map->tab[map->i] = map->line;
		map->i++;
	}
	if (!(map->coord = (int**)malloc(sizeof(int*) * map->lignes)))
		return (0);
	conv_tab(map);
	return (1);
}

void	init(t_graph *draw, t_recup *map)
{
	t_env	e;

	MLX = mlx_init();
	WIN_X = WIDTH;
	WIN_Y = HEIGHT;
	ZH = 1;
	OFFSET_X = -35;
	OFFSET_Y = -10;
	MARGE = 4;
	WIN = mlx_new_window(MLX, WIN_X, WIN_Y, "My FDF");
	e = (t_env){
		map,
		draw
	};
	send_coord(draw, map);
	mlx_key_hook(WIN, event, &e);
	mlx_loop(MLX);
}

int		main(int ac, char **av)
{
	t_recup	map;
	t_graph	draw;
	int		fd;

	ft_bzero(&map, sizeof(t_recup));
	ft_bzero(&draw, sizeof(t_graph));
	if (ac != 2)
		exit(write(1, "Load just one map.\n", 19));
	if (!(draw.img = (t_img *)malloc(sizeof(t_img))))
		exit(write(1, "Malloc failed.\n", 15));
	if ((fd = open(av[1], O_RDONLY)) < 0)
		exit(write(1, "Cannot open map.\n", 17));
	while (get_next_line(fd, &(map.line)) != 0)
		map.lignes++;
	if (!(map.tab = (char**)malloc(sizeof(char*) * (map.lignes + 1))))
		exit(write(1, "Malloc failed.\n", 15));
	map.tab[map.lignes] = NULL;
	if (recup_map(&map, fd, av[1]) == 0)
		exit(write(1, "Load correct map.\n", 18));
	init(&draw, &map);
	return (0);
}
