/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:53:51 by abourgeu          #+#    #+#             */
/*   Updated: 2017/01/18 13:54:47 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_itoa_neg(long *n, long *neg)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
	}
}

char			*ft_ltoa(long n)
{
	long		len;
	long		ntmp;
	long		neg;
	char		*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ntmp = n;
	len = 2;
	neg = 0;
	ft_itoa_neg(&n, &neg);
	while (ntmp /= 10)
		len++;
	len += neg;
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}
