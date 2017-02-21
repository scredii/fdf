/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:57:35 by abourgeu          #+#    #+#             */
/*   Updated: 2016/12/15 13:57:35 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2, int free1, int free2)
{
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(str = ft_strnew(ft_strlen(s2) + ft_strlen(s1))))
		return (NULL);
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	if (free1)
		free((char*)s1);
	if (free2)
		free((char*)s2);
	return (str);
}
