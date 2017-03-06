/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:04:29 by abourgeu          #+#    #+#             */
/*   Updated: 2016/11/12 12:39:37 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	c2;
	unsigned char	*s2;
	size_t			i;

	s2 = (unsigned char *)s;
	c2 = (unsigned char)c;
	i = 0;
	while (n > 0)
	{
		if (s2[i] == c2)
			return (s2 + i);
		i++;
		n--;
	}
	return (NULL);
}
