/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:57:51 by yscheef           #+#    #+#             */
/*   Updated: 2022/12/06 21:07:49 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*plcr;

	if (!lst)
		return ;
	while (*lst)
	{
		plcr = (**lst).next;
		ft_lstdelone(*lst, del);
		*lst = plcr;
	}
}
