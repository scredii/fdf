/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 18:44:13 by abourgeu          #+#    #+#             */
/*   Updated: 2016/11/16 17:26:54 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_count_words(const char *str, char c)
{
	int i;
	int	words;

	words = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			words++;
		i++;
	}
	if (str[0] == '\0')
		i++;
	return (words);
}

static	char		*ft_words(const char *str, char c, int *i)
{
	char	*s1;
	int		j;

	if (!(s1 = (char *)malloc(sizeof(char *) * (ft_strlen(str)))))
		return (NULL);
	j = 0;
	while (str[*i] != c && str[*i])
	{
		s1[j] = str[*i];
		j++;
		*i += 1;
	}
	s1[j] = '\0';
	while (str[*i] == c && str[*i])
		*i += 1;
	return (s1);
}

char				**ft_strsplit(char const *str, char c)
{
	int		k;
	int		wrds;
	int		i;
	char	**s;

	i = 0;
	k = -1;
	if (str == NULL)
		return (NULL);
	wrds = ft_count_words(str, c);
	if (c == 0 || str == NULL)
		return (NULL);
	s = ((char **)malloc(sizeof(char **) * (wrds + 2)));
	if (s == NULL)
		return (NULL);
	while (str[i] == c && str[i])
		i++;
	while (++k <= wrds && str[i])
		s[k] = ft_words(str, c, &i);
	s[k] = NULL;
	return (s);
}
