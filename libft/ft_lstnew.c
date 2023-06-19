/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:58:45 by yscheef           #+#    #+#             */
/*   Updated: 2022/12/06 21:07:53 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*teemo;

	teemo = malloc(sizeof(t_list) * 1);
	if (!teemo)
		return (0);
	(*teemo).content = content;
	(*teemo).next = NULL;
	return (teemo);
}
