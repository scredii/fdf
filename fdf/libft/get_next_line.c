/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 12:49:02 by abourgeu          #+#    #+#             */
/*   Updated: 2017/02/27 15:15:57 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "libft.h"

static	char	*get_line(char **save, int i)
{
	char			*tmp;

	tmp = ft_strsub(*save, 0, i);
	if (!(*save = ft_subfree(*save, i + 1, ft_strlen(*save) - ft_strlen(tmp))))
		return (NULL);
	return (tmp);
}

static	int		extract_line(char **save, const int fd, char **line, int ret)
{
	char			buff[BUFF_SIZE + 1];
	int				i;

	while (ret != 0)
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) < 0)
			return (-1);
		buff[ret] = '\0';
		if (!(*save = ft_strjoinfree(*save, buff, 1, 0)))
			return (-1);
		i = -1;
		while ((*save)[++i])
			if ((*save)[i] == '\n')
			{
				*line = get_line(save, i);
				return (1);
			}
	}
	if (i > 0)
	{
		*line = get_line(save, i);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static	char	*save = NULL;
	int				retour;

	if (!(save))
		if (!(save = (char*)ft_memalloc(sizeof(char) * 1)))
			return (-1);
	retour = 0;
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	if ((retour = extract_line(&save, fd, line, 1)) < 1)
		return (retour);
	return (1);
}
