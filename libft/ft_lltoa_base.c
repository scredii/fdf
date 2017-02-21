/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:55:03 by abourgeu          #+#    #+#             */
/*   Updated: 2017/01/31 14:58:51 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	conv_ex(long long nb)
{
	if (nb >= 10)
		return (nb - 10 + 'a');
	else
		return (nb + '0');
}

char				*ft_lltoa_base(long long value, int base)
{
	long long		i;
	char			*str;
	long long		tmp;

	i = 0;
	tmp = value;
	while (tmp >= base)
	{
		tmp = tmp / base;
		i++;
	}
	if (!(str = ft_strnew(i + 1)))
		return (NULL);
	str[i] = '\0';
	while (i >= 0)
	{
		tmp = value % base;
		str[i] = conv_ex(tmp);
		value /= base;
		i--;
	}
	return (str);
}
