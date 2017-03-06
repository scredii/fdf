/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:17:31 by abourgeu          #+#    #+#             */
/*   Updated: 2016/11/11 14:25:23 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int			i;
	char		*tmp;

	tmp = s1;
	i = 0;
	while (*tmp)
		tmp++;
	while (s2[i] && n > 0)
	{
		*tmp = *s2;
		tmp++;
		s2++;
		n--;
	}
	*tmp = '\0';
	return (s1);
}
