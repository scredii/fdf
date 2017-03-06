/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:12:29 by abourgeu          #+#    #+#             */
/*   Updated: 2016/11/16 18:18:25 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_listlast(t_list *alst)
{
	t_list *tmp;

	if ((void *)0 == alst)
		return (0);
	tmp = alst;
	while (tmp->next != 0)
		tmp = tmp->next;
	return (tmp);
}
