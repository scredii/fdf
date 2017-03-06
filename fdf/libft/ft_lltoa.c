/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:57:52 by abourgeu          #+#    #+#             */
/*   Updated: 2017/01/31 15:00:51 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ll_len(long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		++len;
		n *= -1;
	}
	while (n)
	{
		++len;
		n /= 10;
	}
	return (len);
}

char		*ft_lltoa(long long n)
{
	char	*s;
	int		len;

	len = ft_ll_len(n);
	s = ft_strnew(len);
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		n = -n;
		if (n < 0)
			return (ft_strdup("-9223372036854775808"));
		s[0] = '-';
	}
	while (n)
	{
		--len;
		s[len] = '0' + n % 10;
		n /= 10;
	}
	return (s);
}
