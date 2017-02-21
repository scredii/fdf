/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:22:25 by abourgeu          #+#    #+#             */
/*   Updated: 2016/11/13 17:41:13 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*fresh;
	size_t		i;

	if (!s)
		return (NULL);
	if (!(fresh = ft_strdup(s)))
		return (NULL);
	while (*fresh == ' ' || *fresh == '\t' || *fresh == '\n')
		fresh++;
	i = ft_strlen(fresh) - 1;
	while (fresh[i] == ' ' || fresh[i] == '\t' || fresh[i] == '\n')
		i--;
	fresh[++i] = '\0';
	return (ft_strdup(fresh));
}
