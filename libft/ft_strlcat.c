/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:34:54 by abourgeu          #+#    #+#             */
/*   Updated: 2016/11/13 15:50:33 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t dstlen;
	size_t sclen;

	i = 0;
	dstlen = ft_strlen(dst);
	sclen = ft_strlen(src);
	if (size <= dstlen)
		return (sclen + size);
	while (dst[i] && i < (size - 1))
		i++;
	while (*src && i < (size - 1))
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (dstlen + sclen);
}
