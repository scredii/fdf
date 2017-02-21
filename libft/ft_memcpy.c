/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:47:01 by abourgeu          #+#    #+#             */
/*   Updated: 2016/12/13 15:10:14 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *tmp;

	tmp = (unsigned char*)dst;
	while (n--)
		*tmp++ = *(unsigned char*)src++;
	return (dst);
}
