/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:43:52 by abourgeu          #+#    #+#             */
/*   Updated: 2016/11/16 16:54:56 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t		len2;

	if (*find == '\0')
		return ((char *)str);
	len2 = ft_strlen(find);
	while (*str != '\0' && len-- >= len2)
	{
		if (*str == *find && (ft_memcmp(str, find, len2) == 0))
			return ((char *)str);
		str++;
	}
	return (NULL);
}
