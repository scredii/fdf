/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:01:05 by abourgeu          #+#    #+#             */
/*   Updated: 2016/11/16 12:12:14 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	a;
	int	nb;
	int	negativ;

	negativ = 0;
	nb = 0;
	a = 0;
	while (str[a] == '\t' || str[a] == '\v' || str[a] == '\r' ||
			str[a] == '\n' || str[a] == ' ' || str[a] == '\f')
		a++;
	if (str[a] == '-')
	{
		negativ = 1;
		a++;
	}
	else if (str[a] == '+')
		a++;
	a--;
	while (str[++a] >= '0' && str[a] <= '9' && str[a])
		nb = nb * 10 + (int)str[a] - '0';
	if (negativ == 1)
		nb = -nb;
	return (nb);
}
