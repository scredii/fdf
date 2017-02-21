/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 19:52:40 by abourgeu          #+#    #+#             */
/*   Updated: 2016/12/13 17:55:16 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_subfree(char const *s, unsigned int st, size_t len)
{
	char *str;

	if (!s)
		return (NULL);
	if (!(str = (char*)ft_memalloc(len + 1)))
		return (NULL);
	str[len] = '\0';
	str = ft_memcpy(str, s + st, len);
	free((char*)s);
	return (str);
}
