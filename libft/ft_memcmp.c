/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:03:19 by yscheef           #+#    #+#             */
/*   Updated: 2022/12/06 21:09:29 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_chr;
	unsigned char	*s2_chr;
	size_t			counter;

	s1_chr = (unsigned char *)s1;
	s2_chr = (unsigned char *)s2;
	counter = 0;
	while (counter < n)
	{
		if (s1_chr[counter] == s2_chr[counter])
			counter++;
		else
			return (s1_chr[counter] - s2_chr[counter]);
	}
	return (0);
}
