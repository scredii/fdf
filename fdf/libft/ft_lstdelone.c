/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:11:02 by abourgeu          #+#    #+#             */
/*   Updated: 2016/11/14 15:51:05 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alstm, void (*del)(void *, size_t))
{
	del((*alstm)->content, (*alstm)->content_size);
	free(*alstm);
	*alstm = NULL;
}
