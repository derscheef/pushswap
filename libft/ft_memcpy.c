/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:03:40 by yscheef           #+#    #+#             */
/*   Updated: 2022/12/06 21:09:29 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*src_char;
	char	*dest_char;

	src_char = (char *)src;
	dest_char = (char *)dest;
	i = 0;
	while (i < n)
	{
		dest_char[i] = src_char[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	const char src[50] = "http://www.tutorialspoint.com";
// 	char dest[50];
// 	strcpy(dest, "Heloooo!!");
// 	memcpy(dest, src, strlen(src) + 1);
// 	printf("Original: %s\n", dest);

// 	const char src2[50] = "http://www.tutorialspoint.com";
// 	char dest2[50];
// 	strcpy(dest2, "Heloooo!!");
// 	ft_memcpy(dest2, src2, strlen(src2) + 1);
// 	printf("Mine: %s\n", dest2);

// 	return (0);
// }