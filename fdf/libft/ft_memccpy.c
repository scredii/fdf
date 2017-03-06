/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:33:12 by abourgeu          #+#    #+#             */
/*   Updated: 2016/11/10 18:04:09 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*dst;
	unsigned char	*sc;
	unsigned char	to_find;

	dst = (unsigned char *)dest;
	sc = (unsigned char *)src;
	to_find = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if ((*dst++ = *sc++) == to_find)
			return (dst);
		i++;
	}
	return (NULL);
}
