/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:01:06 by abourgeu          #+#    #+#             */
/*   Updated: 2016/11/04 16:52:17 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = (char *)s;
	if (len == 0)
		return (s);
	while ((size_t)i < len)
	{
		tmp[i] = (unsigned char)c;
		i++;
	}
	s = tmp;
	return (s);
}
