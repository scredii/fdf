/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:46:35 by abourgeu          #+#    #+#             */
/*   Updated: 2017/02/17 15:46:38 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void       ft_stock_map(int fd, t_map *m)
{
    char    *line;
    int     i;

    i = 0;
    m->y = 0;
    while (get_next_line(fd, &line))
        m->y++;
    close(fd);
    fd = open(m->av[1], O_RDONLY);
    if (!(m->tab = (char**)malloc(sizeof(char*) * m->y + 1)))
        exit(0);
    while(get_next_line(fd, &line))
    {
        if (line[0] != '\0')
            m->tab[i++] = line;
        else
            m->y--;
    }
    close(fd);
    return ;
}

t_fmap      ***ft_get_fullmap(int fd, t_map *m)
{
    int     i;
    int     j;
    t_fmap  ***fmap;

    i = 0;
    ft_stock_map(fd, m);
    if (!(fmap = (t_fmap***)malloc(sizeof(t_fmap**) * m->y + 1)))
        return (NULL);
    while (i < m->y)
	{
		m->tmp = ft_strsplit(m->tab[i], ' ');
		m->x = 0;
		while (m->tmp[m->x] != '\0')
			m->x++;
		j = -1;
		if (!(fmap[i] = (t_fmap**)malloc(sizeof(t_fmap*) * (m->x + 1))))
			return (NULL);
		//getch(i, j, map, fmap);
		i++;
	}
	m->tmp = NULL;
	return (fmap);
}

int         main(int ac, char **av)
{
    void    *mlx;
    void    *win;
    t_map   *m = NULL;
    int     fd;

    if (ac == 2)
    {
        m = (t_map*)malloc(sizeof(t_map) * 1);
        m->av = av;
        if ((fd = open(m->av[1], O_RDONLY)) < 0)
        {
            ft_putstr("Cannot read map\n");
            exit(0);
        }
        //ft_stock_map(fd, m);
        ft_get_fullmap(fd, m);
    }
    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "mlx 42");
    mlx_loop(mlx);
}
