/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:07:02 by yscheef           #+#    #+#             */
/*   Updated: 2022/12/06 21:09:13 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_lowercase(char l)
{
	if (l >= 'a' && l <= 'z')
		return (1);
	else
		return (0);
}

int	ft_toupper(int c)
{
	if (ft_is_lowercase(c))
		c -= 32;
	return (c);
}

// int	main(void)
// {
// 	char ch;

// 	ch = 'G';
// 	printf("Original: %c\n", toupper(ch));
// 	ch = 'G';
// 	printf("Mine: %c", ft_toupper(ch));
// 	return (0);
// }