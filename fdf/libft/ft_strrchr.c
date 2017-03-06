/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:57:09 by abourgeu          #+#    #+#             */
/*   Updated: 2016/11/06 16:26:25 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *tmp;

	tmp = s;
	tmp = tmp + ft_strlen(s);
	while (*tmp != (char)c && tmp != s)
		tmp--;
	if (*tmp == (char)c)
		return ((char *)tmp);
	return (NULL);
}
