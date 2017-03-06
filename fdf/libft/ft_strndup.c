/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:51:14 by abourgeu          #+#    #+#             */
/*   Updated: 2016/12/09 16:01:44 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int start, int end)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * (end - start + 1))))
		return (0);
	while (start < end)
	{
		tmp[i] = s1[start];
		start++;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
