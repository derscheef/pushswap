/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:30:15 by yscheef           #+#    #+#             */
/*   Updated: 2022/12/06 21:09:29 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str_arr;

	str_arr = (unsigned char *)b;
	while (len--)
		*str_arr++ = c;
	return (b);
}

// int	main(void)
// {
// 	char str[50] = "GeeksForGeeks is for programming geeks.";
// 	printf("\nBefore memset(): %s\n", str);

// 	ft_memset(str + 13, '.', 8 * sizeof(char));

// 	printf("After memset():  %s", str);
// 	return (0);
// }