/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:45:43 by abourgeu          #+#    #+#             */
/*   Updated: 2017/02/17 15:45:49 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../minilibx/mlx.h"
#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct      s_fmap
{
    int     x;
    int     y;
    int     z;
}                   t_fmap;

typedef struct      s_map
{
    char    **av;
    char    **tab;
    char    **tmp;
    int     x;
    int     y;
    int     z;
    t_fmap  ***fmap;
}                   t_map;

#endif
