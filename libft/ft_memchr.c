/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:03:02 by yscheef           #+#    #+#             */
/*   Updated: 2022/12/06 21:11:48 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		if (*p != (unsigned char)c)
			p++;
	else
		return (p);
	return (0);
}

// int	main(void)
// {
// 	printf("Mine: %s\n", (char *)ft_memchr("bonjour", 'o', 7));
// 	printf("Original: %s\n", (char *)memchr("bonjour", 'o', 7));
// }