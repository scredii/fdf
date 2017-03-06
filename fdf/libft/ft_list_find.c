/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:21:09 by abourgeu          #+#    #+#             */
/*   Updated: 2016/11/16 18:36:44 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_list_find(t_list *alst, void *data, int (*cmp)())
{
	t_list *tmp;

	if (0 == alst || 0 == data || 0 == cmp)
		return (0);
	tmp = alst;
	while (tmp != 0)
	{
		if (0 == cmp(tmp->content, data))
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}
