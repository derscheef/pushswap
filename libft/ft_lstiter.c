/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:58:05 by yscheef           #+#    #+#             */
/*   Updated: 2022/12/06 21:07:50 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*plcr;

	if (lst && f)
	{
		while (lst)
		{
			f((*lst).content);
			plcr = (*lst).next;
			lst = plcr;
		}
	}
}
