/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:59:38 by yscheef           #+#    #+#             */
/*   Updated: 2022/12/06 22:09:35 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	final(size_t end, size_t current, void *dest, const void *src)
{
	signed char	operation;

	if (dest < src)
		operation = 1;
	else
		operation = -1;
	while (current != end)
	{
		*(((unsigned char *)dest) + current) = *(((unsigned char *)src)
				+ current);
		current += operation;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	end;
	size_t	current;

	if (dest != src)
	{
		if (dest < src)
		{
			current = 0;
			end = n;
		}
		else
		{
			current = n - 1;
			end = -1;
		}
		final(end, current, dest, src);
	}
	return (dest);
}
