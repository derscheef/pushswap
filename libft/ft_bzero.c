/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:27:05 by yscheef           #+#    #+#             */
/*   Updated: 2022/12/06 21:07:26 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = b;
	while (len > 0)
	{
		*p = c;
		p++;
		len--;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

// int	main(int argc, char const *argv[])
// {
// 	char	input[50];
// 	int		distance;

// 	distance = 5;
// 	strcpy(input, "Lorem ipsum bla bla");
// 	bzero(input, distance);
// 	printf("Original: %s\n", input);
// 	strcpy(input, "Lorem ipsum bla bla");
// 	ft_bzero(input, distance);
// 	printf("Mine: %s\n", input);
// 	return (0);
// }
